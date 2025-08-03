#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) , "A3_Data_F_Enoch_Loadorder", "OPTRE_Loadorder"};
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgWorlds.hpp"

#include "CfgMissions.hpp"

class RscButton;
class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscEdit;
class RscPicture;
class RscShortcutButton;
class RscText;
#include "rsc\checkPassword.hpp"
#include "rsc\mainMenu.hpp"
