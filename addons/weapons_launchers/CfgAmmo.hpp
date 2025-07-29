class CfgAmmo {
    class RocketBase;
    class SUBCVAR(RPS6_AT_Ammo) : RocketBase {
        model = "\A3\weapons_f\launchers\RPG32\tbg32v_rocket.p3d";
        hit = 200;
        indirectHit = 20;
        indirectHitRange = 5;
        airFriction = 0.07;
        sideAirFriction = 0.07;
        simulationStep = 0.02;
        maxSpeed = 140;
        initTime = 0;
        thrustTime = 0.15;
        thrust = 500;
        fuseDistance = 10;
        deleteParentWhenTriggered = 0;
        submunitionAmmo = "ammo_Penetrator_RPG32V";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset = "[0,0,-0.2]";
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0;
        CraterEffects = "ATMissileCrater";
        explosionEffects = "ATMissileExplosion";
        explosive = 1;
        effectsMissileInit = "";
        effectsMissile = "EmptyEffect";
        triggerOnImpact = 1;
        warheadName = "TandemHEAT";
        airLock = 0;
        irLock = 0;
        timeToLive = 10;
        maneuvrability = 0;
        allowAgainstInfantry = 0;
        class CamShakeExplode {
            distance = 99.3296;
            duration = 1.4;
            frequency = 20;
            power = 11;
        };
        class CamShakeFire {
            distance = 35.7771;
            duration = 0.8;
            frequency = 20;
            power = 2.11474;
        };
        class CamShakeHit {
            distance = 1;
            duration = 0.6;
            frequency = 20;
            power = 110;
        };
        class CamShakePlayerFire {
            distance = 1;
            duration = 0.1;
            frequency = 20;
            power = 1;
        };
    };
};
