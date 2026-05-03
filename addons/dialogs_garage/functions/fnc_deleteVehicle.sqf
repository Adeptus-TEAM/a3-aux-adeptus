#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description : Deletes all vehicles of specified types within the garage area.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <BOOL>
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_deleteVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_deleteVehicle",_this);

private _terminalData = 0 call SUBFUNC(getTerminalData);
if (_terminalData isEqualTo []) exitWith {
	WARNING("Failed to retrieve terminal data");
	false
};

_terminalData params ["_spawnObjectPos", "_spawnObjectDir", "_areaSize"];

{
	deleteVehicle _x;
	INFO("Deleted vehicle: " + typeOf _x);
} forEach (vehicles inAreaArray [_spawnObjectPos,_areaSize, _areaSize, _spawnObjectDir, true]);

true
