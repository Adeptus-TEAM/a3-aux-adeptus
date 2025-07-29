#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Spawns a selected vehicle at the designated spawn location in the garage dialog.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call ar_dialogs_garage_fnc_spawnVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_spawnVehicle",_this);

private _terminalObject = uiNamespace getVariable [QGVAR(garageObject), objNull];

if(isNull _terminalObject)exitWith{
	WARNING("Terminal Object not found");
};
private _spawnObject = call (compile (_terminalObject getVariable[QEGVAR(objects,garageSpawnObject),"objNull"]));
private _counter = uiNamespace getVariable[QGVAR(selectionCounter),0];
private _listVehicles = uiNamespace getVariable[QGVAR(listVehicles),[]];

if(isNull _spawnObject)exitWith{
	WARNING("Spawn Object not found");
};

private _vehicleClass = _listVehicles select _counter;
private _spawnObjectPos = getPosATL _spawnObject;
private _spawnObjectDir = getDir _spawnObject;

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
