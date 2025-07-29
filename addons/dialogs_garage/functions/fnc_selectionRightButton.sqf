#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Handles the logic for the right selection button in the garage dialog.
 *
 * Arguments:
 * 0: Control that triggered the event <CONTROL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_control] call ar_dialogs_garage_fnc_selectionRightButton
 *
 * Public: No
 */

params [
	["_control", controlNull, [controlNull]]
];
TRACE_1("ar_dialogs_garage_fnc_selectionRightButton",_this);

if(isNull _control) exitWith {
	WARNING("Invalid control");
};

private _display = ctrlParent _control;

if(isNull _display) exitWith {
	WARNING("Invalid display");
};

// Get values
private _counter = uiNamespace getVariable [QGVAR(selectionCounter), 0];
private _listVehicles = uiNamespace getVariable [QGVAR(listVehicles), []];

if (count _listVehicles == 0) exitWith {
	WARNING("No vehicles available");
};

ADD(_counter,1);
if(_counter > (count _listVehicles) - 1) then {
	_counter = 0;
};
uiNamespace setVariable [QGVAR(selectionCounter), _counter];

private _vehicleClass = _listVehicles select _counter;

[_display,_vehicleClass] call SUBFUNC(displayVehicle); // Call the function to display the vehicle image
