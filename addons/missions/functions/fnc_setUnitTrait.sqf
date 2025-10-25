#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Assigns a specialist role to a unit.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to assign the specialist role to.
	 * 1: _specToAssign (optionnal, default: "") <STRING> - The specialist role to assign. Can be "medic", "engineer", or "eod".
	 * 2: _isSpecialist (optionnal, default: true) <BOOL> - Whether the unit is a specialist or not.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * for init : [player] call ar_missions_fnc_setUnitTrait
	 * for change : [player, "medic", true] call ar_missions_fnc_setUnitTrait
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]],
	["_specToAssign", "", [""]],
	["_isSpecialist", true, [true]]
];

TRACE_3("fnc_setUnitTrait",_unit,_specToAssign,_isSpecialist);

// Define the specialist roles and their traits
private _medical = { // Define the medical trait
	params ["_unit", "_bool", "_lvl"];
	_unit setVariable ["ace_medical_medicclass", _lvl, true];
	_unit setUnitTrait ["Medic", _bool];
};

private _eod = { // Define the EOD trait
	params ["_unit", "_bool"];
	_unit setVariable ["ace_isExplosiveSpecialist", _bool, true];
	_unit setUnitTrait ["ExplosiveSpecialist", _bool];
};

private _engineer = { // Define the engineer role and its traits
	params ["_unit", "_bool", "_lvl"];
	_unit setVariable ["ace_isEngineer", _lvl, true];
	_unit setUnitTrait ["Engineer", _bool];
};

private _level = 0; // default level for specialists
if (_isSpecialist) then {
	_level = 2; // set level to 2 if the unit is a specialist
};

// Assign the specialist role based on the provided _specToAssign parameter
switch (_specToAssign) do {
	case "medic" : {
		[_unit, _isSpecialist, _level] call _medical;
	};
	case "engineer" : {
		[_unit, _isSpecialist, _level] call _engineer;
		[_unit, _isSpecialist] call _eod; // EOD trait is also assigned for engineers
	};
	case "eod" : {
		[_unit, _isSpecialist] call _eod;
	};
	case "all" : {
		[_unit, _isSpecialist, _level] call _medical;
		[_unit, _isSpecialist, _level] call _engineer;
		[_unit, _isSpecialist] call _eod;
	};
	default {
		INFO_1("fnc_setUnitTrait - Unknown specialist role: %1",_specToAssign);
	};
};
