class cfgWeapons {
    // Imported classes
    CLASS_INHERITANCE(ls_gar_barc_helmet);
    CLASS_INHERITANCE(ls_gar_engineer_helmet);
    CLASS_INHERITANCE(ls_gar_phase1arf_helmet);
    CLASS_INHERITANCE(ls_gar_phase1pilot_helmet);
    CLASS_INHERITANCE(ls_gar_phase2pilot_helmet);
    CLASS_INHERITANCE(ls_gar_scout_helmet);
    CLASS_INHERITANCE(ls_gar_phase1_helmet);
    CLASS_INHERITANCE(ls_gar_phase2_helmet);
    CLASS_INHERITANCE(ls_gar_phase2insulated_helmet);
    CLASS_INHERITANCE(ls_sob_phase1specop_helmet);
    CLASS_INHERITANCE(ls_sob_phase2specop_helmet);
    CLASS_INHERITANCE(ls_gar_rex_helmet);
    CLASS_INHERITANCE(lsd_gar_arc_helmet);

    /* Regs */
        // BARC Helmet
            CLASS_BARC_HELMET(Regs,Base);

        // Engineer Helmet P1
            CLASS_ENGINEER_P1_HELMET(Regs,Base);

        // Engineer Helmet P2
            CLASS_ENGINEER_P2_HELMET(Regs,Base);

        // ARF Helmet P1
            CLASS_ARF_P1_HELMET(Regs,Base);
            CLASS_ARF_P1_HELMET(Regs,Desert);
            CLASS_ARF_P1_HELMET(Regs,Forest);

        // ARF Helmet P2
            CLASS_ARF_P2_HELMET(Regs,Base);

        // Pilot Helmet P1
            CLASS_PILOT_P1_HELMET(Regs,Base);

        // Pilot Helmet P2
            CLASS_PILOT_P2_HELMET(Regs,Base);

        // Scout Helmet
            CLASS_SCOUT_HELMET(Regs,Base);

        // Phase 1 Helmet
            CLASS_P1_HELMET(Regs,V1);
            CLASS_P1_HELMET(Regs,V2);

        // Phase 2 Helmet
            CLASS_P2_HELMET(Regs,V1);
            CLASS_P2_HELMET(Regs,V2);

        // Phase 2 Insulated Helmet
            CLASS_MARINE_HELMET(Regs,Base);
            CLASS_MARINE_HELMET(Regs,CO);

        // Phase 1 SpecOps Helmet
            CLASS_P1_SPECOP_HELMET(Regs,Base);

        // Phase 2 SpecOps Helmet
            CLASS_P2_SPECOP_HELMET(Regs,Base);

        // ARC Helmet
            CLASS_ARC_HELMET(Regs,Base);
    /* End Regs */

    /* Customs */
        // Engineer Helmet P1
            CLASS_ENGINEER_P1_HELMET(Customs,Liberty);

        // Engineer Helmet P2
            CLASS_ENGINEER_P2_HELMET(Customs,Liberty);
            CLASS_ENGINEER_P2_HELMET(Customs,Nek);

        // Phase 1 Helmet
            CLASS_P1_HELMET(Customs,Ankh);
            CLASS_P1_HELMET(Customs,Archer);
            CLASS_P1_HELMET(Customs,Dragon);
            CLASS_P1_HELMET(Customs,Magic);
            CLASS_P1_HELMET(Customs,Phantom);
            CLASS_P1_HELMET(Customs,Puce);
            CLASS_P1_HELMET(Customs,Red);
            CLASS_P1_HELMET(Customs,SixOne);
            CLASS_P1_HELMET(Customs,Spearhead);
            CLASS_P1_HELMET_CUSTOMVISOR(Customs,Gart);

        // Phase 2 Helmet
            CLASS_P2_HELMET(Customs,Ankh);
            CLASS_P2_HELMET(Customs,Dragon);
            CLASS_P2_HELMET(Customs,Ozy);
            CLASS_P2_HELMET(Customs,Phantom);
            CLASS_P2_HELMET(Customs,SixOne);
            CLASS_P2_HELMET_CUSTOMVISOR(Customs,Gart);

        // Pilot Helmet P1
            CLASS_PILOT_P1_HELMET(Customs,Sight);

        // Pilot Helmet P2
            CLASS_PILOT_P2_HELMET(Customs,Nek);
            CLASS_PILOT_P2_HELMET(Customs,Sight);

        // Rex Helmet
            CLASS_REX_HELMET(Customs,Red);

        // Scout Helmet
            CLASS_SCOUT_HELMET(Customs,COde);
            CLASS_SCOUT_HELMET(Customs,Ozy);
            CLASS_SCOUT_HELMET(Customs,Sting);

        /* Customs Helmet w/ visor illumination */
            #undef VISOR_MAT
            #define VISOR_MAT ILLUM_MAT

            // BARC Helmet w/ visor illumination
                CLASS_BARC_HELMET_CUSTOMVISOR(Customs,Puce);
            
            // Phase 1 Helmet w/ visor illumination
                CLASS_P1_HELMET_CUSTOMVISOR(Customs,Bragg);

            // Phase 2 Helmet w/ visor illumination
                CLASS_P2_HELMET_CUSTOMVISOR(Customs,Bragg);
                CLASS_P2_HELMET_CUSTOMVISOR(Customs,Archer);
                CLASS_P2_HELMET_CUSTOMVISOR(Customs,Magic);
                CLASS_P2_HELMET_CUSTOMVISOR(Customs,Spearhead);
            
            #undef VISOR_MAT
            #define VISOR_MAT ""
        /* END Customs Helmet w/ visor illumination */
    /* END Customs */
};
