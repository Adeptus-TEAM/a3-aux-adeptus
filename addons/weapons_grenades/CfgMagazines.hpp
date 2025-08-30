class CfgMagazines{
    class 3AS_ThermalDetonator;
    class SUBCVAR(EMP_Detonator_Mag) : 3AS_ThermalDetonator{
        author = AUTHOR;
        displayName = SUBCSTRING(EMP_Detonator);
        descriptionShort = SUBCSTRING(EMP_Detonator_Short);
        displayNameShort = SUBCSTRING(EMP_Detonator_Short);
        ammo = QSUBCVAR(EMP_Detonator_Ammo);
    };
};
