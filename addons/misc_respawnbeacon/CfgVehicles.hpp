class CfgVehicles {
    class JLTS_GH_icecream;
    class House;
    class Man;

    class CAManBase : Man {
        class ACE_SelfActions {
            class SUBCVAR(CreateNew) {
                displayName = SUBCSTRING(createNew);
                condition = QUOTE([_player] call SUBFUNC(canCreateNew));
                exceptions[] = {};
                statement = QUOTE([_player] call SUBFUNC(createNew));
                icon = QPATHTOF(data\icons\item_ca.paa);
            };
        };
    };

    class House_F : House {
        class ACE_Actions {
            class ACE_MainActions;
        };
    };

    class ls_commandPost_base : House_F { };
    class ls_commandPost_yellow_base : ls_commandPost_base { };
    class ls_commandPost_republic_yellow : ls_commandPost_yellow_base { };

    class SUBCVAR(Active) : ls_commandPost_republic_yellow {
        displayName = SUBCSTRING(active);
        CATEGORY_AR;
        SUBCATEGORY_EDITOR;
        scope = 1;
        scopeCurator = 1;
        author = AUTHOR;
        hiddenSelections[] = { "insig_republic" };
        hiddenSelectionsTextures[] = { ADEPTUS_COLOR_TEX };
        XEH_ENABLED;
        class ACE_Actions : ACE_Actions {
            class ACE_MainActions : ACE_MainActions {
                class remove {
                    displayName = SUBCSTRING(remove);
                    condition = "true";
                    statement = QUOTE([_target] call SUBFUNC(remove));
                    icon = QPATHTOF(data\icons\item_ca.paa);
                };
            };
        };
    };

    class SUBCVAR(GroundItem) : JLTS_GH_icecream {
        displayName = SUBCSTRING(groundItem);

        CATEGORY_AR;
        SUBCATEGORY_INVENTORY;
        scope = 2;
        scopeCurator = 2;
        author = AUTHOR;
        icon = "iconObject_circle";
        class TransportItems {
            ITEM_XX(SUBCVAR(item),1);
        };
    };
};
