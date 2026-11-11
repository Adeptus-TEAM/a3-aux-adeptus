<?php
declare(strict_types=1);
require __DIR__ . '/../src/bootstrap.php';

startSession();
$returnTo = selfUrl($config, 'login.php');

// Retour de Steam : on vérifie et on ouvre la session
if (isset($_GET['openid_mode'])) {
    $uid = SteamAuth::validate($_GET, $returnTo);
    if ($uid === null) {
        http_response_code(403);
        exit('Connexion Steam refusée ou expirée. <a href="login.php">Réessayer</a>');
    }
    session_regenerate_id(true);
    $_SESSION['steam_id'] = $uid;
    header('Location: index.php');
    exit;
}

// Sinon : envoi vers la page de connexion Steam
header('Location: ' . SteamAuth::loginUrl($returnTo));
exit;
