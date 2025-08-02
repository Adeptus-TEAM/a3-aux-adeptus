#include "script_component.hpp"

class CfgPatches {
    class cba_settings_userconfig {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "ar_main", "cba_settings" };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};
