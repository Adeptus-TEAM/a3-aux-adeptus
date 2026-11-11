<?php
/**
 * Import unique des anciens profils iniDBi2 dans la table players (passage à extDB3), base "Main".
 *
 * 1. Copier le dossier @inidbi2/db du serveur Arma sur cette machine (par FTP).
 * 2. Lancer, avec un compte MySQL qui a le droit d'écrire (par exemple "arma") :
 *      AR_DB_PASSWORD=... php migrate-inidbi.php <dossier_db> "mysql:host=...;dbname=adeptus;charset=utf8mb4" <utilisateur>
 *
 * Un profil déjà présent dans MySQL n'est pas écrasé : relancer le script ne fait pas de dégât.
 */
declare(strict_types=1);

require __DIR__ . '/src/IniDbi.php';

if (PHP_SAPI !== 'cli') {
    exit('À lancer en ligne de commande.');
}
[, $dbDir, $dsn, $user] = $argv + [null, null, null, null];
if (!$dbDir || !$dsn || !$user) {
    fwrite(STDERR, "Usage : AR_DB_PASSWORD=... php migrate-inidbi.php <dossier_db> <dsn> <utilisateur>\n");
    exit(1);
}

$pdo = new PDO($dsn, $user, (string) getenv('AR_DB_PASSWORD'), [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]);
$isMysql = $pdo->getAttribute(PDO::ATTR_DRIVER_NAME) === 'mysql';
$ignore = $isMysql ? 'INSERT IGNORE' : 'INSERT OR IGNORE';
$insertPlayer = $pdo->prepare("$ignore INTO players (steam_id, name) VALUES (?, ?)");
$insertData = $pdo->prepare(
    "$ignore INTO player_data (db_mode, steam_id, loadout, is_medic, is_engineer, is_eod) VALUES ('Main', ?, ?, ?, ?, ?)"
);

$imported = $skipped = $errors = 0;
foreach (glob(rtrim($dbDir, '/\\') . '/*.ini') ?: [] as $file) {
    $uid = basename($file, '.ini');
    if (!IniDbi::isValidUid($uid)) {
        continue;
    }
    try {
        $data = IniDbi::parseIni((string) file_get_contents($file))['GameData'] ?? [];
        $loadout = $data['Loadout'] ?? [];
        $name = str_replace([':', '"'], '', is_scalar($data['Name'] ?? '') ? (string) ($data['Name'] ?? '') : '');

        $pdo->beginTransaction();
        $insertPlayer->execute([$uid, mb_substr($name, 0, 64)]);
        $insertData->execute([
            $uid,
            is_array($loadout) ? Sqf::stringify($loadout) : '[]',
            ($data['isMedic'] ?? false) === true ? 1 : 0,
            ($data['isEngineer'] ?? false) === true ? 1 : 0,
            ($data['isEOD'] ?? false) === true ? 1 : 0,
        ]);
        $pdo->commit();
        $insertData->rowCount() > 0 ? $imported++ : $skipped++;
    } catch (Throwable $e) {
        if ($pdo->inTransaction()) {
            $pdo->rollBack();
        }
        $errors++;
        fwrite(STDERR, "$uid : {$e->getMessage()}\n");
    }
}

echo "Importés : $imported, déjà présents : $skipped, erreurs : $errors\n";
exit($errors > 0 ? 1 : 0);
