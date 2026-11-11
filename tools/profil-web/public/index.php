<?php
declare(strict_types=1);
require __DIR__ . '/../src/bootstrap.php';

startSession();
header('Cache-Control: no-store');

$uid = $_SESSION['steam_id'] ?? null;
$player = null;
$error = null;
$modes = [];
$mode = 'Main';

if ($uid !== null) {
    try {
        // Toujours le SteamID de la session, jamais un paramètre d'URL.
        // Seule la base (Main ou une campagne) se choisit dans l'URL, parmi celles du joueur.
        $modes = fetchPlayerModes($config, $uid);
        $requested = (string) ($_GET['mode'] ?? '');
        $mode = in_array($requested, $modes, true) ? $requested : ($modes[0] ?? 'Main');
        $player = $modes ? fetchPlayer($config, $uid, $mode) : null;
    } catch (Throwable $ex) {
        error_log('[profil-web] ' . $ex->getMessage());
        $error = 'Impossible de lire les données du serveur pour le moment.';
    }
}

/** Affiche une arme (classe, accessoires, chargeurs). */
function renderWeapon(string $label, ?array $w): void
{
    if (!$w) {
        return;
    }
    echo '<div class="slot"><span class="label">' . e($label) . '</span><code>' . e($w['class']) . '</code>';
    $extras = array_merge($w['attachments'], array_map(
        static fn($mag) => $mag['class'] . ' (' . $mag['ammo'] . ')',
        $w['magazines']
    ));
    if ($extras) {
        echo '<ul class="sub">';
        foreach ($extras as $x) {
            echo '<li><code>' . e($x) . '</code></li>';
        }
        echo '</ul>';
    }
    echo '</div>';
}

/** Affiche un conteneur (uniforme, gilet, sac) et son contenu. */
function renderContainer(string $label, ?array $c): void
{
    if (!$c) {
        return;
    }
    echo '<div class="slot"><span class="label">' . e($label) . '</span><code>' . e($c['class']) . '</code>';
    if ($c['items']) {
        echo '<ul class="sub">';
        foreach ($c['items'] as $item) {
            echo '<li><code>' . e($item['class']) . '</code> <span class="count">×' . (int) $item['count'] . '</span></li>';
        }
        echo '</ul>';
    }
    echo '</div>';
}
?>
<!doctype html>
<html lang="fr">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Mon profil – 61st Adeptus</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<main>
    <header>
        <h1>Profil du soldat</h1>
        <?php if ($uid !== null): ?>
            <a class="button secondary" href="logout.php">Se déconnecter</a>
        <?php endif; ?>
    </header>

    <?php if ($uid === null): ?>
        <section class="card center">
            <p>Connectez-vous avec Steam pour voir l'équipement et les spécialités sauvegardés sur le serveur.</p>
            <a class="button" href="login.php">Se connecter avec Steam</a>
        </section>

    <?php elseif ($error !== null): ?>
        <section class="card error"><?= e($error) ?></section>

    <?php elseif ($player === null): ?>
        <section class="card center">
            <p>Aucun profil trouvé pour ce compte Steam (<code><?= e($uid) ?></code>).</p>
            <p class="muted">Le profil est créé à votre première connexion sur le serveur.</p>
        </section>

    <?php else: ?>
        <?php if (count($modes) > 1): ?>
            <nav class="tabs" aria-label="Base de données">
                <?php foreach ($modes as $m): ?>
                    <a href="?mode=<?= e(rawurlencode($m)) ?>" class="<?= $m === $mode ? 'active' : '' ?>"
                       <?= $m === $mode ? 'aria-current="page"' : '' ?>><?= e($m === 'Main' ? 'Principal' : $m) ?></a>
                <?php endforeach; ?>
            </nav>
        <?php endif; ?>

        <section class="card">
            <h2><?= e($player['name'] ?: 'Soldat inconnu') ?></h2>
            <p class="muted">SteamID64 <code><?= e($player['steamId']) ?></code>
                · Dernière sauvegarde : <?= e(date('d/m/Y H:i', strtotime($player['savedAt']))) ?></p>
            <div class="traits">
                <?php foreach (['isMedic' => 'Médecin', 'isEngineer' => 'Génie', 'isEOD' => 'Démineur (EOD)'] as $key => $label): ?>
                    <span class="trait <?= $player[$key] ? 'on' : 'off' ?>"><?= e($label) ?></span>
                <?php endforeach; ?>
            </div>
        </section>

        <?php $l = $player['loadout']; ?>
        <section class="card">
            <h2>Armement</h2>
            <?php
            renderWeapon('Arme principale', $l['primary']);
            renderWeapon('Lanceur', $l['launcher']);
            renderWeapon('Arme de poing', $l['handgun']);
            renderWeapon('Jumelles', $l['binocular']);
            if (!$l['primary'] && !$l['launcher'] && !$l['handgun']) {
                echo '<p class="muted">Aucune arme.</p>';
            }
            ?>
        </section>

        <section class="card">
            <h2>Tenue</h2>
            <?php
            if ($l['headgear']) {
                echo '<div class="slot"><span class="label">Casque</span><code>' . e($l['headgear']) . '</code></div>';
            }
            if ($l['goggles']) {
                echo '<div class="slot"><span class="label">Lunettes / visage</span><code>' . e($l['goggles']) . '</code></div>';
            }
            renderContainer('Uniforme', $l['uniform']);
            renderContainer('Gilet', $l['vest']);
            renderContainer('Sac', $l['backpack']);
            if ($l['assigned']) {
                echo '<div class="slot"><span class="label">Objets assignés</span><ul class="sub">';
                foreach ($l['assigned'] as $item) {
                    echo '<li><code>' . e($item) . '</code></li>';
                }
                echo '</ul></div>';
            }
            ?>
        </section>
    <?php endif; ?>
</main>
</body>
</html>
