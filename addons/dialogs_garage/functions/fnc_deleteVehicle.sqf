#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description : Deletes all empty vehicles within the garage area.
 *               Vehicles with a living crew are kept, so nobody gets deleted with their vehicle.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <BOOL> - true if the area is clear, false if occupied vehicles are still in it (or no terminal data)
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

private _isAreaClear = true;
{
	if ((crew _x) findIf {alive _x} != -1) then {
		_isAreaClear = false;
		INFO_1("Kept occupied vehicle: %1",typeOf _x);
	} else {
		INFO_1("Deleted vehicle: %1",typeOf _x);
		deleteVehicle _x;
	};
} forEach (vehicles inAreaArray [_spawnObjectPos,_areaSize, _areaSize, _spawnObjectDir, true]);

if (!_isAreaClear) then {
	hint LSUBLSTRING(vehicleOccupied);
};

_isAreaClear
