#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to add a action to the loadout dialog.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The object to which the action will be added.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_dialogs_loadout_fnc_addaction
	 *
	 * Public: Yes
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("ar_dialogs_loadout_fnc_addaction",_this);

if (isNull _object) exitWith {
	WARNING("ar_dialogs_loadout_fnc_addaction: No object provided");
};

_object addAction [
	LSUBLSTRING(openMenu), {
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_caller, _target] call SUBFUNC(openInterface);
	},
nil, 0, true, true, "", "true", 5];
