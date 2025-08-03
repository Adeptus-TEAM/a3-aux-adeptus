class CfgVehicles {
    class JLTS_Ammobox_weapons_GAR;
    class JLTS_Ammobox_support_GAR;
    class JLTS_Ammobox_grenades_GAR;
    class JLTS_Ammobox_ammo_GAR;
    class JLTS_Ammobox_launchers_GAR;

    class SUBCVAR(Ammo) : JLTS_Ammobox_ammo_GAR {
        displayName = SUBCSTRING(Ammo);
        scope = 2;
        scopeCurator = 2;
        ace_dragging_ignoreWeightCarry = TRUE;
        ace_dragging_ignoreWeight = TRUE;
        CATEGORY_AR;
        SUBCATEGORY_STORAGE;
        EDITORPREVIEW(SUBCVAR(ammo));
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        EMPTY_WEAPON;
        maximumLoad = 2000;
        class TransportMagazines {
            MAG_XX(3AS_100Rnd_EC40_mag,20);
            MAG_XX(3AS_10Rnd_EC80_Mag,20);
            MAG_XX(3AS_16Rnd_EC20_Mag,20);
            MAG_XX(3AS_200Rnd_EC40_Mag,20);
            MAG_XX(3AS_40Rnd_EC40_Mag,20);
            MAG_XX(3AS_45Rnd_EC50_Mag,20);
            MAG_XX(3AS_60Rnd_EC30_mag,20);
            MAG_XX(3AS_60Rnd_EC50_Mag,20);
        };
    };

    class SUBCVAR(AT) : JLTS_Ammobox_launchers_GAR {
        displayName = SUBCSTRING(AT);
        scope = 2;
        scopeCurator = 2;
        ace_dragging_ignoreWeightCarry = TRUE;
        ace_dragging_ignoreWeight = TRUE;
        CATEGORY_AR;
        SUBCATEGORY_STORAGE;
        EDITORPREVIEW(SUBCVAR(at));
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        maximumLoad = 2000;
        class TransportWeapons {
            WEAP_XX(AR_Weapons_Launchers_RPS6_F,1);
            WEAP_XX(3AS_RPS6_F,2);
        };
        class TransportMagazines {
            MAG_XX(AR_Weapons_Launchers_RPS6_AT_Mag,20);
        };
    };
    
    class SUBCVAR(Grenade) : JLTS_Ammobox_grenades_GAR {
        displayName = SUBCSTRING(Grenade);
        scope = 2;
        scopeCurator = 2;
        ace_dragging_ignoreWeightCarry = TRUE;
        ace_dragging_ignoreWeight = TRUE;
        CATEGORY_AR;
        SUBCATEGORY_STORAGE;
        EDITORPREVIEW(SUBCVAR(grenade));
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        EMPTY_WEAPON;
        maximumLoad = 2000;
        class TransportMagazines {
            MAG_XX(3AS_BaridumCore,40);
            MAG_XX(3AS_ThermalDetonator,40);
            MAG_XX(ACE_M84,40);
            MAG_XX(OPTRE_M2_Smoke,40);
            MAG_XX(SmokeShellBlue,40);
            MAG_XX(SmokeShellGreen,40);
            MAG_XX(SmokeShellPurple,40);
            MAG_XX(SmokeShellRed,40);
            MAG_XX(SmokeShellYellow,40);
        };
    };

    class SUBCVAR(Medical) : JLTS_Ammobox_support_GAR {
        displayName = SUBCSTRING(Medical);
        scope = 2;
        scopeCurator = 2;
        ace_dragging_ignoreWeightCarry = TRUE;
        ace_dragging_ignoreWeight = TRUE;
        CATEGORY_AR;
        SUBCATEGORY_STORAGE;
        EDITORPREVIEW(SUBCVAR(medical));
        EMPTY_BACKPACK;
        EMPTY_MAGAZINE;
        EMPTY_WEAPON;
        maximumLoad = 2000;
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,50);
            ITEM_XX(ACE_epinephrine,50);
            ITEM_XX(ACE_morphine,50);
            ITEM_XX(ACE_packingBandage,50);
            ITEM_XX(ACE_personalAidKit,5);
            ITEM_XX(ACE_quikclot,30);
            ITEM_XX(ACE_salineIV,50);
            ITEM_XX(ACE_salineIV_250,50);
            ITEM_XX(ACE_salineIV_500,50);
            ITEM_XX(ACE_splint,50);
            ITEM_XX(ACE_surgicalKit,5);
            ITEM_XX(ACE_tourniquet,50);
            ITEM_XX(ace_filedDressing,50);
            ITEM_XX(kat_X_AED,5);
            ITEM_XX(kat_bvm,5);
            ITEM_XX(kat_carbonate,20);
            ITEM_XX(kat_nytroglycerin,20);
        };
    };

    class SUBCVAR(Grenadier) : JLTS_Ammobox_grenades_GAR {
        displayName = SUBCSTRING(Grenadier);
        scope = 2;
        scopeCurator = 2;
        ace_dragging_ignoreWeightCarry = TRUE;
        ace_dragging_ignoreWeight = TRUE;
        CATEGORY_AR;
        SUBCATEGORY_STORAGE;
        EDITORPREVIEW(SUBCVAR(grenadier));
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        EMPTY_WEAPON;
        maximumLoad = 2000;
        class TransportMagazines {
            MAG_XX(3AS_1UGL_MK54_HE_shell,30);
            MAG_XX(3AS_3UGL_MK56_Flare_White_shell,30);
            MAG_XX(3AS_3UGL_MK55_Smoke_White_shell,30);
        };
    };

    class SUBCVAR(Weapons) : JLTS_Ammobox_weapons_GAR {
        displayName = SUBCSTRING(Weapons);
        scope = 2;
        scopeCurator = 2;
        ace_dragging_ignoreWeightCarry = TRUE;
        ace_dragging_ignoreWeight = TRUE;
        CATEGORY_AR;
        SUBCATEGORY_STORAGE;
        EDITORPREVIEW(SUBCVAR(weapons));
        EMPTY_MAGAZINE;
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        maximumLoad = 2000;
        class TransportWeapons {
            WEAP_XX(3AS_DC15S_F,5);
            WEAP_XX(3AS_DC15S_GL,5);
            WEAP_XX(3AS_DC15A_F,5);
            WEAP_XX(3AS_DC15A_GL,5);
            WEAP_XX(3AS_DC15L_F,5);
            WEAP_XX(3AS_DC17S_F,5);
            WEAP_XX(Shovel_Russian_Rotated,5);
            WEAP_XX(AR_Z6,5);
        };
    };
};
