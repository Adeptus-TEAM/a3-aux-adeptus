class CfgAmmo {
    class JLTS_grenade_emp_ammo;
    class SUBCVAR(emp_ammo) : JLTS_grenade_emp_ammo {
        scope = 2;
        author = AUTHOR;
        model = "\3AS\3AS_Equipment\model\3AS_thermaldet.p3d";
        soundFly[] = {"3AS\3AS_Equipment\SFX\td.ogg",2.5,1,100};
        soundHit1[] = {QPATHTOEF(weapons_grenades,data\sounds\emp_grenade_explosion.ogg), 2.51189, 1, 1500};
        soundHit2[] = {QPATHTOEF(weapons_grenades,data\sounds\emp_grenade_explosion.ogg), 2.51189, 1, 1500};
        soundHit3[] = {QPATHTOEF(weapons_grenades,data\sounds\emp_grenade_explosion.ogg), 2.51189, 1, 1500};
        soundHit4[] = {QPATHTOEF(weapons_grenades,data\sounds\emp_grenade_explosion.ogg), 2.51189, 1, 1500};
        SoundSetExplosion[] = {"","",""};
        hit = 0;
        indirectHit = 0;
        indirectHitRange = 0;
        CraterEffects = "NoCrater";
        class EventHandlers {
            ammoHit	= QUOTE(_this call SUBFUNC(empEffect));
        };
    };
};



