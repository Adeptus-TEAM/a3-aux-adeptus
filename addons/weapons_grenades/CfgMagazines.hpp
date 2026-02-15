class CfgMagazines {
    class HandGrenade;
    class SUBCVAR(emp_mag) : HandGrenade{
        scope = 2;
        author = AUTHOR;

        ammo = QSUBCVAR(emp_ammo);
        displayName = CSTRING(emp_displayName);
        displayNameShort = CSTRING(emp_displayName);
        model = "\3AS\3AS_Equipment\model\3AS_thermaldet.p3d";
        picture = QPATHTOF(data\EMP_Detonator_ca.paa);
    };
};
