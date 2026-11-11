<div align="center">
  <a href="https://adeptusrepublica.fr">
    <img src="https://arma3.com/assets/img/wallpapers/artofwardlc/2/thumb.jpg" alt="logoBanner" width=512px/>
  </a>
</div>

# Adeptus Auxiliaire Mod - Arma 3

> [!IMPORTANT]
> Ce projet est en cours d'ouverture à la communauté dans un esprit de partage, d'apprentissage et de collaboration. Il contient des éléments originaux développés par l’équipe Adeptus.  
> Toute inclusion ou référence à une propriété intellectuelle tierce est strictement non-commerciale et sera retirée à la demande des ayants droit.

## 📁 Structure des addons

```plaintext
a3-aux-adeptus/
├─ .adc/                      # Fichiers de configuration des interfaces
├─ .hemtt/                    # Fichiers de configuration pour Hemtt
├─ .vscode/                   # Fichiers de configuration pour Visual Studio Code
├─ addons/                    # Dossier principal des addons
│  ├─ cba_settings/             # Addon     | ar_cba_settings         | Fichier de configuration de CBA (Community Base Addons) / inA3PATH = cba_settings_userconfig\
│  ├─ characters/               # Addon     | ar_characters
│  ├─ characters_*/             # Sub-addon | ar_characters_*         | Configurations des équipements
│  ├─ characters_units/         # Sub-addon | ar_characters_units     | Configurations des unités et groupes
│  ├─ compositions/             # Addon     | ar_compositions         | Compositions 3den
│  ├─ dialogs/                  # Addon     | ar_dialogs
│  ├─ dialogs_*/                # Sub-addon | ar_dialogs_*            | Configurations de dialogues spécifiques (e.g. main menu, etc.)
│  ├─ database/                 # Addon     | ar_database             | Sauvegarde des joueurs en MySQL (extDB3)
│  ├─ main/                     # Addon     | ar_main                 | Fichiers principaux du mod
│  ├─ misc/                     # Addon     | ar_misc
│  ├─ misc_*/                   # Sub-addon | ar_misc_*               | Autres configurations
│  ├─ missions/                 # Addon     | ar_missions             | Scripts et configurations des missions
│  ├─ missions_builder/         # Sub-Addon | ar_missions_builder     | Scripts et configurations pour créer des missions
│  ├─ objects/                  # Addon     | ar_objects
│  ├─ objects_*/                # Sub-addon | ar_objects_*            | Configurations d'objet spécifiques (e.g. paths, supply crates, etc.)
│  ├─ objects_editor/           # Sub-addon | ar_objects_editor       | Configurations des objets pour l'éditeur (useful for mission makers)
│  ├─ objects_misc/             # Sub-addon | ar_objects_misc         | Configurations des objets divers (e.g. bench, etc.)
│  ├─ vehicles/                 # Addon     | ar_vehicles
│  ├─ vehicles_*/               # Sub-addon | ar_vehicles_*           | Configurations de véhicules spécifiques (e.g. bison, laat/i, etc.)
│  ├─ weapons/                  # Addon     | ar_weapons
│  ├─ weapons_*/                # Sub-addon | ar_weapons_*            | Configurations d'armes spécifiques (e.g. rifles, launchers, etc.)
│  ├─ zeus/                     # Addon     | ar_zeus
│  └─ zeus_*/                   # Sub-addon | ar_zeus_*               | Configurations de modules 3den et Zeus (e.g. laat/i drop, garage, etc.)
├─ include/                   # Fichiers nécessaires pour le mod (e.g. CBA)
├─ *.dll                      # Dll du mod pour des actions spécifiques
├─ logo_ca.paa                # Logo du mod
├─ meta.cpp                   # Fichier de métadonnées du mod
├─ mod.cpp                    # Fichier de configuration du mod
└─ README.md                  # Vous êtes ici !
```

## 💻 Coding Guidelines

Pour garantir la qualité et la cohérence du code, veuillez suivre les [coding guidelines](https://ace3.acemod.org/wiki/development/coding-guidelines) d’ACE3 lors du développement de ce mod.

- Utilisez une indentation cohérente.
- Commentez votre code de manière claire et concise.
- Respectez la structure des fichiers et des dossiers.
- Privilégiez la lisibilité et la maintenabilité du code.

## 🤝 Contributeurs

<div align="center">
  <a href="https://github.com/Admors/adeptusAuxiliaire/graphs/contributors">
    <img src="https://contrib.rocks/image?repo=Adeptus-TEAM/a3-aux-adeptus"/>
  </a>
  <br/><br/>
  <p>Nous remercions tous nos Visual Editors et Techniciens pour leur travail sur ce mod.</p>
</div>

## 📜 Licence

<a href="https://www.bohemia.net/community/licenses/arma-public-license-share-alike">
  <img src="https://files.bistudio.com/public/2d36aa7e-6a0e-4ae8-bdab-dfeb2273f731-1" alt="licence">
</a>

Le code source et les ressources **originales** de ce projet sont disponibles sous licence [APL-SA](https://www.bohemia.net/community/licenses/arma-public-license-share-alike).  
Veuillez noter que **les éléments inspirés de franchises existantes ne sont pas couverts par cette licence**.
<br/>

> [!CAUTION]
> This mod is an unofficial resource and is not affiliated with Lucasfilm Ltd, the Walt Disney Company, Electronic Arts Inc., or Twentieth Century Fox. The "Star Wars" brand and all intellectual content in this mod are based on the property of The Walt Disney Company.
>
> Star Wars © 1977 Twentieth Century Fox Film Corporation. All rights reserved. ™ & Copyright 1977 Lucasfilm Ltd. Star Wars logo and all related characters, names, and indicia are trademarks & copyright 2012 Lucasfilm Ltd. All rights reserved, or their respective trademark and copyright holders.
