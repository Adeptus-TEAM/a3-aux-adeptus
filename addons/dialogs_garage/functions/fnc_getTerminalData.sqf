#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Retrieves the spawn position, direction and area of the garage
 *              from the garage module linked to the currently opened terminal.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * [spawnPosATL, spawnDir, sizeA, sizeB, isRectangle, height, spawnPosASL] <ARRAY> - [] on error
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_getTerminalData
 *
 * Public: No
 */

params [];
TRACE_1("fnc_getTerminalData",_this);

// Terminal currently in use (set by openInterface).
private _terminal = uiNamespace getVariable [QGVAR(garageObject), objNull];
if (isNull _terminal) exitWith {
	WARNING("Invalid terminal object");
	[]
};

// Garage module linked to the terminal (set by fnc_moduleGarageSpawn).
private _module = _terminal getVariable [QGVAR(garageModule), objNull];
if (isNull _module) exitWith {
	WARNING_1("Terminal %1 is not linked to any garage module",_terminal);
	[]
};

// Position and direction: taken from the module.
private _pos = getPosATL _module;
private _dir = getDir _module;

// Area: as set on the module in the editor.
// objectArea = [halfWidth, halfLength, angle, isRectangle, height]
private _objectArea = _module getVariable ["objectArea", []];
if (_objectArea isEqualTo []) then {
	WARNING_1("Garage module %1 has no area, using default size",_module);
	_objectArea = [10, 10, _dir, true, 5];
};
_objectArea params ["_sizeA", "_sizeB", "", "_isRectangle", "_height"];

// Never allow an unlimited height (-1), it would catch aircraft flying over the garage.
if (_height < 0) then { _height = 5 };

[_pos, _dir, _sizeA, _sizeB, _isRectangle, _height, getPosASL _module]
