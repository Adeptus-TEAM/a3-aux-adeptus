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
            // Regs
            QECVAR(Base,HeavyMedic_Backpack),
            QECVAR(Base,Medic_Backpack),
            QECVAR(Base,Heavy_Backpack),
            QECVAR(Base,Medium_Backpack),
            QECVAR(Base,Standard_Backpack),
            QECVAR(Base,Invisible_Backpack),
            QECVAR(EOD,Heavy_Backpack),
            QECVAR(Base,Rocket_Backpack),
            QECVAR(Base,MediumRadio_Backpack),
            QECVAR(Base,Radio_Backpack)

            // Customs

        };
        weapons[] = { };
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
