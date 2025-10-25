#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to add actions for activating or deactivating unit traits.
	 *
	 * Arguments:
	 * 0: _obj (default: objNull) <OBJECT> - The object to which the actions will be added.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_objects_editor_fnc_addActionUnitTrait
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

if (is3DEN) exitWith {};

TRACE_1("ar_objects_editor_fnc_addActionUnitTrait",_object);

_object addAction [
	LLSTRING(ActivateTraitMedic),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_caller, "medic", true] call EFUNC(missions,setUnitTrait);
	}, nil, 1.5, false, false, "", QUOTE(!(_this getUnitTrait 'Medic'))
];

_object addAction [
	LLSTRING(DeactivateTraitMedic),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_caller, "medic", false] call EFUNC(missions,setUnitTrait);
	}, nil, 1.5, false, false, "", QUOTE(_this getUnitTrait 'Medic')
];

_object addAction [
	LLSTRING(ActivateTraitEngineer),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_caller, "engineer", true] call EFUNC(missions,setUnitTrait);
	}, nil, 1.5, false, false, "", QUOTE(!(_this getUnitTrait 'Engineer'))
];

_object addAction [
	LLSTRING(DeactivateTraitEngineer),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_caller, "engineer", false] call EFUNC(missions,setUnitTrait);
	}, nil, 1.5, false, false, "", QUOTE(_this getUnitTrait 'Engineer')
];

_object addAction [
	LLSTRING(ActivateTraitExplosiveSpecialist),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_caller, "eod", true] call EFUNC(missions,setUnitTrait);
	}, nil, 1.5, false, false, "", QUOTE(!(_this getUnitTrait 'ExplosiveSpecialist'))
];

_object addAction [
	LLSTRING(DeactivateTraitExplosiveSpecialist),
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		[_caller, "eod", false] call EFUNC(missions,setUnitTrait);
	}, nil, 1.5, false, false, "", QUOTE(_this getUnitTrait 'ExplosiveSpecialist')
];
