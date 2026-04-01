#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Adds a limited arsenal to a crate.
	 *
	 * Arguments:
	 * 0: _crate (default: objNull) <OBJECT> - The object to which the arsenal will be added.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_objects_editor_fnc_addLimitedArsenal
	 *
	 * Public: No
 */

params [
	["_crate", objNull, [objNull]]
];

if (is3DEN) exitWith {};

TRACE_1("ar_objects_editor_fnc_addLimitedArsenal",_this);

// Initialize the arsenal on the crate
["AmmoboxInit", [_crate, false, {
	_this distance _target < 5 // Check if the player is close enough
}]] call BIS_fnc_arsenal;

// Populate with predefined items and whatever is already in the crate
[_crate, ["%ALL"]] call BIS_fnc_addVirtualBackpackCargo;

[_crate, ["%ALL"]] call BIS_fnc_addVirtualItemCargo;

[_crate, ["%ALL"]] call BIS_fnc_addVirtualMagazineCargo;

private _allowedWeapons = getMissionConfigValue QEGVAR(missions,allowedWeapons);

if (_allowedWeapons isNotEqualTo []) then {
	[_crate, _allowedWeapons] call BIS_fnc_addVirtualWeaponCargo;
} else {
	[_crate, ["%ALL"]] call BIS_fnc_addVirtualWeaponCargo;
};
