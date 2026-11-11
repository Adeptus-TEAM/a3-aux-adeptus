class CfgVehicles{
    class Logic;
    class Module_F : Logic {
        class AttributesBase {
            class ModuleDescription;
        };
        class ModuleDescription;
    };

    class CVAR(ModuleGarageSpawn) : Module_F{
        displayName = SUBCSTRING(ModuleGarageSpawn);
        author = AUTHOR;
        scope = 2;
        scopeCurator = 0;
        CATEGORY_MODULES;
        function = QSUBFUNC(moduleGarageSpawn);
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;
        canSetArea = 1;
        canSetAreaShape = 1;
        canSetAreaHeight = 1;

        class AttributeValues {
            size3[] = {10, 10, 10};
            isRectangle = 1;
        };

        class Attributes : AttributesBase {
            class ModuleDescription : ModuleDescription {};
        };

        class ModuleDescription : ModuleDescription {
            description = SUBCSTRING(ModuleGarageSpawn_Description);
            position = 1;
            direction = 1;
            sync[] = {};
        };
    };
};
