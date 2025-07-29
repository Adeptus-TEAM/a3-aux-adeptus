#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON), "JLTS_weapons_crates", "3as_GNK_Prop" };
        units[] = {
            QSUBCVAR(respawnBeacon_Active),
            QSUBCVAR(respawnBeacon_GroundItem),
            QSUBCVAR(arsenalBox),
            QSUBCVAR(unitTraitTerminal),
            QSUBCVAR(garageTerminal)
        };
        weapons[] = {
            QSUBCVAR(respawnBeacon_item)
        };
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
