#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Initializes the garage dialog: type buttons, vehicle list and selection counter.
 *
 * Arguments:
 * 0: Display <DISPLAY> (optional, default: displayNull)
 *
 * Return Value:
 * None
 *
 * Example:
 * [params] call ar_dialogs_garage_fnc_onLoad
 *
 * Public: No
 */

params [
	["_display", displayNull, [displayNull]]
];
TRACE_1("ar_dialogs_garage_fnc_onLoad",_this);

// Store the display reference for other functions.
uiNamespace setVariable [QGVAR(display), _display];

// Initialize selectionCounter and listVehicles.
uiNamespace setVariable [QGVAR(selectionCounter), 0];
uiNamespace setVariable [QGVAR(listVehicles), []];

// Get the garage terminal.
private _terminal = uiNamespace getVariable [QGVAR(garageObject), objNull];
if (isNull _terminal) exitWith {
	WARNING("Invalid terminal");
};

// Show only the type buttons enabled on the terminal.
private _enabledTypes = [_terminal] call SUBFUNC(updateTypeButtons);
if (_enabledTypes isEqualTo []) exitWith {
	WARNING_1("No vehicle type enabled on terminal %1",_terminal);
};

// Reopen the last used type, if it is enabled on this terminal. Otherwise, open the first enabled one.
private _lastSelectionIndex = uiNamespace getVariable [QGVAR(lastTypeSelection), 0];
if !(_lastSelectionIndex in _enabledTypes) then {
	_lastSelectionIndex = _enabledTypes select 0;
};
[_lastSelectionIndex] call SUBFUNC(typeSelection);
