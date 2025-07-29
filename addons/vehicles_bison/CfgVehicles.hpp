class CfgVehicles {
    class OPTRE_M411_APC_UNSC;
    class OPTRE_M412_IFV_UNSC;
    class OPTRE_M413_MGS_UNSC;

    class SUBCVAR(M411) : OPTRE_M411_APC_UNSC {
        displayName = SUBCSTRING(M411);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_APCS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_V1_P2_Unit";
        EDITORPREVIEW(SUBCVAR(M411));
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Body_co.paa),
            QPATHTOF(data\Misc_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Body_co.paa),
                    QPATHTOF(data\Misc_co.paa)
                };
            };
        };
        textureList[] = {
            QSUBCVAR(texture_0), 1
        };
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        tas_canBlift = 1;
        tas_liftVars = "[[[[0,0,-2.5]]], [0], [0]]";
    };

    class SUBCVAR(M412) : OPTRE_M412_IFV_UNSC {
        displayName = SUBCSTRING(M412);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_APCS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_V1_P2_Unit";
        EDITORPREVIEW(SUBCVAR(M412));
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Body_co.paa),
            QPATHTOF(data\Misc_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Body_co.paa),
                    QPATHTOF(data\Misc_co.paa)
                };
            };
            textureList[] = {
                QSUBCVAR(texture_0), 1
            };
        };
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        tas_canBlift = 1;
        tas_liftVars = "[[[[0,0,-2.5]]], [0], [0]]";
    };

    class SUBCVAR(M413) : OPTRE_M413_MGS_UNSC {
        displayName = SUBCSTRING(M413);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_APCS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_V1_P2_Unit";
        EDITORPREVIEW(SUBCVAR(M413));
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Body_co.paa),
            QPATHTOF(data\Misc_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Body_co.paa),
                    QPATHTOF(data\Misc_co.paa)
                };
            };
            textureList[] = {
                QSUBCVAR(texture_0), 1
            };
        };
        EMPTY_BACKPACK;
        EMPTY_ITEM;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        tas_canBlift = 1;
        tas_liftVars = "[[[[0,0,-2.5]]], [0], [0]]";
    };
};
