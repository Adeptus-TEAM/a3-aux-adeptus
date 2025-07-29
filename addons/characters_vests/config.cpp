#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) };
        units[] = { };
        weapons[] = {
            QECVAR(Base,ARC_Vest),
            QECVAR(Base,ARC_Plate_Vest),
            QECVAR(Base,ARF_Vest),
            QECVAR(Base,Assault_Vest),
            QECVAR(Base,CFR_Vest),
            QECVAR(Base,Clone_Vest),
            QECVAR(Base,Commander_Vest),
            QECVAR(Base,EngineerNCO_Vest),
            QECVAR(Base,Engineer_Vest),
            QECVAR(Base,ForceReconNCO_Vest),
            QECVAR(Base,Grenadier_Vest),
            QECVAR(Base,Hazard_Vest),
            QECVAR(Base,Heavy_Vest),
            QECVAR(Base,Kama_Vest),
            QECVAR(Base,Lieutenant_Vest),
            QECVAR(Base,Medic_Vest),
            QECVAR(Base,Officer_Vest),
            QECVAR(Base,ReconNCO_Vest),
            QECVAR(Base,Recon_Vest),
            QECVAR(Base,Specialist_Vest)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
