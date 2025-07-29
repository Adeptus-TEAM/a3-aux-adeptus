class CfgGroups {
    class West {
        class AR_P1 {
            name = "$STR_AR_GROUPS_CloneP1";
            class Infantry {
                name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY0";
                class InfSquad {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFSQUAD0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Lieutenant,P1),Unit);
                        rank = "LIEUTENANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Engineer,P1),Unit);
                        rank = "CORPORAL";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                    class Unit4 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Sergeant,P1),Unit);
                        rank = "SERGEANT";
                        position[] = { -10, -10, 0 };
                    };
                    class Unit5 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P1),Unit);
                        rank = "CORPORAL";
                        position[] = { 15, -15, 0 };
                    };
                    class Unit6 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Heavy,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { -15, -15, 0 };
                    };
                    class Unit7 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Medic,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { 20, -20, 0 };
                    };
                };
                class InfTeam {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFTEAM0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Sergeant,P1),Unit);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P1),Unit);
                        rank = "CORPORAL";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Medic,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                };
                class InfTeam_AT {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFTEAM_AT0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Sergeant,P1),Unit);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P1),Unit);
                        rank = "CORPORAL";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                };
                class InfSentry {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFSENTRY0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Heavy,P1),Unit);
                        rank = "CORPORAL";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                };
                class ReconSentry {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_RECONSENTRY0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_recon.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(ARF,P1),Unit);
                        rank = "CORPORAL";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(ARF,P1),Unit);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                };
            };
        };

        class AR_P2 {
            name = "$STR_AR_GROUPS_CloneP2";
            class Infantry {
                name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY0";
                class InfSquad {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFSQUAD0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Lieutenant,P2),Unit);
                        rank = "LIEUTENANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Engineer,P2),Unit);
                        rank = "CORPORAL";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                    class Unit4 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Sergeant,P2),Unit);
                        rank = "SERGEANT";
                        position[] = { -10, -10, 0 };
                    };
                    class Unit5 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P2),Unit);
                        rank = "CORPORAL";
                        position[] = { 15, -15, 0 };
                    };
                    class Unit6 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Heavy,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { -15, -15, 0 };
                    };
                    class Unit7 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Medic,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { 20, -20, 0 };
                    };
                };
                class InfTeam {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFTEAM0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Sergeant,P2),Unit);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P2),Unit);
                        rank = "CORPORAL";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Medic,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                };
                class InfTeam_AT {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFTEAM_AT0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Sergeant,P2),Unit);
                        rank = "SERGEANT";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P2),Unit);
                        rank = "CORPORAL";
                        position[] = { 5, -5, 0 };
                    };
                    class Unit2 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { -5, -5, 0 };
                    };
                    class Unit3 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(AT,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { 10, -10, 0 };
                    };
                };
                class InfSentry {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_INFSENTRY0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(Heavy,P2),Unit);
                        rank = "CORPORAL";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(V1,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                };
                class ReconSentry {
                    name = "$STR_A3_CFGGROUPS_WEST_BLU_F_INFANTRY_BUS_RECONSENTRY0";
                    side = BLUFOR;
                    FACTION_AR_BLUFOR;
                    icon = "\A3\ui_f\data\map\markers\nato\b_recon.paa";
                    class Unit0 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(ARF,P2),Unit);
                        rank = "CORPORAL";
                        position[] = { 0, 0, 0 };
                    };
                    class Unit1 {
                        side = BLUFOR;
                        vehicle = QECVAR(DOUBLES(ARF,P2),Unit);
                        rank = "PRIVATE";
                        position[] = { 5, -5, 0 };
                    };
                };
            };
        };
    };
};
