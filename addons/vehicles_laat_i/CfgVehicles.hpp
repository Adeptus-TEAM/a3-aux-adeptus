class CfgVehicles {
    class 3as_LAAT_Mk1;
    class 3as_LAAT_Mk1Lights;
    class 3as_LAAT_Mk2;
    class 3as_LAAT_Mk2Lights;

    class SUBCVAR(Mk1) : 3as_LAAT_Mk1 {
        displayName = SUBCSTRING(Mk1);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_HELICOPTERS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_Pilot_P2_Unit";
        EDITORPREVIEW(SUBCVAR(Mk1));
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Hull_co.paa),
            QPATHTOF(data\Wings_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Hull_co.paa),
                    QPATHTOF(data\Wings_co.paa)
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
    };

    class SUBCVAR(Mk1Lights) : 3as_LAAT_Mk1Lights {
        displayName = SUBCSTRING(Mk1Lights);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_HELICOPTERS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_Pilot_P2_Unit";
        EDITORPREVIEW(SUBCVAR(Mk1Lights));
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Hull_co.paa),
            QPATHTOF(data\Wings_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Hull_co.paa),
                    QPATHTOF(data\Wings_co.paa)
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
    };

    class SUBCVAR(Mk2) : 3as_LAAT_Mk2 {
        displayName = SUBCSTRING(Mk2);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_HELICOPTERS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_Pilot_P2_Unit";
        EDITORPREVIEW(SUBCVAR(Mk2));
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Hull_co.paa),
            QPATHTOF(data\Wings_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Hull_co.paa),
                    QPATHTOF(data\Wings_co.paa)
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
    };

    class SUBCVAR(Mk2Lights) : 3as_LAAT_Mk2Lights {
        displayName = SUBCSTRING(Mk2Lights);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_HELICOPTERS;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_Pilot_P2_Unit";
        EDITORPREVIEW(SUBCVAR(Mk2Lights));
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Hull_co.paa),
            QPATHTOF(data\Wings_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Hull_co.paa),
                    QPATHTOF(data\Wings_co.paa)
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
    };
};
