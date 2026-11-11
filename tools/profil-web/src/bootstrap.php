<?php
declare(strict_types=1);

require __DIR__ . '/IniDbi.php';
require __DIR__ . '/SteamAuth.php';

$configFile = __DIR__ . '/../config.php';
if (!is_file($configFile)) {
    http_response_code(500);
    exit('config.php manquant : copiez config.example.php en config.php et remplissez-le.');
}
/** @var array<string, mixed> $config */
$config = require $configFile;

/** Connexion MySQL (compte en lecture seule conseillé). */
function db(array $config): PDO
{
    static $pdo = null;
    return $pdo ??= new PDO((string) $config['db_dsn'], (string) $config['db_user'], (string) $config['db_password'], [
        PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        PDO::ATTR_TIMEOUT            => 5,
    ]);
}

/**
 * Récupère le profil d'un joueur dans la table players (écrite par le serveur Arma via extDB3).
 * Retourne null si le joueur n'a pas encore de profil.
 */
function fetchPlayer(array $config, string $uid): ?array
{
    if (!IniDbi::isValidUid($uid)) {
        throw new InvalidArgumentException('SteamID64 invalide');
    }

    $stmt = db($config)->prepare(
        'SELECT steam_id, name, loadout, is_medic, is_engineer, is_eod, updated_at FROM players WHERE steam_id = ?'
    );
    $stmt->execute([$uid]);
    $row = $stmt->fetch();
    if (!$row) {
        return null;
    }

    $loadout = IniDbi::parseValue((string) ($row['loadout'] ?? '[]'));

    return [
        'steamId'    => (string) $row['steam_id'],
        'name'       => (string) $row['name'],
        'isMedic'    => (bool) $row['is_medic'],
        'isEngineer' => (bool) $row['is_engineer'],
        'isEOD'      => (bool) $row['is_eod'],
        'loadout'    => IniDbi::describeLoadout(is_array($loadout) ? $loadout : []),
        'savedAt'    => date(DATE_ATOM, (int) strtotime((string) $row['updated_at'])),
    ];
}

function startSession(): void
{
    session_name('ar_profile');
    session_set_cookie_params([
        'httponly' => true,
        'secure'   => !empty($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off',
        'samesite' => 'Lax',
    ]);
    session_start();
}

/** URL absolue d'un fichier de ce dossier (sert de return_to pour Steam). */
function selfUrl(array $config, string $file): string
{
    return rtrim((string) $config['base_url'], '/') . '/' . $file;
}

function e(?string $s): string
{
    return htmlspecialchars((string) $s, ENT_QUOTES | ENT_SUBSTITUTE, 'UTF-8');
}
