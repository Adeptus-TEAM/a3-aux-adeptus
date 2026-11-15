#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Rearms and refuels all vehicles within the garage area.
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

{
	_x setFuel 1;
	_x setVehicleAmmo 1;
} forEach (0 call SUBFUNC(getVehiclesInArea));

true
