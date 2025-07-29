#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Checks if the player can build a respawn beacon.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to check if it can build a respawn beacon.
	 *
	 * Return Value:
	 * <BOOL> - Returns true if the unit can build a respawn beacon, false otherwise.
	 *
	 * Example:
	 * [this] call ar_misc_respawnBeacon_fnc_canCreateNew
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

TRACE_1("ar_misc_respawnBeacon_fnc_canCreateNew",_this);

if (is3DEN) exitWith {
	false
};

if (!(QSUBCVAR(item) in (items _unit))) exitWith {
	false
};
if (_unit getVariable [QGVAR(isBuilding), false]) exitWith {
	false
};
if (_unit getUnitTrait 'Engineer' != true) exitWith {
	false
};

true
