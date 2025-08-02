#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) , "3AS_Weapons_RPS6"};
        units[] = {};
        weapons[] = {
            QSUBCVAR(RPS6_F)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"

#include "CfgAmmo.hpp"

#include "CfgMagazines.hpp"
