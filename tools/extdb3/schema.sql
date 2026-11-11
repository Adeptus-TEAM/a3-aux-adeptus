-- Base de données des profils joueurs (addon ar_database, via extDB3)
-- À exécuter une fois sur le serveur MySQL / MariaDB.

CREATE DATABASE IF NOT EXISTS adeptus CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE adeptus;

-- Résumé du joueur, indépendant de db_mode : UNE ligne par steam_id.
-- C'est la table que le site interroge par steam_id.
CREATE TABLE IF NOT EXISTS players (
    steam_id    VARCHAR(17)  NOT NULL PRIMARY KEY,
    name        VARCHAR(64)  NOT NULL DEFAULT '',
    created_at  DATETIME     NOT NULL DEFAULT CURRENT_TIMESTAMP,   -- Première connexion
    last_seen   DATETIME     NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Ce qui change selon db_mode : une ligne par joueur et par base.
-- db_mode = "Main" pour les missions normales, ou le nom de la campagne (description.ext).
CREATE TABLE IF NOT EXISTS player_data (
    db_mode     VARCHAR(32)  NOT NULL,
    steam_id    VARCHAR(17)  NOT NULL,
    loadout     MEDIUMTEXT   NULL,          -- Résultat de getUnitLoadout, au format SQF
    is_medic    TINYINT(1)   NOT NULL DEFAULT 0,
    is_engineer TINYINT(1)   NOT NULL DEFAULT 0,
    is_eod      TINYINT(1)   NOT NULL DEFAULT 0,
    updated_at  DATETIME     NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    PRIMARY KEY (db_mode, steam_id),
    KEY idx_steam_id (steam_id),
    CONSTRAINT fk_player_data_player FOREIGN KEY (steam_id) REFERENCES players (steam_id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Comptes séparés : le serveur Arma lit et écrit, le site ne fait que lire.
-- Remplacez les mots de passe et les hôtes ('%' = depuis n'importe où : restreignez à l'IP réelle).
CREATE USER IF NOT EXISTS 'arma'@'%' IDENTIFIED BY 'changer-moi';
GRANT SELECT, INSERT, UPDATE ON adeptus.players TO 'arma'@'%';
GRANT SELECT, INSERT, UPDATE ON adeptus.player_data TO 'arma'@'%';

CREATE USER IF NOT EXISTS 'site'@'%' IDENTIFIED BY 'changer-moi-aussi';
GRANT SELECT ON adeptus.players TO 'site'@'%';
GRANT SELECT ON adeptus.player_data TO 'site'@'%';
