# Profil joueur web

Page PHP qui affiche à chaque joueur **son propre** profil, tel que le serveur Arma l'a enregistré dans MySQL (voir [tools/extdb3](../extdb3/README.md)) : équipement, spécialités (médecin, génie, démineur) et date de la dernière sauvegarde.

- Connexion avec Steam (OpenID) : pas de mot de passe ni de clé API Steam à gérer.
- Lecture seule, avec le compte MySQL `site` qui n'a que le droit `SELECT`.
- Un joueur ne peut voir que le profil lié à son compte Steam. Le SteamID vient de la session, jamais de l'URL.
- Les données sont à jour quelques secondes après chaque changement en jeu.
- Si le joueur a aussi un profil de campagne (`db_mode`), un onglet par campagne apparaît à côté de « Principal ».

## Contenu

```plaintext
tools/profil-web/
├─ config.example.php   # À copier en config.php (non versionné)
├─ migrate-inidbi.php   # Import unique des anciens fichiers iniDBi2 dans MySQL
├─ src/                 # Lecture MySQL + parseur SQF, connexion Steam
└─ public/              # Racine web : index.php (profil), login.php, logout.php, style.css
```

Seul `public/` doit être exposé sur le web. `src/`, `config.php` et `migrate-inidbi.php` doivent rester en dehors de la racine web.

## Installation

Prérequis : PHP 8.1 ou plus récent avec `pdo_mysql` (et cURL recommandé), en HTTPS.

1. Copier `config.example.php` en `config.php` et le remplir :
   - `base_url` : adresse publique du dossier `public/`, par exemple `https://adeptus-team.eu/profil`. Elle sert au retour après la connexion Steam.
   - `db_dsn`, `db_user`, `db_password` : accès MySQL avec le compte `site`.
2. Le serveur MySQL doit accepter les connexions venant de l'hébergement du site.

## Intégration au site existant

`public/index.php` est une page autonome. Pour afficher les données dans une page existante du site :

```php
require '/chemin/vers/profil-web/src/bootstrap.php';
startSession();
$modes  = fetchPlayerModes($config, $_SESSION['steam_id']);          // ['Main', 'Operation-Umbara', ...]
$player = fetchPlayer($config, $_SESSION['steam_id'], 'Main');      // tableau, ou null si pas de profil
```

Si le site a déjà une connexion Steam, mettez le SteamID64 du joueur dans `$_SESSION['steam_id']` au lieu de passer par `login.php`.

`$player` contient :

```php
[
  'steamId' => '7656119...', 'name' => 'Bragg',
  'isMedic' => true, 'isEngineer' => false, 'isEOD' => false,
  'loadout' => [
    'primary'  => ['class' => '...', 'attachments' => ['...'], 'magazines' => [['class' => '...', 'ammo' => 60]]],
    'launcher' => null, 'handgun' => [...], 'binocular' => null,
    'uniform'  => ['class' => '...', 'items' => [['class' => '...', 'count' => 10]]],
    'vest' => [...], 'backpack' => [...],
    'headgear' => '...', 'goggles' => null,
    'assigned' => ['ItemMap', 'ItemCompass', '...'],
  ],
  'savedAt' => '2026-11-11T10:54:00+01:00',
]
```

Les objets sont affichés par nom de classe, car le site n'a pas accès aux configs Arma pour connaître les noms affichés en jeu.

Avec MySQL, on peut aussi faire d'autres pages directement en SQL, par exemple la liste des médecins : `SELECT name FROM players WHERE is_medic = 1`.
