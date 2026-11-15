#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description :; This function retrieves the position, direction, and area size for spawning vehicles from the terminal object in the garage dialog. It accesses the terminal and spawn objects from the uiNamespace, checks their validity, and returns the necessary data for vehicle spawning.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * [spawnObjectPosition, spawnObjectDirection, spawnObjectAreaSize] <ARRAY>
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_getTerminalData
 *
 * Public: No
 */

params [];
TRACE_1("fnc_getTerminalData",_this);


// Get the terminal object from the uiNamespace.
private _terminal = uiNamespace getVariable [QGVAR(garageObject), objNull];
if(isNull _terminal) exitWith {
	WARNING("Invalid terminal object");
	[]
};

// Get the terminal's object where vehicles will be spawned from.
private _spawnObject = call compile (_terminal getVariable [QEGVAR(objects,garageSpawnObject), "objNull"]);
if(isNull _spawnObject) exitWith {
	WARNING("Invalid spawn object");
	[]
};

// Get the position, direction and area size for spawning vehicles.
private _pos = getPosATL _spawnObject;
private _dir = getDir _spawnObject;
private _areaSize = parseNumber str (_terminal getVariable [QEGVAR(objects,garageAreaSize), 0]);

// Return the terminal data as an array.
[_pos, _dir, _areaSize]


