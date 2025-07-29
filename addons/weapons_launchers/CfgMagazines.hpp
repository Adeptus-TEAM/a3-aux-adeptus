class CfgMagazines {
    class 3AS_MK40_AT;
    class SUBCVAR(RPS6_AT_Mag) : 3AS_MK40_AT {
        author = AUTHOR;
        displayName = CSTRING(RPS6_AT_Mag_DisplayName);
        descriptionShort = CSTRING(RPS6_AT_Mag_Description);
        ammo = QSUBCVAR(RPS6_AT_Ammo);
        count = 1;
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\rps6_mag_ca.paa);
        model = "\A3\weapons_f\launchers\RPG32\pg32v_rocket_item.p3d";
        nameSound = "handgrenade";
        JLTS_hasElectronics = 1;
        JLTS_hasEMPProtection = 1;
    };
};
