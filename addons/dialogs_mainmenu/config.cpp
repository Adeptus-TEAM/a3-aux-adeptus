#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) , "cba_main", "A3_Data_F_Enoch_Loadorder", "OPTRE_Loadorder", "ls_compat_tas_terrains"};
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "CfgWorlds.hpp"

#include "CfgMissions.hpp"

// Links of the main menu: Arma only accepts URLs from whitelisted addresses (empty url otherwise)
class CfgCommands {
    allowedHTMLLoadURIs[] += {
        "https://adeptus-team.eu*",
        "https://wiki.adeptus-team.eu*",
        "https://discord.com/invite/*",
        "ts3server://ts3.adeptus-team.eu*",
        "https://bragg-server.fr*"
    };
};

class RscButton;
class RscHTML;
class RscCheckBox;
class RscEdit;
class RscPicture;
class RscStructuredText;
class RscText;
#include "rsc\checkPassword.hpp"
#include "rsc\mainMenu.hpp"
