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
 * <BOOL> - true if the area is clear, false if occupied vehicles are still in it
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_deleteVehicle
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_deleteVehicle",_this);

private _isAreaClear = true;
{
	if ((crew _x) findIf {alive _x} != -1) then {
		_isAreaClear = false;
		INFO_1("Kept occupied vehicle: %1",typeOf _x);
	} else {
		INFO_1("Deleted vehicle: %1",typeOf _x);
		deleteVehicle _x;
	};
} forEach (0 call SUBFUNC(getVehiclesInArea));

if (!_isAreaClear) then {
	hint LSUBLSTRING(vehicleOccupied);
};

_isAreaClear
