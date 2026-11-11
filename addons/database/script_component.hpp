#define COMPONENT database
#define COMPONENT_BEAUTIFIED Database
#include "\x\ar\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define ENABLE_PERFORMANCE_COUNTERS

#include "\x\ar\addons\main\script_macros.hpp"

// extDB3 : nom de l'extension, section [adeptus] de extdb3-conf.ini, protocole SQL_CUSTOM
#define EXTDB "extDB3"
#define DB_NAME "adeptus"
#define DB_PROTOCOL "ar"
#define DB_SQL_FILE "adeptus.ini"

// Sauvegarde : délai avant écriture après un changement (laisse le temps à l'équipement de se synchroniser),
// et sauvegarde périodique de secours
#define SAVE_DELAY 3
#define SAVE_INTERVAL 300
