class CfgVehicles {
    class 3as_GNK;
    class JLTS_Ammobox_support_GAR;
    
    class SUBCVAR(arsenalBox) : JLTS_Ammobox_support_GAR {
        displayName = SUBCSTRING(arsenalBox);
        scope = 2;
        scopeCurator = 2;
        CATEGORY_AR;
        SUBCATEGORY_EDITOR;
        EDITORPREVIEW(SUBCVAR(arsenalBox));
        EMPTY_BACKPACK;
        EMPTY_MAGAZINE;
        EMPTY_WEAPON;
        EMPTY_ITEM;
        icon = "iconCrate";
        hiddenSelections[] = {
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\screen_arsenalBox_co.paa)
        };
        class EventHandlers {
            class SUBADDON {
                init = QUOTE(_this spawn SUBFUNC(addLimitedArsenal); _this spawn SUBFUNC(addLimitedAceArsenal));
            };
        };
    };

    class SUBCVAR(unitTraitTerminal) : 3as_GNK {
        displayName = SUBCSTRING(unitTraitTerminal);
        scope = 2;
        scopeCurator = 2;
        CATEGORY_AR;
        SUBCATEGORY_EDITOR;
        EDITORPREVIEW(SUBCVAR(unitTraitTerminal));
        icon = "iconObject_1x2";
        class EventHandlers {
            class SUBADDON {
                init = QUOTE(_this call SUBFUNC(addActionUnitTrait));
            };
        };
    };

    class 3AS_Prop_Base;
    class 3AS_T_Screen : 3AS_Prop_Base {
        class Attributes {
            class ObjectTextureCustom0;
        };
    };
    class 3AS_T_Screen_F : 3AS_T_Screen {};

    class SUBCVAR(garageTerminal) : 3AS_T_Screen_F {
        displayName = SUBCSTRING(garageTerminal);
        scope = 2;
        scopeCurator = 1;
        CATEGORY_AR;
        SUBCATEGORY_EDITOR;
        EDITORPREVIEW(SUBCVAR(garageTerminal));
        class Attributes : Attributes {
            class ObjectTextureCustom0 : ObjectTextureCustom0 { };
            class CVAR(garageSpawnObject) {
                displayName = SUBCSTRING(garageSpawnObject);
                tooltip = SUBCSTRING(garageSpawnObjectTooltip);
                property = QGVAR(garageSpawnObject);
                control = "Edit";
                expression = "_this setVariable ['%s', _value,true]";
                defaultValue = "objNull";
                unique = 0;
                typeName = "STRING";
            };
            class CVAR(garageAreaSize) {
                displayName = SUBCSTRING(garageAreaSize);
                tooltip = SUBCSTRING(garageAreaSizeTooltip);
                property = QGVAR(garageAreaSize);
                control = "Edit";
                expression = "_this setVariable ['%s', _value,true];";
                defaultValue = 10;
                typeName = "NUMBER";
            };
        };
        class EventHandlers {
            class SUBADDON {
                postInit = QUOTE(_this call SUBFUNC(addActionGarage));
            };
        };
    };
};
