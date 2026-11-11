#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Shows the ACE pylons dialog for all vehicles within the garage area.
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

{
	[_x] call ace_pylons_fnc_showDialog;
} forEach (0 call SUBFUNC(getVehiclesInArea));

true
