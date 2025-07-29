#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * This function adds an action to the specified terminal object to open the garage dialog.
	 *
	 * Arguments:
	 * 0: _terminal (default: objectNull) <OBJECT>
	 *
	 * Return Value:
	 * None
	 *
	 * Example:
	 * [_terminal] call ar_objects_editor_fnc_addAction
	 *
	 * Public: No
 */

params [
	["_terminal", objNull, [objNull]]
];
TRACE_1("fnc_addAction",_this);

if (is3DEN) exitWith {};

_terminal addAction[
	LSUBLSTRING(terminal),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_target] call EFUNC(dialogs_garage,openInterface);
	},
	nil,
	0,
	true,
	true,
	"",
	"!(isNull _this)",
	3
];
