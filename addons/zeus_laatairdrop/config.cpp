#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Admors", "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON), "ar_dialogs" , "A3_Modules_F" };
        units[] = {
            QCVAR(ModuleLaatAirDrop)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "CfgVehicles.hpp"

class RscButton;
class RscCombo;
class RscFrame;
class RscListBox;
class RscSlider;
class RscText;
#include "rsc\LaatAirDrop.hpp"
