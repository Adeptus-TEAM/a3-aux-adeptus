#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = {"Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {QUOTE(ADDON), "3AS_Deka", "3AS_Equipment","JLTS_weapons_Grenades","ls_characters_droid","WBK_Droids_3AS","WBK_Droids_LS","JLTS_characters_DroidArmor","3AS_Characters_Droids_TSeries"};
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};


#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"