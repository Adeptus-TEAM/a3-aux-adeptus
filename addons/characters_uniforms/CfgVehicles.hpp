class cfgVehicles {
    // Imported classes
    class lsd_gar_phase2_base;
    class lsd_gar_phase2Insulated_base;

    /* Regs */
        // standard
            CLASS_UNIFORM_V(Regs,ARF_Desert);
            CLASS_UNIFORM_V(Regs,ARF_Forest);
            CLASS_UNIFORM_V(Regs,Engineer);
            CLASS_UNIFORM_V(Regs,Scout);
            CLASS_UNIFORM_V(Regs,V1);
            CLASS_UNIFORM_V(Regs,V2);

        // Insulated
            CLASS_UNIFORM_V_INSULATED(Regs,Marine);
            CLASS_UNIFORM_V_INSULATED(Regs,Marine_CO);

    /* END Regs */

    /* Customs */
        // standard
            CLASS_UNIFORM_V(Customs,Ankh);
            CLASS_UNIFORM_V(Customs,Archer);
            CLASS_UNIFORM_V(Customs,Dragon);
            CLASS_UNIFORM_V(Customs,Gart);
            CLASS_UNIFORM_V(Customs,Liberty);
            CLASS_UNIFORM_V(Customs,Magic);
            CLASS_UNIFORM_V(Customs,Nek);
            CLASS_UNIFORM_V(Customs,Ozy);
            CLASS_UNIFORM_V(Customs,Puce);
            CLASS_UNIFORM_V(Customs,Red);
            CLASS_UNIFORM_V(Customs,Sight);
            CLASS_UNIFORM_V(Customs,SixOne);
            CLASS_UNIFORM_V(Customs,Spearhead);
            CLASS_UNIFORM_V(Customs,Sting);
            CLASS_UNIFORM_V_CUSTOMUNDERSUIT(Customs,Phantom);

        // insulated
            CLASS_UNIFORM_V_INSULATED(Customs,Code);

    /* END Customs */
};
