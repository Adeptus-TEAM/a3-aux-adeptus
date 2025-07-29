class CfgVehicles {
    class Land_OPTRE_Bench_Straight;
    
    class SUBCVAR(briefingBench) : Land_OPTRE_Bench_Straight {
        displayName = SUBCSTRING(briefingbench);
        CATEGORY_AR;
        SUBCATEGORY_DEFAULT;
        scope = 2;
        scopeCurator = 1;
        author = AUTHOR;
        EDITORPREVIEW(SUBCVAR(briefingBench));
        acex_sitting_canSit = 1; // Enable sitting
        acex_sitting_sitDirection = 270; // Direction relative to object
        acex_sitting_sitPosition[] = { { -0.25, -0.75, -1 }, { -0.25, 0.75, -1 } }; // Position relative to object (may behave weird with certain objects)
        acex_sitting_interactPosition[] = { { -0.25, -0.75, 0.5 }, { -0.25, 0.75, 0.5 } }; // Position relative to object where the interaction should take place
    };
};
