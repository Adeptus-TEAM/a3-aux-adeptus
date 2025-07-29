#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to reset the MedicalBot.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The terminal that controls the MedicalBot.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_misc_medicalbot_fnc_reset
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("ar_misc_medicalbot_fnc_reset",_this);

private _unit = _object getVariable [QGVAR(MedicalBotUnit), objNull];

[_object, _unit] call SUBFUNC(createNew);
