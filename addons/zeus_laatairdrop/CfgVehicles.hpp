class CfgVehicles {
    class Module_F;
    class CVAR(ModuleLaatAirDrop) : Module_F {
        displayName = CSTRING(LaatAirDrop);
        author = AUTHOR;
        scope = 1;
        scopeCurator = 2;
        CATEGORY_MODULES;
        icon = QPATHTOEF(zeus,data\logo_ca.paa);
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = TRUE;
        isDisposable = TRUE;
        is3DEN = FALSE;
        canSetArea = FALSE;
        canSetAreaShape = FALSE;
        canSetAreaHeight = FALSE;
    };
};
