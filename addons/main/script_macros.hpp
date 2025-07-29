#define DEBUG_SYNCHRONOUS

#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\cba\addons\xeh\script_xeh.hpp"

/*
    Color
*/
#define ADEPTUS_COLOR { 1, 0.8235, 0, 1 }
#define ADEPTUS_COLOR_TEX "#(argb,8,8,3)color(1,0.8235,0,1,ca)"
#define ADEPTUS_COLOR_HEX #ffd200

/*
    Boolean
*/
#define TRUE 1
#define FALSE 0

/*
    Side
*/
#define OPFOR 0
#define BLUFOR 1
#define AAF 2
#define CIVIL 3
#define PROPS 8

/*
    Faction and Subcategory >> Characters and Vehicles
*/
#define FACTION_AR_BLUFOR faction = "AR_Blufor"
#define SUBCATEGORY_AR_P1 editorSubcategory = "AR_P1"
#define SUBCATEGORY_AR_P2 editorSubcategory = "AR_P2"
#define SUBCATEGORY_AR_UNARMED editorSubcategory = "AR_Unarmed"
#define SUBCATEGORY_AR_MARINE editorSubcategory = "AR_Marine"
#define SUBCATEGORY_PLANES editorSubcategory = "EdSubcat_Planes"
#define SUBCATEGORY_HELICOPTERS editorSubcategory = "EdSubcat_Helicopters"
#define SUBCATEGORY_CARS editorSubcategory = "EdSubcat_Cars"
#define SUBCATEGORY_APCS editorSubcategory = "EdSubcat_APCs"
#define SUBCATEGORY_TANKS editorSubcategory = "EdSubcat_Tanks"
#define SUBCATEGORY_WALKER editorSubcategory = "3AS_EdSubcat_Walker"

/*
    Category and Subcategory >> Props
*/
#define CATEGORY_AR editorCategory = "AR"
#define SUBCATEGORY_DEFAULT editorSubcategory = "EdSubcat_Default"
#define SUBCATEGORY_INVENTORY editorSubcategory = "EdSubcat_InventoryItems"
#define SUBCATEGORY_HELMETS editorSubcategory = "EdSubcat_Helmets"
#define SUBCATEGORY_BACKPACKS editorSubcategory = "EdSubcat_Backpacks"
#define SUBCATEGORY_STORAGE editorSubcategory = "EdSubcat_Storage"
#define SUBCATEGORY_DECALS editorSubcategory = "EdSubcat_Decals"
#define SUBCATEGORY_EDITOR editorSubcategory = "AR_editor"
#define SUBCATEGORY_SKYBOX editorSubcategory = "AR_skybox"

/*
    Category >> Modules
*/
#define CATEGORY_MODULES category = "AR_Blufor"


/*
    Vehicule Transport Inventory
*/
#define MAG_XX(var1, var2)      \
    class _xx_##var1 {          \
        magazine = QUOTE(var1); \
        count = var2;           \
    }

#define WEAP_XX(var1, var2)   \
    class _xx_##var1 {        \
        weapon = QUOTE(var1); \
        count = var2;         \
    }

#define ITEM_XX(var1, var2) \
    class _xx_##var1 {      \
        name = QUOTE(var1); \
        count = var2;       \
    }

#define EMPTY_ITEM         \
    class TransportItems { \
    }

#define EMPTY_BACKPACK         \
    class TransportBackpacks { \
    }

#define EMPTY_WEAPON         \
    class TransportWeapons { \
    }

#define EMPTY_MAGAZINE         \
    class TransportMagazines { \
    }

#define SUPPLY_XX(var1) QUOTE(Supply##var1)

/*
    SubComponent
*/
#ifdef SUBCOMPONENT
    #undef PATHTOF
    #undef PATHTO
    #define PATHTOF(var1) PATHTOF_SYS(PREFIX,DOUBLES(COMPONENT,SUBCOMPONENT),var1)
    #define PATHTO(var1) PATHTO_SYS(PREFIX,DOUBLES(COMPONENT_F,SUBCOMPONENT),var1)

    #undef COMPILE_SCRIPT
    #define COMPILE_SCRIPT(var1) compileScript ['PATHTO_SYS(PREFIX,DOUBLES(COMPONENT_F,SUBCOMPONENT),var1)']
#endif

/*
    Function Macros
*/
#ifdef SUBCOMPONENT
    #define SUBFUNC(var1) TRIPLES(TRIPLES(PREFIX,COMPONENT,SUBCOMPONENT),fnc,var1)
    #define QSUBFUNC(var1) QUOTE(SUBFUNC(var1))
    #define QQSUBFUNC(var1) QUOTE(QSUBFUNC(var1))
#endif

/*
    Preprocessing and Compilation
*/
#undef PREP
#ifdef SUBCOMPONENT
    // UNCOMMENTED CODE IS FOR DEBUGGING PURPOSES
    // #define LINKFUNC(x) {call SUBFUNC(x)}
    // #define PREP(fncName) SUBFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
    // #define PREP_RECOMPILE_START    if (isNil QFUNCMAIN(recompile)) then {ar_recompiles = []; FUNCMAIN(recompile) = {{call _x} forEach ar_recompiles;}}; private _recomp = {
    // #define PREP_RECOMPILE_END      }; call _recomp; ar_recompiles pushBack _recomp;

    #define LINKFUNC(x) SUBFUNC(x)
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QSUBFUNC(fncName)] call CBA_fnc_compileFunction
    #define PREP_RECOMPILE_START ; /* disabled */
    #define PREP_RECOMPILE_END ; /* disabled */
#else
    // UNCOMMENTED CODE IS FOR DEBUGGING PURPOSES
    // #define LINKFUNC(x) {call FUNC(x)}
    // #define PREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
    // #define PREP_RECOMPILE_START    if (isNil QFUNCMAIN(recompile)) then {ar_recompiles = []; FUNCMAIN(recompile) = {{call _x} forEach ar_recompiles;}}; private _recomp = {
    // #define PREP_RECOMPILE_END      }; call _recomp; ar_recompiles pushBack _recomp;

    #define LINKFUNC(x) FUNC(x)
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
    #define PREP_RECOMPILE_START ; /* disabled */
    #define PREP_RECOMPILE_END ; /* disabled */
#endif

/*
    Class naming macros
*/
#define CVAR(var1) DOUBLES(DOUBLES(PREFIX,COMPONENT),var1)
#define QCVAR(var1) QUOTE(CVAR(var1))

#define ECVAR(var1,var2) TRIPLES(PREFIX,var1,var2)
#define QECVAR(var1,var2) QUOTE(ECVAR(var1,var2))

#ifdef SUBCOMPONENT
    #define SUBCVAR(var1) DOUBLES(TRIPLES(PREFIX,COMPONENT,SUBCOMPONENT),var1)
    #define QSUBCVAR(var1) QUOTE(SUBCVAR(var1))
#endif

/*
    materials Light
*/
#define ILLUM_MAT QPATHTOEF(main,data\rvmat\Light.rvmat)

/*
    Editor Preview
*/
#define EDITORPREVIEW(var1) editorPreview = QPATHTOF(data\editorPreview\DOUBLES(var1,co).jpg)
