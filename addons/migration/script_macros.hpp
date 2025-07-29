#define OBSOLETE_CPARMS                       \
    displayName = CSTRING(obsolete);          \
    picture = QPATHTOF(data\obsolete_ca.paa); \
    scope = 1;                          \
    scopeCurator = 1;                   \
    scopeArsenal = 1

#define CLASS_OBSOLETE(var1,var2)  \
    class var2;                    \
    class var1 : var2 {            \
        OBSOLETE_CPARMS;           \
    }
