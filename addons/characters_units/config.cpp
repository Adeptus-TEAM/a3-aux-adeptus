#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        authors[] = { "Bragg", "Archer" };
        url = ECSTRING(main,url);
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { QUOTE(ADDON) ,"ar_characters_backpacks", "ar_characters_helmets", "ar_characters_uniforms", "ar_characters_vests" };
        units[] = {
            QECVAR(DOUBLES(V1,P1),Unit),
            QECVAR(DOUBLES(V2,P1),Unit),
            QECVAR(DOUBLES(V1,P2),Unit),
            QECVAR(DOUBLES(V2,P2),Unit),
            QECVAR(TRIPLES(UnArmed,V1,P1),Unit),
            QECVAR(TRIPLES(UnArmed,V2,P1),Unit),
            QECVAR(TRIPLES(UnArmed,V1,P2),Unit),
            QECVAR(TRIPLES(UnArmed,V2,P2),Unit),
            QECVAR(Marine,Unit),
            QECVAR(DOUBLES(Marine,CO),Unit),
            QECVAR(DOUBLES(UnArmed,Marine),Unit),
            QECVAR(TRIPLES(UnArmed,Marine,CO),Unit),
            QECVAR(BARC,Unit),
            QECVAR(DOUBLES(Engineer,P1),Unit),
            QECVAR(DOUBLES(Engineer,P2),Unit),
            QECVAR(DOUBLES(ARF,P1),Unit),
            QECVAR(DOUBLES(ARF,P2),Unit),
            QECVAR(DOUBLES(ARF,forest),Unit),
            QECVAR(DOUBLES(ARF,desert),Unit),
            QECVAR(DOUBLES(Pilot,P1),Unit),
            QECVAR(DOUBLES(Pilot,P2),Unit),
            QECVAR(DOUBLES(SpecOps,P1),Unit),
            QECVAR(DOUBLES(SpecOps,P2),Unit),
            QECVAR(Scout,Unit),
            QECVAR(DOUBLES(AT,P1),Unit),
            QECVAR(DOUBLES(AT,P2),Unit),
            QECVAR(DOUBLES(Medic,P1),Unit),
            QECVAR(DOUBLES(Medic,P2),Unit),
            QECVAR(DOUBLES(Heavy,P1),Unit),
            QECVAR(DOUBLES(Heavy,P2),Unit),
            QECVAR(DOUBLES(Sergeant,P1),Unit),
            QECVAR(DOUBLES(Sergeant,P2),Unit),
            QECVAR(DOUBLES(Lieutenant,P1),Unit),
            QECVAR(DOUBLES(Lieutenant,P2),Unit)
        };
        weapons[] = { };
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
