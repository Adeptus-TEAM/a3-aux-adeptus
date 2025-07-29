#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Shows the ACE pylons dialog for all vehicles of specified types within the garage area.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call ar_dialogs_garage_fnc_pylonsVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_pylonsVehicle",_this);

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
		[_x] call ace_pylons_fnc_showDialog;
	};
	
} forEach (vehicles inAreaArray [_spawnObjectPos,_areaSize, _areaSize, _spawnObjectDir, true]);
