class cfgVehicles {
    // Imported classes
    class lsd_gar_phase2_Base;
    class lsd_gar_phase2Insulated_Base;

    /* Regs */

        // Phase 1 Basic Troopers
            // Armed
                class ECVAR(DOUBLES(V1,P1),Unit) : lsd_gar_phase2_Base {
                    author = AUTHOR;
                    displayName = SUBCSTRING(TRIPLES(V1,P1,Unit));
                    scope = 2;
                    scopeCurator = 2;
                    FACTION_AR_BLUFOR;
                    SUBCATEGORY_AR_P1;
                    EDITORPREVIEW(ECVAR(DOUBLES(V1,P1),Unit));
                    uniformClass = "AR_V1_Uniform";
                    backpack = "";
                    weapons[] = WEAPON_DEFAULT;
                    respawnWeapons[] = WEAPON_DEFAULT;
                    magazines[] = {MAGAZINE_DEFAULT};
                    respawnMagazines[] = {MAGAZINE_DEFAULT};
                    items[] = {ITEM_DEFAULT};
                    respawnItems[] = {ITEM_DEFAULT};
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Clone_Vest"};
                };

                class ECVAR(DOUBLES(V2,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(V2,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(V2,P1),Unit));
                    uniformClass = "AR_V2_Uniform";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V2_P1_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V2_P1_Helmet", "AR_Base_Clone_Vest"};
                };

            // UnArmed
                class ECVAR(TRIPLES(UnArmed,V1,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(DOUBLES(TRIPLES(UnArmed,V1,P1),Unit));
                    EDITORPREVIEW(ECVAR(TRIPLES(UnArmed,V1,P1),Unit));
                    SUBCATEGORY_AR_UNARMED;
                    weapons[] = {};
                    respawnWeapons[] = {};
                };

                class ECVAR(TRIPLES(UnArmed,V2,P1),Unit) : ECVAR(DOUBLES(V2,P1),Unit) {
                    displayName = SUBCSTRING(DOUBLES(TRIPLES(UnArmed,V2,P1),Unit));
                    EDITORPREVIEW(ECVAR(TRIPLES(UnArmed,V2,P1),Unit));
                    SUBCATEGORY_AR_UNARMED;
                    weapons[] = {};
                    respawnWeapons[] = {};
                };

        // Phase 2 Basic Troopers
            // Armed
                class ECVAR(DOUBLES(V1,P2),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(V1,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(V1,P2),Unit));
                    SUBCATEGORY_AR_P2;
                    uniformClass = "AR_V1_Uniform";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Clone_Vest"};
                };

                class ECVAR(DOUBLES(V2,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(V2,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(V2,P2),Unit));
                    uniformClass = "AR_V2_Uniform";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V2_P2_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V2_P2_Helmet", "AR_Base_Clone_Vest"};
                };
            
            // UnArmed
                class ECVAR(TRIPLES(UnArmed,V1,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(DOUBLES(TRIPLES(UnArmed,V1,P2),Unit));
                    EDITORPREVIEW(ECVAR(TRIPLES(UnArmed,V1,P2),Unit));
                    SUBCATEGORY_AR_UNARMED;
                    weapons[] = {};
                    respawnWeapons[] = {};
                };

                class ECVAR(TRIPLES(UnArmed,V2,P2),Unit) : ECVAR(DOUBLES(V2,P2),Unit) {
                    displayName = SUBCSTRING(DOUBLES(TRIPLES(UnArmed,V2,P2),Unit));
                    EDITORPREVIEW(ECVAR(TRIPLES(UnArmed,V2,P2),Unit));
                    SUBCATEGORY_AR_UNARMED;
                    weapons[] = {};
                    respawnWeapons[] = {};
                };

        // Marine
            // Armed
                class ECVAR(Marine,Unit) : lsd_gar_phase2Insulated_Base {
                    author = AUTHOR;
                    displayName = SUBCSTRING(DOUBLES(Marine,Unit));
                    scope = 2;
                    scopeCurator = 2;
                    FACTION_AR_BLUFOR;
                    SUBCATEGORY_AR_MARINE;
                    EDITORPREVIEW(ECVAR(Marine,Unit));
                    uniformClass = "ar_Marine_uniform";
                    backpack = "";
                    weapons[] = WEAPON_DEFAULT;
                    respawnWeapons[] = WEAPON_DEFAULT;
                    magazines[] = {MAGAZINE_DEFAULT};
                    respawnMagazines[] = {MAGAZINE_DEFAULT};
                    items[] = {ITEM_DEFAULT};
                    respawnItems[] = {ITEM_DEFAULT};
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Marine_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Marine_Helmet", "AR_Base_Clone_Vest"};
                };

                class ECVAR(DOUBLES(Marine,CO),Unit) : ECVAR(Marine,Unit) {
                    displayName = SUBCSTRING(TRIPLES(Marine,CO,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Marine,CO),Unit));
                    uniformClass = "AR_Marine_CO_Uniform";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Co_Marine_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Co_Marine_Helmet", "AR_Base_Clone_Vest"};
                };

            // UnArmed
                class ECVAR(DOUBLES(UnArmed,Marine),Unit) : ECVAR(Marine,Unit) {
                    displayName = SUBCSTRING(TRIPLES(UnArmed,Marine,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(UnArmed,Marine),Unit));
                    SUBCATEGORY_AR_UNARMED;
                    weapons[] = {};
                    respawnWeapons[] = {};
                };

                class ECVAR(TRIPLES(UnArmed,Marine,CO),Unit) : ECVAR(DOUBLES(Marine,CO),Unit) {
                    displayName = SUBCSTRING(DOUBLES(TRIPLES(UnArmed,Marine,CO),Unit));
                    EDITORPREVIEW(ECVAR(TRIPLES(UnArmed,Marine,CO),Unit));
                    SUBCATEGORY_AR_UNARMED;
                    weapons[] = {};
                    respawnWeapons[] = {};
                };

        // BARC
            class ECVAR(BARC,Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                displayName = SUBCSTRING(DOUBLES(BARC,Unit));
                EDITORPREVIEW(ECVAR(BARC,Unit));
                linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_BARC_Helmet", "AR_Base_Specialist_Vest"};
                respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_BARC_Helmet", "AR_Base_Specialist_Vest"};
            };

        // Engineer
            // Phase 1
                class ECVAR(DOUBLES(Engineer,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Engineer,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Engineer,P1),Unit));
                    backpack = "ar_eod_heavy_backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Engineer_P1_Helmet", "AR_Base_Engineer_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Engineer_P1_Helmet", "AR_Base_Engineer_Vest"};
                };
        
            // Phase 2
                class ECVAR(DOUBLES(Engineer,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Engineer,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Engineer,P2),Unit));
                    backpack = "AR_EOD_Heavy_Backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Engineer_P2_Helmet", "AR_Base_Engineer_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Engineer_P2_Helmet", "AR_Base_Engineer_Vest"};
                };

        // ARF
            // Phase 1
                class ECVAR(DOUBLES(ARF,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(ARF,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(ARF,P1),Unit));
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_ARF_P1_Helmet", "AR_Base_ARF_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_ARF_P1_Helmet", "AR_Base_ARF_Vest"};
                };

            // Phase 1 Desert
                class ECVAR(DOUBLES(ARF,Desert),Unit) : ECVAR(DOUBLES(ARF,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(ARF,Desert,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(ARF,Desert),Unit));
                    uniformClass = "AR_ARF_Desert_Uniform";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Desert_ARF_P1_Helmet", "AR_Base_ARF_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Desert_ARF_P1_Helmet", "AR_Base_ARF_Vest"};
                };

            // Phase 1 Forest
                class ECVAR(DOUBLES(ARF,Forest),Unit) : ECVAR(DOUBLES(ARF,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(ARF,Forest,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(ARF,Forest),Unit));
                    uniformClass = "AR_ARF_Forest_Uniform";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Forest_ARF_P1_Helmet", "AR_Base_ARF_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Forest_ARF_P1_Helmet", "AR_Base_ARF_Vest"};
                };

            // Phase 2
                class ECVAR(DOUBLES(ARF,P2),Unit) : ECVAR(DOUBLES(ARF,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(ARF,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(ARF,P2),Unit));
                    SUBCATEGORY_AR_P2;
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_ARF_P2_Helmet", "AR_Base_ARF_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_ARF_P2_Helmet", "AR_Base_ARF_Vest"};
                };

        // Pilot
            // Phase 1
                class ECVAR(DOUBLES(Pilot,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Pilot,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Pilot,P1),Unit));
                    backpack = "ls_gar_rto_mini_backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Pilot_P1_Helmet", "AR_Base_CFR_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Pilot_P1_Helmet", "AR_Base_CFR_Vest"};
                };
            
            // Phase 2
                class ECVAR(DOUBLES(Pilot,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Pilot,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Pilot,P2),Unit));
                    backpack = "ls_gar_rto_mini_backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Pilot_P2_Helmet", "AR_Base_CFR_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Pilot_P2_Helmet", "AR_Base_CFR_Vest"};
                };

        // SpecOp
            // Phase 1
                class ECVAR(DOUBLES(SpecOp,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(SpecOp,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(SpecOp,P1),Unit));
                    backpack = "AR_Base_Radio_Backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_SpecOp_P1_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_SpecOp_P1_Helmet", "AR_Base_Clone_Vest"};
                };

            // Phase 2
                class ECVAR(DOUBLES(SpecOp,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(SpecOp,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(SpecOp,P2),Unit));
                    backpack = "AR_Base_Radio_Backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_SpecOp_P2_Helmet", "AR_Base_Clone_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_SpecOp_P2_Helmet", "AR_Base_Clone_Vest"};
                };

        // Scout
            class ECVAR(Scout,Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                displayName = SUBCSTRING(DOUBLES(Scout,Unit));
                EDITORPREVIEW(ECVAR(Scout,Unit));
                uniformClass = "AR_Scout_Uniform";
                linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Scout_Helmet", "AR_Base_Recon_Vest"};
                respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_Base_Scout_Helmet", "AR_Base_Recon_Vest"};
            };

        // AT
            // Phase 1
                class ECVAR(DOUBLES(AT,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(AT,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(AT,P1),Unit));
                    backpack = "AR_Base_Rocket_Backpack";
                    weapons[] = WEAPONS(DC15S,DC17S,RPS6);
                    respawnWeapons[] = WEAPONS(DC15S,DC17S,RPS6);
                    magazines[] = {MAGAZINE_DEFAULT, MAGS_X6(RPS6_MAG)};
                    respawnMagazines[] = {MAGAZINE_DEFAULT, MAGS_X6(RPS6_MAG)};
                };

            // Phase 2
                class ECVAR(DOUBLES(AT,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(AT,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(AT,P2),Unit));
                    backpack = "AR_Base_Rocket_Backpack";
                    weapons[] = WEAPONS(DC15S,DC17S,RPS6);
                    respawnWeapons[] = WEAPONS(DC15S,DC17S,RPS6);
                    magazines[] = {MAGAZINE_DEFAULT, MAGS_X6(RPS6_MAG)};
                    respawnMagazines[] = {MAGAZINE_DEFAULT, MAGS_X6(RPS6_MAG)};
                };
            
        // Médecin
            // Phase 1
                class ECVAR(DOUBLES(Medic,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Medic,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Medic,P1),Unit));
                    backpack = "AR_Base_HeavyMedic_Backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Medic_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Medic_Vest"};
                    items[] = {ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT};
                    respawnItems[] = {ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT};
                };
            
            // Phase 2
                class ECVAR(DOUBLES(Medic,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Medic,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Medic,P2),Unit));
                    backpack = "AR_Base_HeavyMedic_Backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Medic_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Medic_Vest"};
                    items[] = {ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT};
                    respawnItems[] = {ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT,ITEM_DEFAULT};
                };

        // Heavy
            // Phase 1
                class ECVAR(DOUBLES(Heavy,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Heavy,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Heavy,P1),Unit));
                    backpack = "AR_Base_Heavy_Backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Heavy_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Heavy_Vest"};
                    weapons[] = WEAPONS(Z6,DC17S,"");
                    respawnWeapons[] = WEAPONS(Z6,DC17S,"");
                    magazines[] = {MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI};
                    respawnMagazines[] = {MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI};
                };

            // Phase 2
                class ECVAR(DOUBLES(Heavy,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Heavy,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Heavy,P2),Unit));
                    backpack = "AR_Base_Heavy_Backpack";
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Heavy_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Heavy_Vest"};
                    weapons[] = WEAPONS(Z6,DC17S,"");
                    respawnWeapons[] = WEAPONS(Z6,DC17S,"");
                    magazines[] = {MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI};
                    respawnMagazines[] = {MAGS_X6(Z6_MAG),MAGS_X2(DC17S_MAG),MAGS_X2(DETONATOR),MAGS_X2("SmokeShellRed"),MAGS_X2("SmokeShellGreen"),MAGS_X2("SmokeShell"),CTBI};
                };

        // sergeant
            // Phase 1
                class ECVAR(DOUBLES(Sergeant,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Sergeant,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Sergeant,P1),Unit));
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_ReconNCO_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_ReconNCO_Vest"};
                };

            // Phase 2
                class ECVAR(DOUBLES(Sergeant,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Sergeant,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Sergeant,P2),Unit));
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_ReconNCO_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_ReconNCO_Vest"};
                };

        // Lieutenant
            // Phase 1
                class ECVAR(DOUBLES(Lieutenant,P1),Unit) : ECVAR(DOUBLES(V1,P1),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Lieutenant,P1,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Lieutenant,P1),Unit));
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Lieutenant_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P1_Helmet", "AR_Base_Lieutenant_Vest"};
                };

            // Phase 2
                class ECVAR(DOUBLES(Lieutenant,P2),Unit) : ECVAR(DOUBLES(V1,P2),Unit) {
                    displayName = SUBCSTRING(TRIPLES(Lieutenant,P2,Unit));
                    EDITORPREVIEW(ECVAR(DOUBLES(Lieutenant,P2),Unit));
                    linkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Lieutenant_Vest"};
                    respawnlinkedItems[] = {LINKED_ITEMS_DEFAULT, "AR_V1_P2_Helmet", "AR_Base_Lieutenant_Vest"};
                };

    /* END Regs */

    /* Customs */

    /* END Customs */
};
