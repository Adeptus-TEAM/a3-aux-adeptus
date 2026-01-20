#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = {"Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {QUOTE(ADDON), "3AS_Deka", "3AS_Equipment","JLTS_weapons_Grenades"};
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};


#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"