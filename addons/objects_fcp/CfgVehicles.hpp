class CfgVehicles {
    class Land_Trophy_01_gold_F;
    class CVAR(FCP) : Land_Trophy_01_gold_F {
        displayName = CSTRING(FCP);
        scope = 2;
        scopeCurator = 2;
        model = "3as\3as_static\FCP\model\3AS_FCP.p3d";
        CATEGORY_AR;
        SUBCATEGORY_DEFAULT;
        EDITORPREVIEW(CVAR(FCP));
        class UserActions {
            class deploy {
                displayName = SUBCSTRING(deploy);
                position = "action";
                radius = 5;
                hideOnUse = TRUE;
                onlyForPlayer = TRUE;
                showWindow = TRUE;
                condition = QUOTE([ARR_2(this,player)] call SUBFUNC(canDeploy));
                statement = QUOTE([this] call SUBFUNC(deploy));
            };
            class unDeploy {
                displayName = SUBCSTRING(unDeploy);
                position = "action";
                radius = 5;
                hideOnUse = TRUE;
                onlyForPlayer = TRUE;
                showWindow = TRUE;
                condition = QUOTE([ARR_2(this,player)] call SUBFUNC(canUnDeploy));
                statement = QUOTE([this] call SUBFUNC(unDeploy));
            };
        };
        class AnimationSources {
            class Ramp {
                source = "user";
                initPhase = 1;
                animPeriod = 1;
            };
        };
        EMPTY_ITEM;
        EMPTY_BACKPACK;
        EMPTY_WEAPON;
        EMPTY_MAGAZINE;
        armor = 1000;
        armorStructural = 10;
        tas_canBlift = 1;
        tas_liftVars = "[[[[0.2,-1,-5]]], [0], [0]]";
        icon = "iconObject_1x2";
    };
};
