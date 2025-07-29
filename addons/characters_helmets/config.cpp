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
            QECVAR(Base,barc_Headgear),
            QECVAR(Base,engineer_P1_Headgear),
            QECVAR(Base,engineer_P2_Headgear),
            QECVAR(Base,ARF_P1_Headgear),
            QECVAR(Desert,ARF_P1_Headgear),
            QECVAR(Forest,ARF_P1_Headgear),
            QECVAR(Base,ARF_P2_Headgear),
            QECVAR(Base,pilot_P1_Headgear),
            QECVAR(Base,pilot_P2_Headgear),
            QECVAR(Base,scout_Headgear),
            QECVAR(V1,P1_Headgear),
            QECVAR(V2,P1_Headgear),
            QECVAR(V1,P2_Headgear),
            QECVAR(V2,P2_Headgear),
            QECVAR(Base,Marine_Headgear),
            QECVAR(CO,Marine_Headgear),
            QECVAR(Base,specop_P1_Headgear),
            QECVAR(Base,specop_P2_Headgear),
            QECVAR(Base,arc_Headgear),

            // Customs
            QECVAR(Ankh,P1_Headgear),
            QECVAR(Ankh,P2_Headgear),
            QECVAR(Archer,P1_Headgear),
            QECVAR(Archer,P2_Headgear),
            QECVAR(Code,Scout_Headgear),
            QECVAR(Dragon,P1_Headgear),
            QECVAR(Dragon,P2_Headgear),
            QECVAR(Gart,P1_Headgear),
            QECVAR(Gart,P2_Headgear),
            QECVAR(Liberty,engineer_P1_Headgear),
            QECVAR(Liberty,engineer_P2_Headgear),
            QECVAR(Magic,P1_Headgear),
            QECVAR(Magic,P2_Headgear),
            QECVAR(Nek,engineer_P2_Headgear),
            QECVAR(Nek,pilot_P2_Headgear),
            QECVAR(Ozy,P2_Headgear),
            QECVAR(Ozy,scout_Headgear),
            QECVAR(Phantom,P1_Headgear),
            QECVAR(Phantom,P2_Headgear),
            QECVAR(Puce,barc_Headgear),
            QECVAR(Puce,P1_Headgear),
            QECVAR(Red,P1_Headgear),
            QECVAR(Red,rex_Headgear),
            QECVAR(Sight,pilot_P1_Headgear),
            QECVAR(Sight,pilot_P2_Headgear),
            QECVAR(SixOne,P1_Headgear),
            QECVAR(SixOne,P2_Headgear),
            QECVAR(Spearhead,P1_Headgear),
            QECVAR(Spearhead,P2_Headgear),
            QECVAR(Sting,scout_Headgear)
        };
        weapons[] = {
            // Regs
            QECVAR(Base,barc_helmet),
            QECVAR(Base,engineer_P1_helmet),
            QECVAR(Base,engineer_P2_helmet),
            QECVAR(Base,ARF_P1_helmet),
            QECVAR(Desert,ARF_P1_helmet),
            QECVAR(Forest,ARF_P1_helmet),
            QECVAR(Base,ARF_P2_helmet),
            QECVAR(Base,pilot_P1_helmet),
            QECVAR(Base,pilot_P2_helmet),
            QECVAR(Base,scout_helmet),
            QECVAR(V1,P1_helmet),
            QECVAR(V2,P1_helmet),
            QECVAR(V1,P2_helmet),
            QECVAR(V2,P2_helmet),
            QECVAR(Base,Marine_helmet),
            QECVAR(CO,Marine_helmet),
            QECVAR(Base,specop_P1_helmet),
            QECVAR(Base,specop_P2_helmet),
            QECVAR(Base,arc_helmet),

            // Customs
            QECVAR(Ankh,P1_helmet),
            QECVAR(Ankh,P2_helmet),
            QECVAR(Archer,P1_helmet),
            QECVAR(Archer,P2_helmet),
            QECVAR(Code,scout_helmet),
            QECVAR(Dragon,P1_helmet),
            QECVAR(Dragon,P2_helmet),
            QECVAR(Gart,P1_helmet),
            QECVAR(Gart,P2_helmet),
            QECVAR(Liberty,engineer_P1_helmet),
            QECVAR(Liberty,engineer_P2_helmet),
            QECVAR(Magic,P1_helmet),
            QECVAR(Magic,P2_helmet),
            QECVAR(Nek,engineer_P2_helmet),
            QECVAR(Nek,pilot_P2_helmet),
            QECVAR(Ozy,P2_helmet),
            QECVAR(Ozy,scout_helmet),
            QECVAR(Phantom,P1_helmet),
            QECVAR(Phantom,P2_helmet),
            QECVAR(Puce,barc_helmet),
            QECVAR(Puce,P1_helmet),
            QECVAR(Red,P1_helmet),
            QECVAR(Red,rex_helmet),
            QECVAR(Sight,pilot_P1_helmet),
            QECVAR(Sight,pilot_P2_helmet),
            QECVAR(SixOne,P1_helmet),
            QECVAR(SixOne,P2_helmet),
            QECVAR(Spearhead,P1_helmet),
            QECVAR(Spearhead,P2_helmet),
            QECVAR(Sting,scout_helmet)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
