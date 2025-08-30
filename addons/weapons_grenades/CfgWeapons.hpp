class CfgWeapons{
    class GrenadeLauncher;
    class Throw: GrenadeLauncher{
        muzzles[] += { 
            QSUBCVAR(EMP_Detonator_Muzzle)
        };
        class ThrowMuzzle;
        class SUBCVAR(EMP_Detonator_Muzzle) : ThrowMuzzle{
            author = AUTHOR;
            displayName = SUBCSTRING(EMP_Detonator);
            magazines[] = {QSUBCVAR(EMP_Detonator_Mag)};
        };
    };
};
