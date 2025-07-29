class CfgVehicles {
    class I_APC_Wheeled_03_cannon_F;
    class APC_Wheeled_03_cannon_F : I_APC_Wheeled_03_cannon_F {
        class AnimationSources;
        scope = 0;
        scopeCurator = 0;
    };

    class SUBCVAR(TSP) : APC_Wheeled_03_cannon_F {
        displayName = SUBCSTRING(TSP);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_APCS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_V1_P2_Unit";
        EDITORPREVIEW(SUBCVAR(TSP));
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "CamoNet",
            "CamoSlat"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\body_co.paa),
            QPATHTOF(data\body2_co.paa),
            QPATHTOF(data\doors_co.paa),
            QPATHTOF(data\grille_ca.paa),
            "a3\Armor_F\Data\camonet_DT.paa",
            QPATHTOF(data\cage_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\body_co.paa),
                    QPATHTOF(data\body2_co.paa),
                    QPATHTOF(data\doors_co.paa),
                    QPATHTOF(data\grille_ca.paa),
                    "a3\Armor_F\Data\camonet_DT.paa",
                    QPATHTOF(data\cage_co.paa)
                };
            };
        };
        textureList[] = {
            QSUBCVAR(texture_0), 1
        };
        class AnimationSources : AnimationSources {
            class BreakWater {
                source = "user";
                initPhase = 0;
                animPeriod = 2;
            };
            class HideTurret {
                source = "user";
                animPeriod = 0.001;
                initPhase = 1;
            };
            class showBags {
                source = "user";
                animPeriod = 0.001;
                initPhase = 0;
            };
        };
        animationList[] = {
            "showTools",
            1,
            "showSLATHull",
            0,
            "showBags1",
            1,
            "showCamonetHull",
            0
        };
        class Turrets { };
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        tas_canBlift = 1;
        tas_liftVars = "[[[[0,0,-2.5]]], [0], [0]]";
    };
};
