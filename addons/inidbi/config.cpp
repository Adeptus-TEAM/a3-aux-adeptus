#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "ar_main", "ar_missions" };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
        skipWhenMissingDependencies = TRUE;
    };
};

#include "CfgEventHandlers.hpp"
