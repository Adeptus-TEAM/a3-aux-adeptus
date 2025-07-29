/* Macro for cfgWeapons */

/**
 * @name CLASS_P1STANDARD_NVG
 * @brief Macro pour définir une classe de nvg standard pour la phase 1
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : v1, v2)
 */
#define CLASS_P1STANDARD_NVG(var1,var2)                                         \
    class ECVAR(var2,P1_Standard_NVG) : lsd_gar_P1Standard_nvg {                 \
        author = AUTHOR;                                                        \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P1_Standard_NVG));            \
        picture = QPATHTOEF(characters,data\##var1##\nvg_ca.paa);                           \
        scope = 2;                                                           \
        scopeArsenal = 2;                                                    \
        hiddenSelectionsTextures[] = {                                          \
            QPATHTOF(data\##var1##\##var2##_co.paa)                         \
        };                                                                      \
    }

/**
 * @name CLASS_P1COMMANDER_NVG
 * @brief Macro pour définir une classe de nvg commandant pour la phase 1
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : v1, v2)
 */
#define CLASS_P1COMMANDER_NVG(var1,var2)                                        \
    class ECVAR(var2,P1_Commander_NVG) : lsd_gar_P1Commander_nvg {               \
        author = AUTHOR;                                                        \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P1_Commander_NVG));           \
        picture = QPATHTOEF(characters,data\##var1##\nvg_ccvisor_ca.paa);                   \
        scope = 2;                                                           \
        scopeArsenal = 2;                                                    \
        hiddenSelectionsTextures[] = {                                          \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa),              \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa)               \
        };                                                                      \
    }

/**
 * @name CLASS_P1MARSHALCOMMANDER_NVG
 * @brief Macro pour définir une classe de nvg commandant marshal pour la phase 1
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : v1, v2)
 */
#define CLASS_P1MARSHALCOMMANDER_NVG(var1,var2)                                 \
    class ECVAR(var2,P1_MarshalCommander_NVG) : lsd_gar_P1Commander_nvg {        \
        author = AUTHOR;                                                        \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P1_MarshalCommander_NVG));    \
        picture = QPATHTOEF(characters,data\##var1##\nvg_mcvisor_ca.paa);                   \
        scope = 2;                                                           \
        scopeArsenal = 2;                                                    \
        hiddenSelectionsTextures[] = {                                          \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa),              \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa),              \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa)               \
        };                                                                      \
    }

/**
 * @name CLASS_P2STANDARD_NVG
 * @brief Macro pour définir une classe de nvg standard pour la phase 2
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : v1, v2)
 */
#define CLASS_P2STANDARD_NVG(var1,var2)                                         \
    class ECVAR(var2,P2_Standard_NVG) : lsd_gar_Standard_nvg {                   \
        author = AUTHOR;                                                        \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P2_Standard_NVG));            \
        picture = QPATHTOEF(characters,data\##var1##\nvg_ca.paa);                           \
        scope = 2;                                                           \
        scopeArsenal = 2;                                                    \
        hiddenSelectionsTextures[] = {                                          \
            QPATHTOF(data\##var1##\##var2##_co.paa)                         \
        };                                                                      \
    }

/**
 * @name CLASS_P2COMMANDER_NVG
 * @brief Macro pour définir une classe de nvg commandant pour la phase 2
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : v1, v2)
 */
#define CLASS_P2COMMANDER_NVG(var1,var2)                                        \
    class ECVAR(var2,P2_Commander_NVG) : lsd_gar_P2Commander_nvg {               \
        author = AUTHOR;                                                        \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P2_Commander_NVG));           \
        picture = QPATHTOEF(characters,data\##var1##\nvg_ccvisor_ca.paa);                   \
        scope = 2;                                                           \
        scopeArsenal = 2;                                                    \
        hiddenSelectionsTextures[] = {                                          \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa),              \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa)               \
        };                                                                      \
    }

/**
 * @name CLASS_P2MARSHALCOMMANDER_NVG
 * @brief Macro pour définir une classe de nvg commandant marshal pour la phase 2
 * @param var1 Nom de la faction (regs ou customs)
 * @param var2 Nom de la variante (ex : v1, v2)
 */
#define CLASS_P2MARSHALCOMMANDER_NVG(var1,var2)                                 \
    class ECVAR(var2,P2_MarshalCommander_NVG) : lsd_gar_P2Commander_nvg {        \
        author = AUTHOR;                                                        \
        displayName = SUBCSTRING(TRIPLES(var1,var2,P2_MarshalCommander_NVG));    \
        picture = QPATHTOEF(characters,data\##var1##\nvg_mcvisor_ca.paa);                   \
        scope = 2;                                                           \
        scopeArsenal = 2;                                                    \
        hiddenSelectionsTextures[] = {                                          \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa),              \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa),              \
            QPATHTOF(data\##var1##\##var2##_commander_co.paa)               \
        };                                                                      \
    }
