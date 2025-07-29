class CfgWeapons {
    class 3AS_RPS6_Base;
    class SUBCVAR(RPS6_F) : 3AS_RPS6_Base {
        baseWeapon = QSUBCVAR(RPS6_F);
        author = AUTHOR;
        displayName = CSTRING(RPS6_DisplayName);
        descriptionShort = CSTRING(RPS6_Description);
        scope = 2;
        scopeArsenal = 2;
        magazines[] = { QSUBCVAR(RPS6_AT_Mag) };
        JLTS_hasElectronics = 1;
        JLTS_hasEMPProtection = 1;
        picture = QPATHTOF(data\rps6_ca.paa);
        class EventHandlers { };
    };
};
