/* Macro for cfgWeapons */
/**
 * @name CLASS_UNIFORM
 * @brief Macro to define a uniform class.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, arf_desert, arf_forest)
 */
#define CLASS_UNIFORM(var1,var2)                                                    \
    class ECVAR(var2,Uniform) : ls_gar_phase2_uniform_base {                             \
        Author = AUTHOR;                                                            \
        scopeArsenal = 2;                                                        \
        scope = 2;                                                               \
        displayName = SUBCSTRING(DOUBLES(var1,var2));                               \
        picture = QPATHTOEF(characters,data\##var1##\body_ca.paa);                              \
        class ItemInfo : ItemInfo {                                              \
            uniformModel = "-";                                                     \
            uniformType = "neopren";                                                \
            uniformClass = QECVAR(var2,U);                                        \
            containerClass = CONTAINER_UNIFORM;                                     \
            mass = MASS_UNIFORM;                                                    \
        };                                                                          \
    }


/* Macro for cfgVehicles */
/**
 * @name CLASS_UNIFORM_V
 * @brief Macro to define a uniform class for cfgVehicles.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, arf_desert, arf_forest)
 */
#define CLASS_UNIFORM_V(var1,var2)                                                  \
    class ECVAR(var2,U) : lsd_gar_phase2_base {                                     \
        Author = AUTHOR;                                                            \
        scopeCurator = 1;                                                     \
        scope = 1;                                                            \
        uniformClass = QECVAR(var2,Uniform);                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\##var2##_camo1_co.paa),                 \
            QPATHTOF(data\##var1##\##var2##_camo2_co.paa),                 \
            QPATHTOF(data\undersuit_co.paa)                                \
        };                                                                          \
    }

/**
 * @name CLASS_UNIFORM_V_CUSTOMUNDERSUIT
 * @brief Macro to define a uniform class with a custom undersuit for cfgVehicles.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., base, arf_desert, arf_forest)
 */
#define CLASS_UNIFORM_V_CUSTOMUNDERSUIT(var1,var2)                                  \
    class ECVAR(var2,U) : lsd_gar_phase2_base {                                     \
        Author = AUTHOR;                                                            \
        scopeCurator = 1;                                                     \
        scope = 1;                                                            \
        uniformClass = QECVAR(var2,Uniform);                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\##var2##_camo1_co.paa),                 \
            QPATHTOF(data\##var1##\##var2##_camo2_co.paa),                 \
            QPATHTOF(data\##var1##\##var2##_undersuit_co.paa)              \
        };                                                                          \
    }

/**
 * @name CLASS_UNIFORM_V_INSULATED
 * @brief Macro to define an insulated uniform class for cfgVehicles.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., marine, marine_co)
 */
#define CLASS_UNIFORM_V_INSULATED(var1,var2)                                        \
    class ECVAR(var2,U) : lsd_gar_phase2Insulated_base {                            \
        Author = AUTHOR;                                                            \
        scopeCurator = 1;                                                     \
        scope = 1;                                                            \
        uniformClass = QECVAR(var2,Uniform);                                        \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\##var2##_camo1_co.paa),                 \
            QPATHTOF(data\##var1##\##var2##_camo2_co.paa),                 \
            QPATHTOF(data\undersuit_marine_co.paa)                         \
        };                                                                          \
    }

/**
 * @name CLASS_UNIFORM_V_CUSTOMUNDERSUIT_INSULATED
 * @brief Macro to define an insulated uniform class with a custom undersuit for cfgVehicles.
 * @param var1 Name of the faction (regs or customs)
 * @param var2 Name of the variant (e.g., marine, marine_co)
 */
#define CLASS_UNIFORM_V_CUSTOMUNDERSUIT_INSULATED(var1,var2)                        \
    class ECVAR(var2,U) : lsd_gar_phase2Insulated_base {                            \
        Author = AUTHOR;                                                            \
        scopeCurator = 1;                                                     \
        scope = 1;                                                            \
        uniformClass = QECVAR(var2,Uniform);                                       \
        hiddenSelectionsTextures[] = {                                              \
            QPATHTOF(data\##var1##\##var2##_camo1_co.paa),                 \
            QPATHTOF(data\##var1##\##var2##_camo2_co.paa),                 \
            QPATHTOF(data\##var1##\##var2##_undersuit_marine_co.paa)       \
        };                                                                          \
    }
