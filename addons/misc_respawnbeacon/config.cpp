#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = {"Bragg", "Archer"};
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {QUOTE(ADDON), "JLTS_C_Credits", "ls_props"};
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "CfgVehicles.hpp"

#include "CfgWeapons.hpp"
