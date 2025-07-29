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
                init = QUOTE(_this spawn SUBFUNC(addLimitedArsenal));
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
            class CVAR(garageVehiclesList) {
                displayName = SUBCSTRING(garageVehiclesList);
                tooltip = SUBCSTRING(garageVehiclesListTooltip);
                property = QGVAR(garageVehiclesList);
                control = "Combo";
                expression = "_this setVariable ['%s', _value,true];";
                defaultValue = 0;
                typeName = "NUMBER";
                class Values {
                    class CVAR(TerrestrialVehicles) {
                        name = SUBCSTRING(TerrestrialVehicles);
                        value = 0;
                        pictureRight = "3AS\3AS_ATTE\data\ui\atte_top_ca.paa";
                    };
                    class CVAR(TransportAerialVehicles) {
                        name = SUBCSTRING(TransportAerialVehicles);
                        value = 1;
                        pictureRight = "3AS\3AS_LAAT\laati\data\ui\map_laat_ca.paa";
                    };
                    class CVAR(AttackAerialVehicles) {
                        name = SUBCSTRING(AttackAerialVehicles);
                        value = 2;
                        pictureRight = "3AS\3AS_ARC170\data\ui\arc_top_ca.paa";
                    };
                    class CVAR(SupplyCrate) {
                        name = SUBCSTRING(SupplyCrate);
                        value = 3;
                        pictureRight = "a3\ui_f\data\map\vehicleicons\iconcrateammo_ca.paa";
                    };
                };
            };
        };
        class EventHandlers {
            class SUBADDON {
                postInit = QUOTE(_this call SUBFUNC(addActionGarage));
            };
        };
    };
};
