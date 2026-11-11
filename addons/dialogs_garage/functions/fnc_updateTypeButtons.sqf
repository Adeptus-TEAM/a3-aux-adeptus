#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Shows only the vehicle type buttons enabled on the terminal,
 *              and moves them up into the first slots, keeping their order.
 *              Uses the buttons' original positions, so the layout is unchanged.
 *
 * Arguments:
 * 0: Garage terminal <OBJECT>
 *
 * Return Value:
 * Enabled type indexes (0 = Terrestrial, 1 = Aerial, 2 = Supply) <ARRAY>
 *
 * Example:
 * [_terminal] call ar_dialogs_garage_fnc_updateTypeButtons
 *
 * Public: No
 */

params [
	["_terminal", objNull, [objNull]]
];
TRACE_1("fnc_updateTypeButtons",_this);

private _display = uiNamespace getVariable [QGVAR(display), displayNull];
if (isNull _display) exitWith {
	WARNING("Invalid display");
	[]
};

// Type buttons, in type index order (0 = Terrestrial, 1 = Aerial, 2 = Supply).
private _buttons = [1010, 1011, 1012] apply {_display displayCtrl _x};

// Original slots, read from the config positions before moving anything.
private _slots = _buttons apply {ctrlPosition _x};

// Types enabled on the terminal (all enabled by default).
private _enabledFlags = [
	_terminal getVariable [QEGVAR(objects,garageTerrestrialEnabled), true],
	_terminal getVariable [QEGVAR(objects,garageAerialEnabled), true],
	_terminal getVariable [QEGVAR(objects,garageSupplyEnabled), true]
];

private _enabledTypes = [];
{
	if (_enabledFlags select _forEachIndex) then {
		// Move the button into the next free slot.
		_x ctrlSetPosition (_slots select (count _enabledTypes));
		_x ctrlShow true;
		_enabledTypes pushBack _forEachIndex;
	} else {
		_x ctrlShow false;
	};
	_x ctrlCommit 0;
} forEach _buttons;

uiNamespace setVariable [QGVAR(enabledTypes), _enabledTypes];

_enabledTypes
