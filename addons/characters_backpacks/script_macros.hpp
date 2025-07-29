/* Macro for cfgVehicles */

/**
 * @name CLASS_HEAVYMEDIC_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Heavy Medic.
 *        Textures requises : Backpack, Cover, Pouches, Medic.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_HEAVYMEDIC_BACKPACK(var1,var2)                                        \
    class ECVAR(var2,HeavyMedic_Backpack) : ls_gar_heavyMedic_backpack {            \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,HeavyMedic_Backpack));              \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 500;                                                          \
        mass = MASS_BACKPACK;                                                       \
        backpackClass = QECVAR(var2,HeavyMedic_Backpack);                           \
        picture = QPATHTOEF(characters,data\##var1##\backpack_medic_ca.paa);                    \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\heavyMedic\##var2##_Backpack_co.paa),  \
            QPATHTOF(data\##var1##\heavyMedic\##var2##_Cover_co.paa),     \
            QPATHTOF(data\##var1##\heavyMedic\##var2##_Pouches_co.paa),   \
            QPATHTOF(data\##var1##\heavyMedic\##var2##_Medic_co.paa),    \
            QPATHTOF(data\##var1##\heavyMedic\##var2##_Medic_co.paa)     \
        };                                                                          \
    }

/**
 * @name CLASS_HEAVY_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Heavy.
 *        Textures requises : Backpack, Cover, Pouches, Tube.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_HEAVY_BACKPACK(var1,var2)                                             \
    class ECVAR(var2,Heavy_Backpack) : ls_gar_heavy_backpack {                      \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,Heavy_Backpack));                   \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 500;                                                          \
        mass = MASS_BACKPACK;                                                       \
        picture = QPATHTOEF(characters,data\##var1##\backpack_ca.paa);                          \
        backpackClass = QECVAR(var2,Heavy_Backpack);                                \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\heavy\##var2##_Backpack_co.paa),       \
            QPATHTOF(data\##var1##\heavy\##var2##_Cover_co.paa),          \
            QPATHTOF(data\##var1##\heavy\##var2##_Pouches_co.paa),        \
            QPATHTOF(data\##var1##\heavy\##var2##_Tube_co.paa)            \
        };                                                                          \
    }

/**
 * @name CLASS_MEDIUM_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Medium.
 *        Textures requises : Backpack, Cover, Pouches.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_MEDIUM_BACKPACK(var1,var2)                                            \
    class ECVAR(var2,Medium_Backpack) : ls_gar_heavy_backpack {                     \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,Medium_Backpack));                  \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 400;                                                          \
        mass = MASS_BACKPACK;                                                       \
        picture = QPATHTOEF(characters,data\##var1##\backpack_ca.paa);                          \
        backpackClass = QECVAR(var2,Medium_Backpack);                               \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\medium\##var2##_Backpack_co.paa),      \
            QPATHTOF(data\##var1##\medium\##var2##_Cover_co.paa),         \
            QPATHTOF(data\##var1##\medium\##var2##_Pouches_co.paa),       \
            ""                                                                      \
        };                                                                          \
    }

/**
 * @name CLASS_MEDIC_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Medic.
 *        Textures requises : Backpack, Cover, Medic.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_MEDIC_BACKPACK(var1,var2)                                             \
    class ECVAR(var2,Medic_Backpack) : ls_gar_medic_backpack {                      \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,Medic_Backpack));                   \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 300;                                                          \
        mass = MASS_BACKPACK;                                                       \
        picture = QPATHTOEF(characters,data\##var1##\backpack_medic_ca.paa);                    \
        backpackClass = QECVAR(var2,Medic_Backpack);                                \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\medic\##var2##_Backpack_co.paa),       \
            QPATHTOF(data\##var1##\medic\##var2##_Cover_co.paa),          \
            QPATHTOF(data\##var1##\medic\##var2##_Medic_co.paa),         \
            QPATHTOF(data\##var1##\medic\##var2##_Medic_co.paa)          \
        };                                                                          \
    }

/**
 * @name CLASS_MEDIUMRADIO_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Radio Medium.
 *        Textures requises : Backpack, Radio, Screen, Pouches.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_MEDIUMRADIO_BACKPACK(var1,var2)                                       \
    class ECVAR(var2,MediumRadio_Backpack) : ls_gar_mediumRadio_backpack {          \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,MediumRadio_Backpack));             \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 300;                                                          \
        mass = MASS_BACKPACK;                                                       \
        picture = QPATHTOEF(characters,data\##var1##\backpack_rto_ca.paa);                      \
        backpackClass = QECVAR(var2,MediumRadio_Backpack);                          \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\mediumRadio\##var2##_Backpack_co.paa), \
            QPATHTOF(data\##var1##\mediumRadio\##var2##_Radio_co.paa),    \
            QPATHTOF(data\##var1##\mediumRadio\##var2##_Screen_co.paa),   \
            QPATHTOF(data\##var1##\mediumRadio\##var2##_Pouches_co.paa)   \
        };                                                                          \
    }

/**
 * @name CLASS_RADIO_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Radio.
 *        Textures requises : Backpack, Radio, Screen.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_RADIO_BACKPACK(var1,var2)                                             \
    class ECVAR(var2,Radio_Backpack) : ls_gar_radio_backpack {                      \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,Radio_Backpack));                   \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 300;                                                          \
        mass = MASS_BACKPACK;                                                       \
        picture = QPATHTOEF(characters,data\##var1##\backpack_rto_ca.paa);                      \
        backpackClass = QECVAR(var2,Radio_Backpack);                                \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\radio\##var2##_Backpack_co.paa),       \
            QPATHTOF(data\##var1##\radio\##var2##_Radio_co.paa),          \
            QPATHTOF(data\##var1##\radio\##var2##_Screen_co.paa)          \
        };                                                                          \
    }

/**
 * @name CLASS_ROCKET_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Rocket.
 *        Textures requises : Backpack, Holder, Rocket, Pouches.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_ROCKET_BACKPACK(var1,var2)                                            \
    class ECVAR(var2,Rocket_Backpack) : ls_gar_rocket_backpack {                    \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,Rocket_Backpack));                  \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 400;                                                          \
        mass = MASS_BACKPACK;                                                       \
        picture = QPATHTOEF(characters,data\##var1##\backpack_ca.paa);                          \
        backpackClass = QECVAR(var2,Rocket_Backpack);                               \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\rocket\##var2##_Backpack_co.paa),      \
            QPATHTOF(data\##var1##\rocket\##var2##_Holder_co.paa),        \
            QPATHTOF(data\##var1##\rocket\##var2##_Rocket_co.paa),        \
            "#(rgb,8,8,3)color(1,0,0,1)",                                           \
            QPATHTOF(data\##var1##\rocket\##var2##_Pouches_co.paa)        \
        };                                                                          \
    }

/**
 * @name CLASS_STANDARD_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Standard.
 *        Textures requises : Backpack, Pouches.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_STANDARD_BACKPACK(var1,var2)                                          \
    class ECVAR(var2,Standard_Backpack) : ls_gar_standard_backpack {                \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,Standard_Backpack));                \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 300;                                                          \
        mass = MASS_BACKPACK;                                                       \
        picture = QPATHTOEF(characters,data\##var1##\backpack_ca.paa);                          \
        backpackClass = QECVAR(var2,Standard_Backpack);                             \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\standard\##var2##_Backpack_co.paa),    \
            QPATHTOF(data\##var1##\standard\##var2##_Cover_co.paa)      \
        };                                                                          \
    }

/**
 * @name CLASS_INVISIBLE_BACKPACK
 * @brief Macro pour définir une classe de sac à dos Invisible.
 *        Textures requises : aucune.
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : base, arf_desert, arf_forest)
 */
#define CLASS_INVISIBLE_BACKPACK(var1,var2)                                         \
    class ECVAR(var2,Invisible_Backpack) : ls_gar_standard_backpack {               \
        Author = AUTHOR;                                                            \
        displayName = CSTRING(TRIPLES(var1,var2,Invisible_Backpack));               \
        scopeCurator = 1;                                                     \
        scopeArsenal = 2;                                                        \
        scope = 1;                                                            \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_BACKPACKS;                                                      \
        maximumLoad = 300;                                                          \
        picture = QPATHTOEF(characters,data\##var1##\ui_ca.paa);                                \
        mass = MASS_BACKPACK;                                                       \
        backpackClass = QECVAR(var2,Invisible_Backpack);                            \
        hiddenSelectionsTextures[] = { };                                           \
    }
