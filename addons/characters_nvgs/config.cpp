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
        units[] = { };
        weapons[] = {
            QECVAR(Base,P1_Standard_NVG),
            QECVAR(Base,P1_Commander_NVG),
            QECVAR(Base,P1_MarshalCommander_NVG),
            QECVAR(Base,P2_Standard_NVG),
            QECVAR(Base,P2_Commander_NVG),
            QECVAR(Base,P2_MarshalCommander_NVG)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"

#include "CfgEventHandlers.hpp"
