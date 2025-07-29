class CfgVehicles {
    class B_MRAP_01_F;

    class SUBCVAR(Base) : B_MRAP_01_F {
        displayName = SUBCSTRING(Base);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_CARS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_V1_P2_Unit";
        EDITORPREVIEW(SUBCVAR(Base));
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Body_co.paa),
            QPATHTOF(data\Back_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Body_co.paa),
                    QPATHTOF(data\Back_co.paa)
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
};
