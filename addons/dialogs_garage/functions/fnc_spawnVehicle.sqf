#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Spawns a selected vehicle at the designated spawn location in the garage dialog.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * <BOOL>
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_spawnVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_spawnVehicle",_this);

private _terminalData = 0 call SUBFUNC(getTerminalData);
if (_terminalData isEqualTo []) exitWith {
	WARNING("Failed to retrieve terminal data");
	false
};

_terminalData params ["_spawnObjectPos", "_spawnObjectDir", "_areaSize"];

// Get selected vehicle class from UI variables
private _selectedIndex = uiNamespace getVariable[QGVAR(selectionCounter),0];
private _listVehicles = uiNamespace getVariable[QGVAR(listVehicles),[]];

if (_selectedIndex >= count _listVehicles) exitWith {
	WARNING("Index out of bounds");
	false;
};

private _vehicleClass = _listVehicles select _selectedIndex;

// Delete existing vehicles in the spawn area before spawning a new one
0 call SUBFUNC(deleteVehicle);

[
	{
		params["_vehicleClass","_spawnObjectPos","_spawnObjectDir"];
		private _vehicle = createVehicle [_vehicleClass,_spawnObjectPos,[],0,"NONE"];
		_vehicle setPosATL _spawnObjectPos;
		_vehicle setDir _spawnObjectDir;
	},
	[_vehicleClass,_spawnObjectPos,_spawnObjectDir],
	0.5
] call CBA_fnc_waitAndExecute;

true
