class CfgVehicles {
    class House_F;

    class SUBCVAR(hyperspace) : House_F {
        displayName = SUBCSTRING(hyperspace);
        scope = 2;
        scopeCurator = 2;
        CATEGORY_AR;
        SUBCATEGORY_SKYBOX;
        model = QPATHTOF(data\models\hyperspace_F.p3d);
        hiddenSelections[] = {
            "camo"
};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\textures\hyperspace_co.paa)
        };

        class UVAnimations{
            class SUBCVAR(hyperspace) {
                type = "translation";
                source = "time";
                section = "camo";
                sourceAddress = "loop";
                minValue = 0;
                maxValue = 5;
                offset0[] = {0, 0};
                offset1[] = {0, 1};
            };
        };
        class AnimationSources{
            class SUBCVAR(hyperspace) {
                source = "time";
                animPeriod = 1;
                initPhase = 0;
            };
        };
    };
};
