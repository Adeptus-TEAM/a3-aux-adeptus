#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        authors[] = { "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ar_characters",
            "ar_characters_backpacks",
            "ar_characters_helmets",
            "ar_characters_nvgs",
            "ar_characters_uniforms",
            "ar_characters_units",
            "ar_characters_vests",
            "ar_compositions",
            "ar_dialogs",
            "ar_dialogs_garage",
            "ar_dialogs_loadout",
            "ar_dialogs_mainmenu",
            "ar_main",
            "ar_misc",
            "ar_misc_medicalbot",
            "ar_missions",
            "ar_missions_builder",
            "ar_objects",
            "ar_objects_editor",
            "ar_objects_misc",
            "ar_objects_paths",
            "ar_objects_supply",
            "ar_vehicles",
            "ar_vehicles_atte",
            "ar_vehicles_bison",
            "ar_vehicles_hunter",
            "ar_vehicles_laat_i",
            "ar_vehicles_pandur",
            "ar_weapons",
            "ar_weapons_launchers",
            "ar_weapons_rifles",
            "ar_zeus",
            "ar_zeus_laatairdrop"
        };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
