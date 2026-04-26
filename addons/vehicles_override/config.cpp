#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON), "3AS_LightVics_Barc","3AS_LAAT_Cargo","3AS_Republic_Heli_Nu","3AS_ARC_170","3AS_BTLB_Bomber","3AS_Z95_base" };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};


#include "CfgVehicles.hpp"
