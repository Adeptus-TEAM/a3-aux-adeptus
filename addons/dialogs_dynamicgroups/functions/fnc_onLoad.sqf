#include "..\script_component.hpp"
/*
 * Authors: Archer
 * The load script of the dialogs_dynamicsGroups overwrite
 *
 * Arguments:
 * 0: _display (default: displayNull) <DISPLAY>
 *
 * Return Value:
 * Return description <NONE>
 *
 * Example:
 * [_this] call ar_missions_fnc_onLoad
 *
 * Public: No
 */

params [
	["_display", displayNull ,[ displayNull ]]
];
TRACE_1("fnc_onLoad",_this);

private _availableInsignias = (configFile >> "CfgUnitInsignia") call BIS_fnc_getCfgSubClasses;
uiNamespace setVariable [QGVAR(availableInsignia),_availableInsignias];
