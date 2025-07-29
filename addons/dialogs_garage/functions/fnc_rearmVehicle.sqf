#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Rearms and refuels all vehicles of specified types within the garage area.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call ar_dialogs_garage_fnc_rearmVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_rearmVehicle",_this);

private _terminalObject = uiNamespace getVariable [QGVAR(garageObject), objNull];

if(isNull _terminalObject)exitWith{
	WARNING("Terminal Object not found");
};

private _spawnObject = (call compile (_terminalObject getVariable[QEGVAR(objects,garageSpawnObject),"objNull"]));
private _areaSize = _terminalObject getVariable[QEGVAR(objects,garageAreaSize),0];
private _listVehicles = uiNamespace getVariable[QGVAR(listVehicles),[]];

if(isNull _spawnObject)exitWith{
	WARNING("Spawn Object not found");
};

private _spawnObjectPos = getPosATL _spawnObject;
private _spawnObjectDir = getDir _spawnObject;

{
	if (!(isNull _x) && ((typeOf _x) in _listVehicles)) then {
		_x setFuel 1;
		_x setVehicleAmmo 1;
	};
	
} forEach (vehicles inAreaArray [_spawnObjectPos,_areaSize, _areaSize, _spawnObjectDir, true]);
