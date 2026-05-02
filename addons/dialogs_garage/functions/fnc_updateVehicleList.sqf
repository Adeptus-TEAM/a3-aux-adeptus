#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description : Update the list of vehicles in the garage dialog.
 *
 * Arguments:
 * 0: List of vehicle's classname
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [["B_MRAP_01_F", "B_Truck_01_transport_F"]] call AR_dialogs_garage_fnc_showVehicleList
 *
 * Public: No
 */

params [
	["_listVehicles", [], [[]]]
];
TRACE_1("ar_dialogs_garage_fnc_showVehicleList",_this);

// Store the list of vehicles for other functions.
uiNamespace setVariable [QGVAR(listVehicles), _listVehicles];

// Get the display.
private _display = uiNamespace getVariable [QGVAR(display), displayNull];
if (isNull _display) exitWith {
	WARNING("Invalid display");
};

// Get the control for the vehicle list.
private _vehicleListBox = _display displayCtrl 1003;
if(isNull _vehicleListBox) exitWith {
	WARNING("Invalid control");
};

// Clear the list box before populating it.
lbClear _vehicleListBox;

{
	private _displaName = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
	private _editorPreview = getText (configFile >> "CfgVehicles" >> _x >> "editorPreview");

	_vehicleListBox lbAdd _displaName;
	_vehicleListBox lbSetPicture [_forEachIndex,_editorPreview];
} forEach _listVehicles;

// Set the first item as selected by default and update the display.
_vehicleListBox lbSetCurSel 0;
0 call SUBFUNC(updateDisplayVehicle);
