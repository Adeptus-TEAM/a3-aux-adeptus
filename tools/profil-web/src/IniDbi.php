<?php
/**
 * Outils autour des données joueurs au format SQF :
 *  - lecture de la colonne loadout (texte SQF écrit par le serveur via extDB3) ;
 *  - lecture des anciens fichiers iniDBi2 (<SteamID64>.ini, section [GameData]) pour la migration.
 */

declare(strict_types=1);

final class IniDbi
{
    /** Un SteamID64 fait toujours 17 chiffres : aucun chemin de fichier possible. */
    public static function isValidUid(string $uid): bool
    {
        return (bool) preg_match('/^\d{17}$/', $uid);
    }

    /**
     * Découpe le fichier INI à la main : parse_ini_file() abîme les guillemets
     * et les crochets des valeurs SQF.
     *
     * @return array<string, array<string, mixed>>
     */
    public static function parseIni(string $content): array
    {
        $sections = [];
        $current = '';
        // Retire un éventuel BOM UTF-8
        $content = preg_replace('/^\xEF\xBB\xBF/', '', $content) ?? $content;

        foreach (preg_split('/\r\n|\r|\n/', $content) ?: [] as $line) {
            $line = trim($line);
            if ($line === '' || $line[0] === ';' || $line[0] === '#') {
                continue;
            }
            if (preg_match('/^\[(.+)\]$/', $line, $m)) {
                $current = trim($m[1]);
                $sections[$current] ??= [];
                continue;
            }
            $pos = strpos($line, '=');
            if ($pos === false) {
                continue;
            }
            $key = trim(substr($line, 0, $pos));
            $sections[$current][$key] = self::parseValue(trim(substr($line, $pos + 1)));
        }

        return $sections;
    }

    /** Convertit une valeur SQF en valeur PHP, en tolérant un niveau de guillemets en trop. */
    public static function parseValue(string $raw)
    {
        try {
            $value = Sqf::parse($raw);
        } catch (Throwable $e) {
            return $raw; // Valeur illisible : on la garde telle quelle
        }

        // Certaines versions d'iniDBi2 entourent toute la valeur de guillemets
        if (is_string($value)) {
            $inner = trim($value);
            if ($inner !== '' && ($inner[0] === '[' || $inner[0] === '"' || in_array(strtolower($inner), ['true', 'false'], true))) {
                try {
                    return Sqf::parse($inner);
                } catch (Throwable $e) {
                    // C'était vraiment une chaîne
                }
            }
        }

        return $value;
    }

    /**
     * Transforme le tableau de getUnitLoadout en structure lisible.
     * Format : [primaire, lanceur, poing, uniforme, gilet, sac, casque, lunettes, jumelles, items assignés]
     */
    public static function describeLoadout(array $loadout): array
    {
        $weapon = static function ($w): ?array {
            if (!is_array($w) || ($w[0] ?? '') === '') {
                return null;
            }
            $mags = [];
            foreach ([4, 5] as $i) {
                if (is_array($w[$i] ?? null) && ($w[$i][0] ?? '') !== '') {
                    $mags[] = ['class' => (string) $w[$i][0], 'ammo' => (int) ($w[$i][1] ?? 0)];
                }
            }
            return [
                'class'       => (string) $w[0],
                'attachments' => array_values(array_filter([
                    (string) ($w[1] ?? ''), (string) ($w[2] ?? ''), (string) ($w[3] ?? ''), (string) ($w[6] ?? ''),
                ])),
                'magazines'   => $mags,
            ];
        };

        $container = static function ($c) use ($weapon): ?array {
            if (!is_array($c) || ($c[0] ?? '') === '') {
                return null;
            }
            $items = [];
            foreach ((is_array($c[1] ?? null) ? $c[1] : []) as $entry) {
                if (!is_array($entry)) {
                    continue;
                }
                if (is_array($entry[0] ?? null)) { // Arme rangée dans le conteneur
                    $w = $weapon($entry[0]);
                    if ($w) {
                        $items[] = ['class' => $w['class'], 'count' => (int) ($entry[1] ?? 1)];
                    }
                } elseif (is_bool($entry[1] ?? null)) { // Sac dans le sac : [classe, true]
                    $items[] = ['class' => (string) $entry[0], 'count' => 1];
                } else { // Objet [classe, nb] ou chargeur [classe, nb, munitions]
                    $items[] = ['class' => (string) ($entry[0] ?? ''), 'count' => (int) ($entry[1] ?? 1)];
                }
            }
            return ['class' => (string) $c[0], 'items' => $items];
        };

        $str = static fn($v): ?string => is_string($v) && $v !== '' ? $v : null;

        return [
            'primary'    => $weapon($loadout[0] ?? null),
            'launcher'   => $weapon($loadout[1] ?? null),
            'handgun'    => $weapon($loadout[2] ?? null),
            'uniform'    => $container($loadout[3] ?? null),
            'vest'       => $container($loadout[4] ?? null),
            'backpack'   => $container($loadout[5] ?? null),
            'headgear'   => $str($loadout[6] ?? null),
            'goggles'    => $str($loadout[7] ?? null),
            'binocular'  => $weapon($loadout[8] ?? null),
            'assigned'   => array_values(array_filter(
                is_array($loadout[9] ?? null) ? $loadout[9] : [],
                static fn($v) => is_string($v) && $v !== ''
            )),
        ];
    }
}

/**
 * Parseur minimal des littéraux SQF : tableaux, chaînes ("..." ou '...', guillemet doublé = échappement),
 * nombres, true/false, nil.
 */
final class Sqf
{
    private string $s;
    private int $i = 0;

    private function __construct(string $s)
    {
        $this->s = $s;
    }

    /** Réécrit une valeur PHP au format de "str" en SQF (inverse de parse). */
    public static function stringify($v): string
    {
        if (is_array($v)) {
            return '[' . implode(',', array_map([self::class, 'stringify'], $v)) . ']';
        }
        if (is_bool($v)) {
            return $v ? 'true' : 'false';
        }
        if (is_int($v) || is_float($v)) {
            return (string) $v;
        }
        if ($v === null) {
            return 'nil';
        }
        return '"' . str_replace('"', '""', (string) $v) . '"';
    }

    public static function parse(string $s)
    {
        $p = new self($s);
        $value = $p->value();
        $p->ws();
        if ($p->i !== strlen($p->s)) {
            throw new UnexpectedValueException('Caractères en trop après la valeur SQF');
        }
        return $value;
    }

    private function ws(): void
    {
        while ($this->i < strlen($this->s) && ctype_space($this->s[$this->i])) {
            $this->i++;
        }
    }

    private function value()
    {
        $this->ws();
        $c = $this->s[$this->i] ?? '';
        if ($c === '[') {
            return $this->arr();
        }
        if ($c === '"' || $c === "'") {
            return $this->str($c);
        }
        if (preg_match('/\G-?\d+(\.\d+)?(e[+-]?\d+)?/i', $this->s, $m, 0, $this->i)) {
            $this->i += strlen($m[0]);
            return str_contains($m[0], '.') || stripos($m[0], 'e') !== false ? (float) $m[0] : (int) $m[0];
        }
        if (preg_match('/\G(true|false|nil|any)\b/i', $this->s, $m, 0, $this->i)) {
            $this->i += strlen($m[0]);
            $word = strtolower($m[0]);
            return $word === 'true' ? true : ($word === 'false' ? false : null);
        }
        throw new UnexpectedValueException("Valeur SQF inattendue à la position {$this->i}");
    }

    private function arr(): array
    {
        $this->i++; // [
        $out = [];
        $this->ws();
        if (($this->s[$this->i] ?? '') === ']') {
            $this->i++;
            return $out;
        }
        while (true) {
            $out[] = $this->value();
            $this->ws();
            $c = $this->s[$this->i] ?? '';
            $this->i++;
            if ($c === ']') {
                return $out;
            }
            if ($c !== ',') {
                throw new UnexpectedValueException('Tableau SQF mal formé');
            }
        }
    }

    private function str(string $q): string
    {
        $this->i++; // guillemet ouvrant
        $out = '';
        $len = strlen($this->s);
        while ($this->i < $len) {
            $c = $this->s[$this->i++];
            if ($c === $q) {
                if (($this->s[$this->i] ?? '') === $q) { // "" = guillemet échappé
                    $out .= $q;
                    $this->i++;
                    continue;
                }
                return $out;
            }
            $out .= $c;
        }
        throw new UnexpectedValueException('Chaîne SQF non fermée');
    }
}
