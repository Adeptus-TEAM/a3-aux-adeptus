#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Shows the ACE pylons dialog for all vehicles of specified types within the garage area.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * <BOOL>
 *
 * Example:
 * [] call ar_dialogs_garage_fnc_pylonsVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_pylonsVehicle",_this);

private _terminalData = 0 call SUBFUNC(getTerminalData);
if (_terminalData isEqualTo []) exitWith {
	WARNING("Failed to retrieve terminal data");
	false
};

_terminalData params ["_spawnObjectPos", "_spawnObjectDir", "_areaSize"];

{
	if (!(isNull _x)) then {
		[_x] call ace_pylons_fnc_showDialog;
	};
	
} forEach (vehicles inAreaArray [_spawnObjectPos,_areaSize, _areaSize, _spawnObjectDir, true]);

true
