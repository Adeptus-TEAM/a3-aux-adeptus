#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to add damage to the MedicalBot.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The terminal that controls the MedicalBot.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_misc_medicalbot_fnc_addRandomDamage
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("ar_misc_medicalbot_fnc_addRandomDamage",_this);

if (isNull _object) exitWith {
	WARNING("ar_misc_medicalbot_fnc_addRandomDamage: _object is null");
};

private _unit = _object getVariable [QGVAR(MedicalBotUnit), objNull];

private _qttOfEffects = floor (random 20) + 1;

for "_i" from 1 to _qttOfEffects do {
	private _severity = random 1;
	private _bodyPart = selectRandom ["Head", "Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"];
	private _damageType = selectRandom ["backblast", "bite", "bullet", "explosive", "falling", "grenade", "punch", "ropeburn", "shell", "stab", "unknown", "vehiclecrash"];

	[_unit, _severity, _bodyPart, _damageType] call ace_medical_fnc_addDamageToUnit;
};
