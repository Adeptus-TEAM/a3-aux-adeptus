class CfgAmmo{
    class 3AS_Detonator_1RND;
    class SUBCVAR(EMP_Detonator_Ammo) : 3AS_Detonator_1RND{
        author = AUTHOR;
        soundHit1[] = {QPATHTOF(emp_detonation),2.51189,1,1500};
        soundHit2[] = {QPATHTOF(emp_detonation),2.51189,1,1500};
        soundHit3[] = {QPATHTOF(emp_detonation),2.51189,1,1500};
        soundHit4[] = {QPATHTOF(emp_detonation),2.51189,1,1500};
        SoundSetExplosion[] = {QSUBCVAR(EMP_Detonation_SoundSet),QSUBCVAR(EMP_Detonation_SoundSet),QSUBCVAR(EMP_Detonation_SoundSet)};
    };
};
