class CfgAmmo{
    class 3AS_Detonator_1RND;
    class SUBCVAR(EMP_Detonator_Ammo) : 3AS_Detonator_1RND{
        author = AUTHOR;
        SoundSetExplosion[] = {QSUBCVAR(EMP_Detonation_SoundSet),QSUBCVAR(EMP_Detonation_SoundSet),QSUBCVAR(EMP_Detonation_SoundSet)};
        explosionEffects = "JLTS_fx_exp_EMP";
    };
};
