#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

private _category = [QUOTE(MOD_NAME), QUOTE(COMPONENT_BEAUTIFIED)];

#include "initSettings.inc.sqf"
#include "initKeybinds.inc.sqf"

ADDON = true;

[] call FUNC(initCheckVersion);
[] call FUNC(initFortify);
