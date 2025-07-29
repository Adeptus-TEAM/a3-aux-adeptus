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
        units[] = {
            // Regs
            QECVAR(V1,U),
            QECVAR(V2,U),
            QECVAR(Engineer,U),
            QECVAR(Marine,U),
            QECVAR(Marine_CO,U),
            QECVAR(ARF_desert,U),
            QECVAR(ARF_forest,U),
            QECVAR(Scout,U),
            // Customs
            QECVAR(Ankh,U),
            QECVAR(Archer,U),
            QECVAR(Code,U),
            QECVAR(Dragon,U),
            QECVAR(Gart,U),
            QECVAR(Liberty,U),
            QECVAR(Magic,U),
            QECVAR(Nek,U),
            QECVAR(Ozy,U),
            QECVAR(Phantom,U),
            QECVAR(Puce,U),
            QECVAR(Red,U),
            QECVAR(Sight,U),
            QECVAR(SixOne,U),
            QECVAR(Spearhead,U),
            QECVAR(Sting,U)
        };
        weapons[] = {
            // Regs
            QECVAR(V1,Uniform),
            QECVAR(V2,Uniform),
            QECVAR(eng,Uniform),
            QECVAR(Marine,Uniform),
            QECVAR(Marine_co,Uniform),
            QECVAR(ARF_desert,Uniform),
            QECVAR(ARF_forest,Uniform),
            QECVAR(Scout,Uniform),
            // Customs
            QECVAR(Ankh,Uniform),
            QECVAR(Archer,Uniform),
            QECVAR(Code,Uniform),
            QECVAR(Dragon,Uniform),
            QECVAR(Gart,Uniform),
            QECVAR(Liberty,Uniform),
            QECVAR(Magic,Uniform),
            QECVAR(Nek,Uniform),
            QECVAR(Ozy,Uniform),
            QECVAR(Phantom,Uniform),
            QECVAR(Puce,Uniform),
            QECVAR(Red,Uniform),
            QECVAR(Sight,Uniform),
            QECVAR(SixOne,Uniform),
            QECVAR(Spearhead,Uniform),
            QECVAR(Sting,Uniform)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
