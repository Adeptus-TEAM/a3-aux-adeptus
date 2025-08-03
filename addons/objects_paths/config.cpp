#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) };
        units[] = {
            // Blue
            QSUBCVAR2(line,blue),
            QSUBCVAR2(turn,blue),
            QSUBCVAR2(arrow,blue),
            QSUBCVAR2(barracks,blue),
            QSUBCVAR2(bridge,blue),
            QSUBCVAR2(infirmary,blue),

            // Red
            QSUBCVAR2(line,red),
            QSUBCVAR2(turn,red),
            QSUBCVAR2(arrow,red),
            QSUBCVAR2(armory,red),
            QSUBCVAR2(briefing,red),

            // Yellow
            QSUBCVAR2(line,yellow),
            QSUBCVAR2(turn,yellow),
            QSUBCVAR2(arrow,yellow),
            QSUBCVAR2(hangar_1,yellow),
            QSUBCVAR2(hangar_2,yellow),
            QSUBCVAR2(main_hangar,yellow)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
