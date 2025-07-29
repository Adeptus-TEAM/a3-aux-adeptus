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

uiNamespace setVariable [QGVAR(selectionCounter), 0]; // Set the selection counter to 0
uiNamespace setVariable [QGVAR(listVehicles), []]; // Set the list of vehicles to an empty array

private _terminal = uiNamespace getVariable [QGVAR(garageObject), objNull]; // Get the garage terminal object

private _spawnObject = (call compile (_terminalObject getVariable[QEGVAR(objects,garageSpawnObject),"objNull"])); // Get the spawn object from the terminal
private _areaSize = _terminal getVariable [QEGVAR(objects,garageAreaSize), 0]; // Get the area size from the terminal
private _listVehiclesCombo = _terminal getVariable [QEGVAR(objects,garageVehiclesList), 0]; // Get the selected vehicles list from the terminal

// Check if the terminal and spawn object are valid

if(isNull _terminal) exitWith {
	WARNING("Invalid terminal");
};

if(isNull _spawnObject) exitWith {
	WARNING("Invalid spawn object");
};

switch (_listVehiclesCombo) do {
	case 0: {uiNamespace setVariable [QGVAR(listVehicles),getMissionConfigValue QEGVAR(missions,TerrestrialVehicles)];};
	case 1: {uiNamespace setVariable [QGVAR(listVehicles),getMissionConfigValue QEGVAR(missions,TransportAerialVehicles)];};
	case 2: {uiNamespace setVariable [QGVAR(listVehicles),getMissionConfigValue QEGVAR(missions,AttackAerialVehicles)];};
	case 3: {uiNamespace setVariable [QGVAR(listVehicles),getMissionConfigValue QEGVAR(missions,SupplyCrate)];};
};

private _vehicleClass = (uiNamespace getVariable[QGVAR(listVehicles),[""]]) select 0;
[_display,_vehicleClass] call SUBFUNC(displayVehicle); // Call the function to display the vehicle image
