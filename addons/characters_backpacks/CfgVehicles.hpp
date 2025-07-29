class cfgVehicles {
    // Imported classes
    class ls_gar_heavyMedic_backpack;
    class ls_gar_heavy_backpack;
    class ls_gar_medic_backpack;
    class ls_gar_mediumRadio_backpack;
    class ls_gar_radio_backpack;
    class ls_gar_rocket_backpack;
    class ls_gar_standard_backpack;

    /* Regs */
        // Medic
        CLASS_HEAVYMEDIC_BACKPACK(Regs,Base);
        CLASS_MEDIC_BACKPACK(Regs,Base);

        // Standard
        CLASS_HEAVY_BACKPACK(Regs,Base);        
        CLASS_MEDIUM_BACKPACK(Regs,Base);
        CLASS_STANDARD_BACKPACK(Regs,Base);
        CLASS_INVISIBLE_BACKPACK(Regs,Base);

        // EOD
        CLASS_HEAVY_BACKPACK(Regs,EOD);

        // Rocket
        CLASS_ROCKET_BACKPACK(Regs,Base);

        // Radio
        CLASS_MEDIUMRADIO_BACKPACK(Regs,Base);
        CLASS_RADIO_BACKPACK(Regs,Base);

    /* END Regs */

    /* Customs */
        CLASS_MEDIUMRADIO_BACKPACK(Customs,Spearhead);

    /* END Customs */
};
