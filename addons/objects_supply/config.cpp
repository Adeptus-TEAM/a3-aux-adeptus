#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON), "ace_dragging", "JLTS_weapons_crates" };
        units[] = {
            QSUBCVAR(Ammo),
            QSUBCVAR(AT),
            QSUBCVAR(AA),
            QSUBCVAR(Grenade),
            QSUBCVAR(Medical),
            QSUBCVAR(Grenadier),
            QSUBCVAR(Weapons),
            QSUBCVAR(Empty),
            QSUBCVAR(Engineer)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
