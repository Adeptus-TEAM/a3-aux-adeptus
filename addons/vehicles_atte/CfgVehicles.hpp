class CfgVehicles {
    class 3AS_ATTE_Base;

    class SUBCVAR(Base) : 3AS_ATTE_Base {
        displayName = SUBCSTRING(Base);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 2;
        FACTION_AR_BLUFOR;
        SUBCATEGORY_WALKER;
        side = BLUFOR;
        forceInGarage = 2;
        cargoCanEject = 1;
        crew = "AR_V1_P2_Unit";
        EDITORPREVIEW(SUBCVAR(Base));
        hiddenSelections[] = {"camo1","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\Shell_co.paa),
            QPATHTOF(data\Legs_co.paa)
        };
        class textureSources {
            class SUBCVAR(texture_0) {
                displayName = ECSTRING(main,3den);
                author = AUTHOR;
                textures[] = {
                    QPATHTOF(data\Shell_co.paa),
                    QPATHTOF(data\Legs_co.paa)
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
};
