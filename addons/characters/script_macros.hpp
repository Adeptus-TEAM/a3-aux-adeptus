#define MASS_BACKPACK 50
#define MASS_HELMET 10
#define MASS_UNIFORM 20
#define MASS_VEST 40

#define CONTAINER_UNIFORM SUPPLY_XX(100)
#define CONTAINER_VEST SUPPLY_XX(100)

#define HITPOINTSPROTECTION_HELMET    \
    class HitpointsProtectionInfo {   \
        class Head {                  \
            hitpointName = "HitHead"; \
            armor = 6;                \
            passThrough = 0.5;        \
        };                            \
        class Face {                  \
            hitpointName = "HitFace"; \
            armor = 6;                \
            passThrough = 0.5;        \
        };                            \
    }

#define HITPOINTSPROTECTION_VEST           \
    class HitpointsProtectionInfo {        \
        class Chest {                      \
            hitpointName = "HitChest";     \
            armor = 12;                    \
            passThrough = 0.1;             \
        };                                 \
        class Diaphragm {                  \
            hitpointName = "HitDiaphragm"; \
            armor = 8;                     \
            passThrough = 0.2;             \
        };                                 \
        class Abdomen {                    \
            hitpointName = "HitAbdomen";   \
            armor = 8;                     \
            passThrough = 0.2;             \
        };                                 \
        class Body {                       \
            hitpointName = "HitBody";      \
            armor = 8;                     \
            passThrough = 0.2;             \
        };                                 \
        class Legs {                       \
            hitpointName = "HitLegs";      \
            armor = 10;                    \
            passThrough = 0.3;             \
        };                                 \
        class Arms {                       \
            hitpointName = "HitArms";      \
            armor = 10;                    \
            passThrough = 0.3;             \
        };                                 \
        class Neck {                       \
            hitpointName = "HitNeck";      \
            armor = 6;                     \
            passThrough = 0.5;             \
        };                                 \
    }

#define CLASS_INHERITANCE(var1) \
    class var1;                 \
    class var1##_base : var1 {  \
        scope = 0;              \
        scopeArsenal = 0;       \
        class ItemInfo;         \
    }
