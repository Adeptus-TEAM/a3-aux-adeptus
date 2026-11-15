#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Initializes the garage dialog, sets up vehicle lists and selection counter.
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

// Store the display reference for other functions
uiNamespace setVariable [QGVAR(display), _display]; 

// Initialize selectionCounter and listVehicles
uiNamespace setVariable [QGVAR(selectionCounter), 0];
uiNamespace setVariable [QGVAR(listVehicles), []];

// Get the garage terminal object
private _terminal = uiNamespace getVariable [QGVAR(garageObject), objNull]; 

// Check if the terminal is valid
if(isNull _terminal) exitWith {
	WARNING("Invalid terminal");
};

private _spawnObject = (call compile (_terminal getVariable[QEGVAR(objects,garageSpawnObject),"objNull"])); // Get the spawn object from the terminal

// Check if the spawnObject is valid
if(isNull _spawnObject) exitWith {
	WARNING("Invalid spawn object");
};

// Get the last type selection index from the uiNamespace and call the typeSelection function to update the dialog
private _lastSelectionIndex = uiNamespace getVariable [QGVAR(lastTypeSelection), 0];
[_lastSelectionIndex] call SUBFUNC(typeSelection);
