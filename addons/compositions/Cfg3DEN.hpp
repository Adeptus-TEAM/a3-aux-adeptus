class Cfg3DEN {
    class Compositions {
        class CVAR(BaseTemplate) {
            path = "x\ar\addons\compositions\data\BaseTemplate"; //! DON'T MAKE A `\` BEFORE `x\ar\addons\*`
            side = PROPS;
            CATEGORY_AR;
            SUBCATEGORY_EDITOR;
            scope = 2;
            scopeCurator = 1;
            displayName = CSTRING(BaseTemplate);
            icon = QPATHTOF(data\logo_ca.paa);
            useSideColorOnIcon = 1;
        };
        class CVAR(Venator) {
            path = "x\ar\addons\compositions\data\Venator"; //! DON'T MAKE A `\` BEFORE `x\ar\addons\*`
            side = PROPS;
            CATEGORY_AR;
            SUBCATEGORY_EDITOR;
            scope = 2;
            scopeCurator = 1;
            displayName = CSTRING(Venator);
            icon = QPATHTOF(data\logo_ca.paa);
            useSideColorOnIcon = 1;
        };
    };
};
