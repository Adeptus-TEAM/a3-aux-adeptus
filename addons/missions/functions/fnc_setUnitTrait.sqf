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
	params ["_unit", "_isSpecialist", "_lvl"];
	_unit setVariable ["ace_medical_medicclass", _lvl, true];
	_unit setUnitTrait ["Medic", _isSpecialist];
};

private _eod = { // Define the EOD trait
	params ["_unit", "_isSpecialist"];
	_unit setVariable ["ace_isExplosiveSpecialist", _isSpecialist, true];
	_unit setUnitTrait ["ExplosiveSpecialist", _isSpecialist];
};

private _engineer = { // Define the engineer role and its traits
	params ["_unit", "_isSpecialist", "_lvl"];
	_unit setVariable ["ace_isEngineer", _lvl, true];
	_unit setUnitTrait ["Engineer", _isSpecialist];
};

if (_specToAssign isNotEqualTo "") then { // If a specific specialist role is provided, assign it directly
	private _lvl = 2; // default level for specialists
	if (!_isSpecialist) then {
		_lvl = 0; // if not a specialist, set level to 0
	};

	// Assign the specialist role based on the provided _specToAssign parameter
	switch (_specToAssign) do {
		case "medic" : {
			[_unit, _isSpecialist, _lvl] call _medical;
		};
		case "engineer" : {
			[_unit, _isSpecialist, _lvl] call _engineer;
			[_unit, _isSpecialist] call _eod; // EOD trait is also assigned for engineers
		};
		case "eod" : {
			[_unit, _isSpecialist] call _eod;
		};
		case "all" : {
			[_unit, _isSpecialist, _lvl] call _medical;
			[_unit, _isSpecialist, _lvl] call _engineer;
			[_unit, _isSpecialist] call _eod;
		};
		default {
			INFO_1("fnc_setUnitTrait - Unknown specialist role: %1",_specToAssign);
		};
	};
} else { // If no specific specialist role is provided, check the player's UID against the mission config lists
	private _playerUID = getPlayerUID _unit;

	// Get the specialist lists from the mission config
	private _medicalSpecialistListUID = getMissionConfigValue [QGVAR(medicList), []]; // List of UIDs for medical specialists from ar_missions_medicList in description.ext
	private _engineerSpecialistListUID = getMissionConfigValue [QGVAR(engineerList), []]; // List of UIDs for engineer specialists from ar_missions_engineerList in description.ext
	private _eodSpecialistListUID = getMissionConfigValue [QGVAR(eodList), []]; // List of UIDs for EOD specialists from ar_missions_eodList in description.ext

	// Check the player's UID against the specialist lists and assign the appropriate traits
	switch (true) do {
		case (_playerUID in _medicalSpecialistListUID) : {
			[_unit, true, 2] call _medical;
		};
		case (_playerUID in _engineerSpecialistListUID) : {
			[_unit, true, 2] call _engineer;
			[_unit, true] call _eod; // EOD trait is also assigned for engineers
		};
		case (_playerUID in _eodSpecialistListUID) : {
			[_unit, true] call _eod;
		};
		default { }; // No action if the player is not in any specialist list
	};
};
