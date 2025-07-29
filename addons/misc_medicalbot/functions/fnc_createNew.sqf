#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to create a new MedicalBot.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The terminal that will create and control the MedicalBot.
	 * 1: _unit (default: objNull) <OBJECT> - The unit that will be replaced by the MedicalBot.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_misc_medicalbot_fnc_createNew
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]],
	["_unit", objNull, [objNull]]
];

TRACE_1("ar_misc_medicalbot_fnc_createNew",_this);

if (isNull _object || isNull _unit) exitWith {
	WARNING("ar_misc_medicalbot_fnc_createNew: _object or _unit is null");
};

private _pos = getPosATL _unit;
private _dir = getDir _unit;
private _name = name _unit;
private _loadout = getUnitLoadout _unit;

deleteVehicle _unit;

private _newgroup = createGroup civilian;
private _medicalBot = _newgroup createUnit ["B_Soldier_VR_F", _pos, [], 0, "CAN_COLLIDE"];
_medicalBot setPosATL _pos;
_medicalBot setDir _dir;
_medicalBot setUnitLoadout _loadout;
_medicalBot setName _name;
_medicalBot enableSimulationGlobal false;

_object setVariable [QGVAR(MedicalBotUnit), _medicalBot, true];

[_medicalBot, true, 99999, false] remoteExecCall ["ace_medical_fnc_setUnconscious", 0, true];
[_medicalBot, "UnconsciousReviveArms"] remoteExecCall ["switchMove", 0, true];
