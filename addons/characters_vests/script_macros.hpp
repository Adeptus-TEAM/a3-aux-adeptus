/* Macro for cfgWeapons */

/**
 * @name CLASS_ARF_VEST
 * @brief Macro pour définir une classe de gilet ARF (Advanced Recon Force).
 *        Textures requises : Light, Heavy, Officer.
 * @param var1 Nom de la faction (Regs ou Customs)
 * @param var2 Nom de la variante (ex : V1, V2)
 */
#define CLASS_ARF_VEST(var1,var2)                                                                                      \
    class ECVAR(var2,ARF_Vest) : ls_gar_arf_vest_base {                                                                     \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,arf_vest));                                                         \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\arf\##var2##_light_accessories_co.paa),                                       \
            QPATHTOF(data\##var1##\arf\##var2##_heavy_accessories_co.paa),                                       \
            QPATHTOF(data\##var1##\arf\##var2##_officer_accessories_co.paa)                                      \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_ENGINEER_VEST
 * @brief Macro pour définir une classe de gilet Engineer.
 *        Textures requises : Light, Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_ENGINEER_VEST(var1,var2)                                                                                 \
    class ECVAR(var2,Engineer_Vest) : ls_gar_engineer_vest_base {                                                           \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,engineer_vest));                                                    \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\engineer\##var2##_light_accessories_co.paa),                                  \
            QPATHTOF(data\##var1##\engineer\##var2##_heavy_accessories_co.paa)                                   \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_ENGINEERNCO_VEST
 * @brief Macro pour définir une classe de gilet Engineer NCO.
 *        Textures requises : Light, Heavy, Officer, ARC.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_ENGINEERNCO_VEST(var1,var2)                                                                              \
    class ECVAR(var2,EngineerNCO_Vest) : ls_gar_engineerNCO_vest_base {                                                     \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,engineerNCO_vest));                                                 \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\engineerNCO\##var2##_light_accessories_co.paa),                               \
            QPATHTOF(data\##var1##\engineerNCO\##var2##_heavy_accessories_co.paa),                               \
            QPATHTOF(data\##var1##\engineerNCO\##var2##_officer_accessories_co.paa),                             \
            QPATHTOF(data\##var1##\engineerNCO\##var2##_heavy_accessories_co.paa),                               \
            "",                                                                                                        \
            QPATHTOF(data\##var1##\engineerNCO\##var2##_arc_accessories_co.paa)                                  \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_FORCERECONNCO_VEST
 * @brief Macro pour définir une classe de gilet Force Recon NCO.
 *        Textures requises : Light, Officer, Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_FORCERECONNCO_VEST(var1,var2)                                                                            \
    class ECVAR(var2,ForceReconNCO_Vest) : ls_gar_forceReconNCO_vest_base {                                                 \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,forceReconNCO_vest));                                               \
        picture = QPATHTOEF(characters,data\##var1##\vest_kama_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\forceReconNCO\##var2##_light_accessories_co.paa),                             \
            QPATHTOF(data\##var1##\forceReconNCO\##var2##_officer_accessories_co.paa),                           \
            QPATHTOF(data\##var1##\forceReconNCO\##var2##_heavy_accessories_co.paa)                              \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_HAZARD_VEST
 * @brief Macro pour définir une classe de gilet Hazard.
 *        Textures requises : Light, Officer.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_HAZARD_VEST(var1,var2)                                                                                   \
    class ECVAR(var2,Hazard_Vest) : ls_gar_hazard_vest_base {                                                               \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,hazard_vest));                                                      \
        picture = QPATHTOEF(characters,data\##var1##\vest_kama_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\hazard\##var2##_light_accessories_co.paa),                                    \
            QPATHTOF(data\##var1##\hazard\##var2##_officer_accessories_co.paa)                                   \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_HEAVY_VEST
 * @brief Macro pour définir une classe de gilet Heavy.
 *        Textures requises : Heavy, Light.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_HEAVY_VEST(var1,var2)                                                                                    \
    class ECVAR(var2,Heavy_Vest) : ls_gar_heavy_vest_base {                                                                 \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,heavy_vest));                                                       \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\heavy\##var2##_heavy_accessories_co.paa),                                     \
            QPATHTOF(data\##var1##\heavy\##var2##_heavy_accessories_co.paa),                                     \
            QPATHTOF(data\##var1##\heavy\##var2##_heavy_accessories_co.paa),                                     \
            QPATHTOF(data\##var1##\heavy\##var2##_light_accessories_co.paa),                                     \
            QPATHTOF(data\##var1##\heavy\##var2##_heavy_accessories_co.paa)                                      \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_ARC_VEST
 * @brief Macro pour définir une classe de gilet ARC.
 *        Textures requises : ARC, Officer.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_ARC_VEST(var1,var2)                                                                                      \
    class ECVAR(var2,ARC_Vest) : ls_gar_arc_vest_base {                                                                     \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,arc_vest));                                                         \
        picture = QPATHTOEF(characters,data\##var1##\vest_officer_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\arc\##var2##_arc_accessories_co.paa),                                         \
            QPATHTOF(data\##var1##\arc\##var2##_officer_accessories_co.paa)                                      \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_ARCPLATE_VEST
 * @brief Macro pour définir une classe de gilet ARC.
 *        Textures requises : ARC
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_ARCPLATE_VEST(var1,var2)                                                                                 \
    class ECVAR(var2,ARC_Plate_Vest) : ls_gar_arc_vest_base {                                                               \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,arc_plate_vest));                                                   \
        picture = QPATHTOEF(characters,data\##var1##\vest_officer_ca.paa);                                                         \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\arcPlate\##var2##_arc_accessories_co.paa),                                    \
            ""                                                                                                         \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_ASSAULT_VEST
 * @brief Macro pour définir une classe de gilet Assault.
 *        Textures requises : Light, Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_ASSAULT_VEST(var1,var2)                                                                                  \
    class ECVAR(var2,Assault_Vest) : ls_gar_assault_vest_base {                                                             \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,assault_vest));                                                     \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\assault\##var2##_light_accessories_co.paa),                                   \
            QPATHTOF(data\##var1##\assault\##var2##_heavy_accessories_co.paa)                                    \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_CLONE_VEST
 * @brief Macro pour définir une classe de gilet Clone.
 *        Textures requises : aucune.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_CLONE_VEST(var1,var2)                                                                                    \
    class ECVAR(var2,Clone_Vest) : ls_gar_clone_vest_base {                                                                 \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,clone_vest));                                                       \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {};                                                                               \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_CFR_VEST
 * @brief Macro pour définir une classe de gilet CFR.
 *        Textures requises : Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_CFR_VEST(var1,var2)                                                                                      \
    class ECVAR(var2,CFR_Vest) : ls_gar_cfr_vest_base {                                                                     \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,cfr_vest));                                                         \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\cfr\##var2##_heavy_accessories_co.paa)                                        \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_COMMANDER_VEST
 * @brief Macro pour définir une classe de gilet Commander.
 *        Textures requises : Officer.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_COMMANDER_VEST(var1,var2)                                                                                \
    class ECVAR(var2,Commander_Vest) : ls_gar_commander_vest_base {                                                         \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,commander_vest));                                                   \
        picture = QPATHTOEF(characters,data\##var1##\vest_officer_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\commander\##var2##_officer_accessories_co.paa)                                \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_GRENADIER_VEST
 * @brief Macro pour définir une classe de gilet Grenadier.
 *        Textures requises : Light, Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_GRENADIER_VEST(var1,var2)                                                                                \
    class ECVAR(var2,Grenadier_Vest) : ls_gar_grenadier_vest_base {                                                         \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,grenadier_vest));                                                   \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\grenadier\##var2##_light_accessories_co.paa),                                 \
            QPATHTOF(data\##var1##\grenadier\##var2##_heavy_accessories_co.paa)                                  \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_KAMA_VEST
 * @brief Macro pour définir une classe de gilet Kama.
 *        Textures requises : Officer.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_KAMA_VEST(var1,var2)                                                                                     \
    class ECVAR(var2,Kama_Vest) : ls_gar_kama_vest_base {                                                                   \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,kama_vest));                                                        \
        picture = QPATHTOEF(characters,data\##var1##\vest_kama_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\kama\##var2##_officer_accessories_co.paa)                                     \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_LIEUTENANT_VEST
 * @brief Macro pour définir une classe de gilet Lieutenant.
 *        Textures requises : Officer.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_LIEUTENANT_VEST(var1,var2)                                                                               \
    class ECVAR(var2,Lieutenant_Vest) : ls_gar_lieutenant_vest_base {                                                       \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,lieutenant_vest));                                                  \
        picture = QPATHTOEF(characters,data\##var1##\vest_officer_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\lieutenant\##var2##_officer_accessories_co.paa)                               \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_MEDIC_VEST
 * @brief Macro pour définir une classe de gilet Medic.
 *        Textures requises : Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_MEDIC_VEST(var1,var2)                                                                                    \
    class ECVAR(var2,Medic_Vest) : ls_gar_medic_vest_base {                                                                 \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,medic_vest));                                                       \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\medic\##var2##_heavy_accessories_co.paa)                                      \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_OFFICER_VEST
 * @brief Macro pour définir une classe de gilet Officer.
 *        Textures requises : Officer.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_OFFICER_VEST(var1,var2)                                                                                  \
    class ECVAR(var2,Officer_Vest) : ls_gar_officer_vest_base {                                                             \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,officer_vest));                                                     \
        picture = QPATHTOEF(characters,data\##var1##\vest_officer_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\officer\##var2##_officer_accessories_co.paa)                                  \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_RECON_VEST
 * @brief Macro pour définir une classe de gilet Recon.
 *        Textures requises : Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_RECON_VEST(var1,var2)                                                                                    \
    class ECVAR(var2,Recon_Vest) : ls_gar_recon_vest_base {                                                                 \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,recon_vest));                                                       \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\recon\##var2##_heavy_accessories_co.paa),                                     \
            QPATHTOF(data\##var1##\recon\##var2##_heavy_accessories_co.paa)                                      \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_RECONNCO_VEST
 * @brief Macro pour définir une classe de gilet Recon NCO.
 *        Textures requises : Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_RECONNCO_VEST(var1,var2)                                                                                 \
    class ECVAR(var2,ReconNCO_Vest) : ls_gar_reconNCO_vest_base {                                                           \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,reconNCO_vest));                                                    \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\reconNCO\##var2##_heavy_accessories_co.paa),                                  \
            QPATHTOF(data\##var1##\reconNCO\##var2##_heavy_accessories_co.paa),                                  \
            QPATHTOF(data\##var1##\reconNCO\##var2##_heavy_accessories_co.paa)                                   \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }

/**
 * @name CLASS_SPECIALIST_VEST
 * @brief Macro pour définir une classe de gilet Specialist.
 *        Textures requises : Light, Heavy.
 * @param var1 Nom de la faction
 * @param var2 Nom de la variante
 */
#define CLASS_SPECIALIST_VEST(var1,var2)                                                                               \
    class ECVAR(var2,Specialist_Vest) : ls_gar_specialist_vest_base {                                                       \
        author = AUTHOR;                                                                                               \
        displayName = SUBCSTRING(TRIPLES(var1,var2,specialist_vest));                                                  \
        picture = QPATHTOEF(characters,data\##var1##\vest_ca.paa);                                                                 \
        scope = 2;                                                                                                  \
        scopeArsenal = 2;                                                                                           \
        hiddenSelectionsTextures[] = {                                                                                 \
            QPATHTOF(data\##var1##\specialist\##var2##_light_accessories_co.paa),                                \
            QPATHTOF(data\##var1##\specialist\##var2##_heavy_accessories_co.paa)                                 \
        };                                                                                                             \
        class ItemInfo : ItemInfo {                                                                                    \
            mass = MASS_VEST;                                                                                          \
            HITPOINTSPROTECTION_VEST;                                                                                  \
        };                                                                                                             \
    }
