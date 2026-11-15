#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Rearms and refuels all vehicles of specified types within the garage area.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * <BOOL>
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_rearmVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_rearmVehicle",_this);

private _terminalData = 0 call SUBFUNC(getTerminalData);
if (_terminalData isEqualTo []) exitWith {
	WARNING("Failed to retrieve terminal data");
	false
};

_terminalData params ["_spawnObjectPos", "_spawnObjectDir", "_areaSize"];

{
	if (!(isNull _x)) then {
		_x setFuel 1;
		_x setVehicleAmmo 1;
	};
} forEach (vehicles inAreaArray [_spawnObjectPos,_areaSize, _areaSize, _spawnObjectDir, true]);

true
