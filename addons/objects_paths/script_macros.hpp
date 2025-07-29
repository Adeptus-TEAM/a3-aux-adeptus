// Class name macro
#define SUBCVAR2(var1,var2) SUBCVAR(DOUBLES(var1,var2))
#define QSUBCVAR2(var1,var2) QUOTE(SUBCVAR2(var1,var2))

/**
 * @name CLASS_OBJECT_1x1
 * @brief Macro to define a 1x1 object class with specific properties.
 * @param var1 Name of the object (e.g., line, turn, arrow).
 * @param var2 Color of the object (e.g., blue, red).
 */
#define CLASS_OBJECT_1x1(var1, var2)                                                        \
    class SUBCVAR2(var1,var2) : UserTexture1m_F {                                           \
        author = AUTHOR;                                                                    \
        CATEGORY_AR;                                                                        \
        SUBCATEGORY_DECALS;                                                                 \
        displayName = SUBCSTRING(DOUBLES(var1,var2));                                       \
        editorPreview = QPATHTOF(data\##var2##\##var1##_ca.paa);                            \
        hiddenSelectionsTextures[] = { QPATHTOF(data\##var2##\##var1##_ca.paa) };           \
        hiddenSelectionsMaterials[] = { ILLUM_MAT };                                        \
        scope = 2;                                                                       \
        scopeCurator = 1;                                                             \
    }

/**
 * @name CLASS_OBJECT_1x2
 * @brief Macro to define a 1x2 object class with specific properties.
 * @param var1 Type of object (e.g., barracks, bridge).
 * @param var2 Color of the object (e.g., blue, red).
 */
#define CLASS_OBJECT_1x2(var1, var2)                                                        \
    class SUBCVAR2(var1,var2) : UserTexture_1x2_F {                                         \
        author = AUTHOR;                                                                    \
        CATEGORY_AR;                                                                        \
        SUBCATEGORY_DECALS;                                                                 \
        displayName = SUBCSTRING(DOUBLES(var1,var2));                                       \
        editorPreview = QPATHTOF(data\##var2##\##var1##_ca.paa);                            \
        hiddenSelectionsTextures[] = { QPATHTOF(data\##var2##\##var1##_ca.paa) };           \
        hiddenSelectionsMaterials[] = { ILLUM_MAT };                                        \
        scope = 2;                                                                       \
        scopeCurator = 1;                                                             \
    }
