# Base MySQL des joueurs (extDB3)

L'addon `ar_database` sauvegarde l'équipement et les spécialités de chaque joueur dans MySQL, via l'extension extDB3. Il remplace iniDBi2.

## Quand les données sont sauvegardées

Uniquement sur le serveur dédié, une fois le profil du joueur chargé :
- quelques secondes après un changement d'équipement (arsenal, menu de chargement, objet ramassé…) ;
- quand une spécialité change (terminal des spécialités, menu de chargement) ;
- à la déconnexion ;
- toutes les 5 minutes, en secours.

Les requêtes sont asynchrones : le serveur n'attend jamais MySQL.

## Installation sur le serveur Arma

1. **MySQL ou MariaDB** : exécuter [schema.sql](schema.sql) après avoir changé les mots de passe. Il crée la table `players` et deux comptes : `arma` (lecture et écriture, pour le serveur) et `site` (lecture seule, pour la page web). Restreignez l'hôte `'%'` à l'IP réelle de chaque machine.
2. **extDB3** : installer le mod `@extDB3` sur le serveur, en mod serveur uniquement (`-serverMod=@extDB3`). Il nécessite le redistribuable Visual C++ x64 sur Windows.
3. Copier [extdb3-conf.example.ini](extdb3-conf.example.ini) en `@extDB3/extdb3-conf.ini` et remplir la section `[adeptus]` avec le compte `arma`.
4. Copier [sql_custom/adeptus.ini](sql_custom/adeptus.ini) dans `@extDB3/sql_custom/`.
5. Retirer `@inidbi2` du serveur, une fois la migration faite.

Au démarrage, le RPT du serveur doit afficher `[DATABASE] extDB3 connected.`. Sinon, il indique l'étape qui a échoué : extension absente, connexion MySQL, ou fichier `adeptus.ini`.

Les noms `adeptus` (section de la config) et `adeptus.ini` sont définis dans [addons/database/script_component.hpp](../../addons/database/script_component.hpp).

## Reprendre les anciens profils iniDBi2

1. Récupérer le dossier `@inidbi2/db` du serveur.
2. Lancer [migrate-inidbi.php](../profil-web/migrate-inidbi.php) avec le compte `arma` :

```bash
AR_DB_PASSWORD=changer-moi php tools/profil-web/migrate-inidbi.php ./db "mysql:host=IP_MYSQL;dbname=adeptus;charset=utf8mb4" arma
```

Un profil déjà présent dans MySQL n'est pas écrasé, donc le script peut être relancé sans risque.

## Limites connues

- Le caractère `:` sert de séparateur à extDB3 : il est retiré des noms de joueurs, ainsi que `"`.
- Le loadout est stocké tel que le renvoie `getUnitLoadout`, en texte SQF.
