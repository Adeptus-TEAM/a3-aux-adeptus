/* Macro for cfgWeapons */
#define VISOR_MAT ""

// BARC Helmet
/**
 * @name CLASS_BARC_HELMET
 * @brief Macro to define a BARC helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_BARC_HELMET(var1,var2)                                                \
    class ECVAR(var2,BARC_helmet) : ls_gar_barc_helmet_base {                            \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,BARC_helmet));                   \
        picture = QPATHTOEF(characters,data\##var1##\helmet_barc_ca.paa);                       \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\barc\##var2##_helmet_co.paa),            \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_BARC_HELMET_CUSTOMVISOR
 * @brief Macro to define a BARC helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_BARC_HELMET_CUSTOMVISOR(var1,var2)                                    \
    class ECVAR(var2,BARC_helmet) : ls_gar_barc_helmet_base {                            \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,BARC_helmet));                   \
        picture = QPATHTOEF(characters,data\##var1##\helmet_barc_ca.paa);                       \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\barc\##var2##_helmet_co.paa),            \
            QPATHTOF(data\##var1##\barc\##var2##_visor_co.paa)              \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// ENGINEER Helmet P1
/**
 * @name CLASS_ENGINEER_P1_HELMET
 * @brief Macro to define an Engineer Phase 1 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ENGINEER_P1_HELMET(var1,var2)                                         \
    class ECVAR(var2,Engineer_P1_Helmet) : ls_gar_phase1pilot_helmet_base {              \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Engineer_P1_Helmet));            \
        picture = QPATHTOEF(characters,data\##var1##\helmet_pilot_p1_ca.paa);                   \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\engineer_p1\##var2##_helmet_co.paa),     \
            QPATHTOF(data\##var1##\engineer_p1\##var2##_lifesupport_co.paa),\
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_ENGINEER_P1_HELMET_CUSTOMVISOR
 * @brief Macro to define an Engineer Phase 1 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ENGINEER_P1_HELMET_CUSTOMVISOR(var1,var2)                             \
    class ECVAR(var2,Engineer_P1_Helmet) : ls_gar_phase1pilot_helmet_base {              \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Engineer_P1_Helmet));            \
        picture = QPATHTOEF(characters,data\##var1##\helmet_pilot_p1_ca.paa);                   \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\engineer_p1\##var2##_helmet_co.paa),     \
            QPATHTOF(data\##var1##\engineer_p1\##var2##_lifesupport_co.paa),\
            QPATHTOF(data\##var1##\engineer_p1\##var2##_visor_co.paa)       \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// ENGINEER Helmet P2
/**
 * @name CLASS_ENGINEER_P2_HELMET
 * @brief Macro to define an Engineer Phase 2 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ENGINEER_P2_HELMET(var1,var2)                                         \
    class ECVAR(var2,Engineer_P2_Helmet) : ls_gar_engineer_helmet_base {                 \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Engineer_P2_Helmet));            \
        picture = QPATHTOEF(characters,data\##var1##\helmet_eng_ca.paa);                        \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\engineer_p2\##var2##_helmet_co.paa),     \
            "\ls\core\addons\characters_clone_legacy\helmets\engineer\data\light_co.paa",\
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            ILLUM_MAT,                                                              \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_ENGINEER_P2_HELMET_CUSTOMVISOR
 * @brief Macro to define an Engineer Phase 2 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ENGINEER_P2_HELMET_CUSTOMVISOR(var1,var2)                             \
    class ECVAR(var2,Engineer_P2_Helmet) : ls_gar_engineer_helmet_base {                 \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Engineer_P2_Helmet));            \
        picture = QPATHTOEF(characters,data\##var1##\helmet_eng_ca.paa);                        \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\engineer_p2\##var2##_helmet_co.paa),     \
            "\ls\core\addons\characters_clone_legacy\helmets\engineer\data\light_co.paa",\
            QPATHTOF(data\##var1##\engineer_p2\##var2##_visor_co.paa)       \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            ILLUM_MAT,                                                              \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// ARF P1 Helmet
/**
 * @name CLASS_ARF_P1_HELMET
 * @brief Macro to define an ARF Phase 1 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ARF_P1_HELMET(var1,var2)                                              \
    class ECVAR(var2,ARF_P1_Helmet) : ls_gar_phase1arf_helmet_base {                     \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,ARF_P1_Helmet));                 \
        picture = QPATHTOEF(characters,data\##var1##\helmet_arf_p1_ca.paa);                     \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\arf_p1\##var2##_helmet_co.paa),          \
            "",                                                                     \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_ARF_P1_HELMET_CUSTOMVISOR
 * @brief Macro to define an ARF Phase 1 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ARF_P1_HELMET_CUSTOMVISOR(var1,var2)                                  \
    class ECVAR(var2,ARF_P1_Helmet) : ls_gar_phase1arf_helmet_base {                     \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,ARF_P1_Helmet));                 \
        picture = QPATHTOEF(characters,data\##var1##\helmet_arf_p1_ca.paa);                     \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\arf_p1\##var2##_helmet_co.paa),          \
            "",                                                                     \
            QPATHTOF(data\##var1##\arf_p1\##var2##_visor_co.paa)            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// ARF P2 Helmet
/**
 * @name CLASS_ARF_P2_HELMET
 * @brief Macro to define an ARF Phase 2 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ARF_P2_HELMET(var1,var2)                                              \
    class ECVAR(var2,ARF_P2_Helmet) : ls_gar_phase1arf_helmet_base {                     \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,ARF_P2_Helmet));                 \
        picture = QPATHTOEF(characters,data\##var1##\helmet_arf_p2_ca.paa);                     \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\arf_p2\##var2##_helmet_co.paa),          \
            QPATHTOF(data\##var1##\arf_p2\##var2##_flaps_co.paa),           \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_ARF_P2_HELMET_CUSTOMVISOR
 * @brief Macro to define an ARF Phase 2 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ARF_P2_HELMET_CUSTOMVISOR(var1,var2)                                  \
    class ECVAR(var2,ARF_P2_Helmet) : ls_gar_phase1arf_helmet_base {                     \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,ARF_P2_Helmet));                 \
        picture = QPATHTOEF(characters,data\##var1##\helmet_arf_p2_ca.paa);                     \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\arf_p2\##var2##_helmet_co.paa),          \
            QPATHTOF(data\##var1##\arf_p2\##var2##_flaps_co.paa),           \
            QPATHTOF(data\##var1##\arf_p2\##var2##_visor_co.paa)            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// Pilot P1 Helmet
/**
 * @name CLASS_PILOT_P1_HELMET
 * @brief Macro to define a Pilot Phase 1 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_PILOT_P1_HELMET(var1,var2)                                            \
    class ECVAR(var2,Pilot_P1_Helmet) : ls_gar_phase1pilot_helmet_base {                 \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Pilot_P1_Helmet));               \
        picture = QPATHTOEF(characters,data\##var1##\helmet_pilot_p1_ca.paa);                   \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\pilot_p1\##var2##_helmet_co.paa),        \
            QPATHTOF(data\##var1##\pilot_p1\##var2##_lifesupport_co.paa),   \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_PILOT_P1_HELMET_CUSTOMVISOR
 * @brief Macro to define a Pilot Phase 1 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_PILOT_P1_HELMET_CUSTOMVISOR(var1,var2)                                \
    class ECVAR(var2,Pilot_P1_Helmet) : ls_gar_phase1pilot_helmet_base {                 \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Pilot_P1_Helmet));               \
        picture = QPATHTOEF(characters,data\##var1##\helmet_pilot_p1_ca.paa);                   \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\pilot_p1\##var2##_helmet_co.paa),        \
            QPATHTOF(data\##var1##\pilot_p1\##var2##_lifesupport_co.paa),   \
            QPATHTOF(data\##var1##\pilot_p1\##var2##_visor_co.paa)          \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// Pilot P2 Helmet
/**
 * @name CLASS_PILOT_P2_HELMET
 * @brief Macro to define a Pilot Phase 2 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_PILOT_P2_HELMET(var1,var2)                                            \
    class ECVAR(var2,Pilot_P2_Helmet) : ls_gar_phase2pilot_helmet_base {                 \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Pilot_P2_Helmet));               \
        picture = QPATHTOEF(characters,data\##var1##\helmet_pilot_p2_ca.paa);                   \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\pilot_p2\##var2##_helmet_co.paa),        \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_PILOT_P2_HELMET_CUSTOMVISOR
 * @brief Macro to define a Pilot Phase 2 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_PILOT_P2_HELMET_CUSTOMVISOR(var1,var2)                                \
    class ECVAR(var2,Pilot_P2_Helmet) : ls_gar_phase2pilot_helmet_base {                 \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Pilot_P2_Helmet));               \
        picture = QPATHTOEF(characters,data\##var1##\helmet_pilot_p2_ca.paa);                   \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\pilot_p2\##var2##_helmet_co.paa),        \
            QPATHTOF(data\##var1##\pilot_p2\##var2##_visor_co.paa)          \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// Phase 1 Helmet
/**
 * @name CLASS_P1_HELMET
 * @brief Macro to define a Phase 1 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., v1, v2)
 */
#define CLASS_P1_HELMET(var1,var2)                                                  \
    class ECVAR(var2,P1_Helmet) : ls_gar_phase1_helmet_base {                            \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P1_Helmet));                     \
        picture = QPATHTOEF(characters,data\##var1##\helmet_p1_ca.paa);                         \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\p1\##var2##_helmet_co.paa),              \
            "#(rgb,8,8,3)color(0,0,0,0)",                                           \
            "#(rgb,8,8,3)color(1,0,0,1)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT,                                                              \
            ILLUM_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_P1_HELMET_CUSTOMVISOR
 * @brief Macro to define a Phase 1 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., v1, v2)
 */
#define CLASS_P1_HELMET_CUSTOMVISOR(var1,var2)                                      \
    class ECVAR(var2,P1_Helmet) : ls_gar_phase1_helmet_base {                            \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P1_Helmet));                     \
        picture = QPATHTOEF(characters,data\##var1##\helmet_p1_ca.paa);                         \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\p1\##var2##_helmet_co.paa),              \
            QPATHTOF(data\##var1##\p1\##var2##_visor_co.paa),               \
            "#(rgb,8,8,3)color(1,0,0,1)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT,                                                              \
            ILLUM_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// Phase 2 Helmet
/**
 * @name CLASS_P2_HELMET
 * @brief Macro to define a Phase 2 helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., v1, v2)
 */
#define CLASS_P2_HELMET(var1,var2)                                                  \
    class ECVAR(var2,P2_Helmet) : ls_gar_phase2_helmet_base {                            \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P2_Helmet));                     \
        picture = QPATHTOEF(characters,data\##var1##\helmet_p2_ca.paa);                         \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\p2\##var2##_helmet_co.paa),              \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_P2_HELMET_CUSTOMVISOR
 * @brief Macro to define a Phase 2 helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., v1, v2)
 */
#define CLASS_P2_HELMET_CUSTOMVISOR(var1,var2)                                      \
    class ECVAR(var2,P2_Helmet) : ls_gar_phase2_helmet_base {                            \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P2_Helmet));                     \
        picture = QPATHTOEF(characters,data\##var1##\helmet_p2_ca.paa);                         \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\p2\##var2##_helmet_co.paa),              \
            QPATHTOF(data\##var1##\p2\##var2##_visor_co.paa)                \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// Scout Helmet
/**
 * @name CLASS_SCOUT_HELMET
 * @brief Macro to define a Scout helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_SCOUT_HELMET(var1,var2)                                               \
    class ECVAR(var2,Scout_Helmet) : ls_gar_scout_helmet_base {                          \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Scout_Helmet));                  \
        picture = QPATHTOEF(characters,data\##var1##\helmet_scout_ca.paa);                      \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\scout\##var2##_helmet_co.paa),           \
            QPATHTOF(data\##var1##\scout\##var2##_helmet_co.paa),           \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_SCOUT_HELMET_CUSTOMVISOR
 * @brief Macro to define a Scout helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_SCOUT_HELMET_CUSTOMVISOR(var1,var2)                                   \
    class ECVAR(var2,Scout_Helmet) : ls_gar_scout_helmet_base {                          \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Scout_Helmet));                  \
        picture = QPATHTOEF(characters,data\##var1##\helmet_scout_ca.paa);                      \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\scout\##var2##_helmet_co.paa),           \
            QPATHTOF(data\##var1##\scout\##var2##_helmet_co.paa),           \
            QPATHTOF(data\##var1##\scout\##var2##_visor_co.paa)             \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// Phase 2 Insulated Helmet
/**
 * @name CLASS_MARINE_HELMET
 * @brief Macro to define a Phase 2 Insulated helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, co)
 */
#define CLASS_MARINE_HELMET(var1,var2)                                              \
    class ECVAR(var2,Marine_Helmet) : ls_gar_phase2insulated_helmet_base {               \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Marine_Helmet));                 \
        picture = QPATHTOEF(characters,data\##var1##\ui_ca.paa);                                \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\marine\##var2##_helmet_co.paa)           \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            ""                                                                      \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// SpecOp Helmet P1
/**
 * @name CLASS_P1_SPECOP_HELMET
 * @brief Macro to define a Phase 1 SpecOps helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_P1_SPECOP_HELMET(var1,var2)                                           \
    class ECVAR(var2,SpecOp_P1_Helmet) : ls_sob_phase1specop_helmet_base {               \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,SpecOp_P1_Helmet));              \
        picture = QPATHTOEF(characters,data\##var1##\helmet_spec_p1_ca.paa);                    \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\specop_p1\##var2##_helmet_co.paa),       \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_P1_SPECOP_HELMET_CUSTOMVISOR
 * @brief Macro to define a Phase 1 SpecOps helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_P1_SPECOP_HELMET_CUSTOMVISOR(var1,var2)                               \
    class ECVAR(var2,SpecOp_P1_Helmet) : ls_sob_phase1specop_helmet_base {               \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,SpecOp_P1_Helmet));              \
        picture = QPATHTOEF(characters,data\##var1##\helmet_spec_p1_ca.paa);                    \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\specop_p1\##var2##_helmet_co.paa),       \
            QPATHTOF(data\##var1##\specop_p1\##var2##_visor_co.paa)         \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// SpecOp Helmet P2
/**
 * @name CLASS_P2_SPECOP_HELMET
 * @brief Macro to define a Phase 2 SpecOps helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_P2_SPECOP_HELMET(var1,var2)                                           \
    class ECVAR(var2,SpecOp_P2_Helmet) : ls_sob_phase2specop_helmet_base {               \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,SpecOp_P2_Helmet));              \
        picture = QPATHTOEF(characters,data\##var1##\helmet_spec_p2_ca.paa);                    \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\specop_p2\##var2##_helmet_co.paa),       \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_P2_SPECOP_HELMET_CUSTOMVISOR
 * @brief Macro to define a Phase 2 SpecOps helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_P2_SPECOP_HELMET_CUSTOMVISOR(var1,var2)                               \
    class ECVAR(var2,SpecOp_P2_Helmet) : ls_sob_phase2specop_helmet_base {               \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,SpecOp_P2_Helmet));              \
        picture = QPATHTOEF(characters,data\##var1##\helmet_spec_p2_ca.paa);                    \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\specop_p2\##var2##_helmet_co.paa),       \
            QPATHTOF(data\##var1##\specop_p2\##var2##_visor_co.paa)         \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// Rex Helmet
/**
 * @name CLASS_REX_HELMET
 * @brief Macro to define a Rex helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_REX_HELMET(var1,var2)                                                 \
    class ECVAR(var2,Rex_Helmet) : ls_gar_rex_helmet_base {                              \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Rex_Helmet));                    \
        picture = QPATHTOEF(characters,data\##var1##\helmet_rex_ca.paa);                        \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\rex\##var2##_helmet_co.paa),             \
            "#(rgb,8,8,3)color(0,0,0,0)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_REX_HELMET_CUSTOMVISOR
 * @brief Macro to define a Rex helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_REX_HELMET_CUSTOMVISOR(var1,var2)                                     \
    class ECVAR(var2,Rex_Helmet) : ls_gar_rex_helmet_base {                              \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Rex_Helmet));                    \
        picture = QPATHTOEF(characters,data\##var1##\helmet_rex_ca.paa);                        \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\rex\##var2##_helmet_co.paa),             \
            QPATHTOF(data\##var1##\rex\##var2##_visor_co.paa)               \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

// ARC Helmet
/**
 * @name CLASS_ARC_HELMET
 * @brief Macro to define an ARC helmet class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ARC_HELMET(var1,var2)                                                 \
    class ECVAR(var2,Arc_Helmet) : lsd_gar_arc_helmet_base {                             \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,Arc_Helmet));                    \
        picture = QPATHTOEF(characters,data\##var1##\helmet_arc_ca.paa);                        \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\arc\##var2##_helmet_co.paa),             \
            "#(rgb,8,8,3)color(0,0,0,0)",                                           \
            "#(rgb,8,8,3)color(1,0,0,1)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT,                                                              \
            ILLUM_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/**
 * @name CLASS_ARC_HELMET_CUSTOMVISOR
 * @brief Macro to define an ARC helmet class with a custom visor.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, desert, forest)
 */
#define CLASS_ARC_HELMET_CUSTOMVISOR(var1,var2)                                     \
    class ECVAR(var2,ARC_Helmet) : lsd_gar_arc_helmet_base {                             \
        author = AUTHOR;                                                            \
        displayName = SUBCSTRING(TRIPLES(var1,var2,ARC_Helmet));                    \
        picture = QPATHTOEF(characters,data\##var1##\helmet_arc_ca.paa);                        \
        scope = 2;                                                               \
        scopeArsenal = 2;                                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\arc\##var2##_helmet_co.paa),             \
            QPATHTOF(data\##var1##\arc\##var2##_visor_co.paa),              \
            "#(rgb,8,8,3)color(1,0,0,1)"                                            \
        };                                                                          \
        hiddenSelectionsMaterials[] = {                                             \
            "",                                                                     \
            VISOR_MAT,                                                              \
            ILLUM_MAT                                                               \
        };                                                                          \
        class ItemInfo : ItemInfo {                                                 \
            mass = MASS_HELMET;                                                     \
            HITPOINTSPROTECTION_HELMET;                                             \
        };                                                                          \
    }

/* Macro for cfgVehicles */
/**
 * @name CLASS_HEADGEAR
 * @brief Macro to define a headgear class in the config.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Base type of the headgear (e.g., base, desert, forest)
 * @param var3 Specific type of the headgear (e.g., barc, engineer_p1, etc.)
 */
#define CLASS_HEADGEAR(var1,var2,var3)                                              \
    class ECVAR(DOUBLES(var2,var3),Headgear) : Headgear_Base_F {                    \
        Author = AUTHOR;                                                            \
        displayName = SUBCSTRING(DOUBLES(TRIPLES(var1,var2,var3),helmet));          \
        scopeCurator = 2;                                                           \
        scope = 2;                                                                  \
        CATEGORY_AR;                                                                \
        SUBCATEGORY_HELMETS;                                                        \
        class TransportItems {                                                      \
            ITEM_XX(ECVAR(DOUBLES(var2,var3),Helmet),1);                            \
        };                                                                          \
    }
