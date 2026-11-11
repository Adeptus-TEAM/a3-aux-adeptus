<?php
/*
 * Copiez ce fichier en config.php (ne le commitez pas : il contient des identifiants).
 */
return [
    // Adresse publique du dossier public/, sans "/" final (utilisée pour le retour de la connexion Steam)
    'base_url' => 'https://adeptus-team.eu/profil',

    // Base MySQL remplie par le serveur Arma (extDB3). Utilisez le compte en lecture seule "site"
    // créé par tools/extdb3/schema.sql.
    'db_dsn'      => 'mysql:host=127.0.0.1;port=3306;dbname=adeptus;charset=utf8mb4',
    'db_user'     => 'site',
    'db_password' => 'changer-moi-aussi',
];
