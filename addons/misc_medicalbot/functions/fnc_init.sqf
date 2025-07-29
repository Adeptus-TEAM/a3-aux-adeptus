#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to initialize a MedicalBot terminal.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The terminal that will create and control the MedicalBot.
	 * 1: _unit (default: objNull) <OBJECT> - The unit that will be treated by the MedicalBot.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this, bot1] call ar_misc_medicalbot_fnc_init
	 *
	 * Public: Yes
 */

params [
	["_object", objNull, [objNull]],
	["_unit", objNull, [objNull]]
];

TRACE_1("ar_misc_medicalbot_fnc_init",_this);

if (isNull _object) exitWith {
	WARNING("ar_misc_medicalbot_fnc_init: _object is null");
};

if (isNull _unit) then {
	INFO("ar_misc_medicalbot_fnc_init: already initialized");
};

private _unitInit = _object getVariable [QGVAR(medicalBotUnitInit), false];

if (!_unitInit) then {
	[_object, _unit] call SUBFUNC(createNew);
	_object setVariable [QGVAR(medicalBotUnitInit), true, true];
};

_object addAction [
	LSUBLSTRING(addDamageToMedicalBot),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_target] call SUBFUNC(addRandomDamage);
	},
	nil, 0, true, true, "", "true", 3
];

_object addAction [
	LSUBLSTRING(resetMedicalBot),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_target] call SUBFUNC(reset);
	},
	nil, 0, true, true, "", "true", 3
];
