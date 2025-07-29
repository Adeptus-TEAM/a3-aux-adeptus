#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to open the loadout dialog.
	 *
	 * Arguments:
	 * 0: _caller (default: objNull) <OBJECT> - The object that called the function.
	 * 1: _target (default: objNull) <OBJECT> - The target object for the action.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [_caller, _target] call ar_dialogs_loadout_fnc_openInterface
	 *
	 * Public: No
 */

params [
	["_caller", objNull, [objNull]],
	["_target", objNull, [objNull]]
];

TRACE_1("ar_dialogs_loadout_fnc_openInterface",_this);

if (isNull _caller || isNull _target) exitWith {
	WARNING("ar_dialogs_loadout_fnc_openInterface: Invalid caller or target");
};

// Create the display for the loadout dialog
createDialog "RscLoadout";

// get the player varialble
private _loadout = getUnitLoadout _caller;
private _isMedic = _caller getUnitTrait "Medic";
private _isEngineer = _caller getUnitTrait "Engineer";
private _isEOD = _caller getUnitTrait "ExplosiveSpecialist";

// set the player variables
private _playerData = [_caller, _target, _loadout, _isMedic, _isEngineer, _isEOD];

uiNamespace setVariable [QGVAR(playerLoadoutData), _playerData];
