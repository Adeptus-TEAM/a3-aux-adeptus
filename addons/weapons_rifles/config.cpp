#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON), "JLTS_weapons_Z6" };
        units[] = {};
        weapons[] = {
            QSUBCVAR(z6)
        };
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "CfgWeapons.hpp"
