class CfgWeapons {
    class GrenadeLauncher;
    class Throw: GrenadeLauncher{
        muzzles[] += {QSUBCVAR(emp_muzzle),};

        class ThrowMuzzle;

        class SUBCVAR(emp_muzzle): ThrowMuzzle{
            displayName = CSTRING(emp_displayName);
            magazines[] = {QSUBCVAR(emp_mag)};
        };
    };
};
