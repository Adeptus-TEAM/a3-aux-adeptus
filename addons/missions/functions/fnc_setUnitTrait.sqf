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

private _level = 0; // default level for specialists
if (_isSpecialist) then {
	_level = 2; // set level to 2 if the unit is a specialist
};

// Assign the specialist role based on the provided _specToAssign parameter
switch (_specToAssign) do {
	case "medic" : {
		_unit setVariable ["ace_medical_medicclass", _level, true];
		_unit setUnitTrait ["Medic", _isSpecialist];
	};
	case "engineer" : {
		_unit setVariable ["ace_isEngineer", _level, true];
		_unit setUnitTrait ["Engineer", _isSpecialist];
		_unit setVariable ["ace_isExplosiveSpecialist", _isSpecialist, true];
		_unit setUnitTrait ["ExplosiveSpecialist", _isSpecialist];
	};
	case "eod" : {
		_unit setVariable ["ace_isExplosiveSpecialist", _isSpecialist, true];
		_unit setUnitTrait ["ExplosiveSpecialist", _isSpecialist];
	};
	case "all" : {
		_unit setVariable ["ace_medical_medicclass", _level, true];
		_unit setUnitTrait ["Medic", _isSpecialist];
		_unit setVariable ["ace_isEngineer", _level, true];
		_unit setUnitTrait ["Engineer", _isSpecialist];
		_unit setVariable ["ace_isExplosiveSpecialist", _isSpecialist, true];
		_unit setUnitTrait ["ExplosiveSpecialist", _isSpecialist];
	};
	default {
		INFO_1("fnc_setUnitTrait - Unknown specialist role: %1",_specToAssign);
	};
};
