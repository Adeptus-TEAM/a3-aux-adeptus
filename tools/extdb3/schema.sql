-- Base de données des profils joueurs (addon ar_database, via extDB3)
-- À exécuter une fois sur le serveur MySQL / MariaDB.

CREATE DATABASE IF NOT EXISTS adeptus CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE adeptus;

CREATE TABLE IF NOT EXISTS players (
    steam_id    VARCHAR(17)  NOT NULL PRIMARY KEY,
    name        VARCHAR(64)  NOT NULL DEFAULT '',
    loadout     MEDIUMTEXT   NULL,          -- Résultat de getUnitLoadout, au format SQF
    is_medic    TINYINT(1)   NOT NULL DEFAULT 0,
    is_engineer TINYINT(1)   NOT NULL DEFAULT 0,
    is_eod      TINYINT(1)   NOT NULL DEFAULT 0,
    created_at  DATETIME     NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at  DATETIME     NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Comptes séparés : le serveur Arma lit et écrit, le site ne fait que lire.
-- Remplacez les mots de passe et les hôtes ('%' = depuis n'importe où : restreignez à l'IP réelle).
CREATE USER IF NOT EXISTS 'arma'@'%' IDENTIFIED BY 'changer-moi';
GRANT SELECT, INSERT, UPDATE ON adeptus.players TO 'arma'@'%';

CREATE USER IF NOT EXISTS 'site'@'%' IDENTIFIED BY 'changer-moi-aussi';
GRANT SELECT ON adeptus.players TO 'site'@'%';
