#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = CSTRING(url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "cba_main" };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgMods.hpp"
#include "CfgCategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgMarkers.hpp"
