#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        authors[] = { "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "ar_main" };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "Cfg3DEN.hpp"
