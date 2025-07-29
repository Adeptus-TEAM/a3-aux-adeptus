#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description : Deletes all vehicles of specified types within the garage area.
 *
 * Arguments:
 * 0: Argument (optional, default: value) <OBJECT>
 *
 * Return Value:
 * Return description <NONE>
 *
 * Example:
 * [params] call ar_dialogs_garage_fnc_deleteVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_deleteVehicle",_this);
private _terminalObject = uiNamespace getVariable [QGVAR(garageObject), objNull];

if(isNull _terminalObject)exitWith{
	WARNING("Terminal Object not found");
};

private _spawnObject = (call (compile (_terminalObject getVariable[QEGVAR(objects,garageSpawnObject),"objNull"])));
private _areaSize = _terminalObject getVariable[QEGVAR(objects,garageAreaSize),0];
private _listVehicles = uiNamespace getVariable[QGVAR(listVehicles),[]];

if(isNull _spawnObject)exitWith{
	WARNING("Spawn Object not found");
};

private _spawnObjectPos = getPosATL _spawnObject;
private _spawnObjectDir = getDir _spawnObject;

{
	if((typeOf _x) in _listVehicles)then{
		deleteVehicle _x;
	};
	
} forEach (vehicles inAreaArray [_spawnObjectPos,_areaSize, _areaSize, _spawnObjectDir, true]);

