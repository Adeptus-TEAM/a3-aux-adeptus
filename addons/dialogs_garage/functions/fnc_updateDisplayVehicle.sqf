#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Displays the vehicle image and display name in the garage dialog.
 *
 * Arguments:
 * <NONE>
 * 
 * Return Value:
 * None
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_displayVehicles
 *
 * Public: No
 */

params [];
TRACE_1("ar_dialogs_garage_fnc_displayVehicles",_this);

// Get the display.
_display = uiNamespace getVariable [QGVAR(display), displayNull];
if (isNull _display) exitWith {
	WARNING("Invalid display");
};

// Get the list of vehicles from the uiNamespace.
private _displayImageVehicleControl = _display displayCtrl 1000; 
if(isNull _displayImageVehicleControl) exitWith {
	WARNING("Invalid control");
};

// Get the control for the vehicle display name.
private _displayNameVehicleControl = _display displayCtrl 1001; 
if(isNull _displayNameVehicleControl) exitWith {
	WARNING("Invalid control");
};

// Get the control for the vehicle list box.
private _vehicleListBoxControl = _display displayCtrl 1003;
if(isNull _vehicleListBoxControl) exitWith {
	WARNING("Invalid control");
};

// Get the selected index from the vehicle list box.
private _selectedIndex = lbCurSel _vehicleListBoxControl;
if (_selectedIndex < 0) exitWith {};

// Store the selected index in the uiNamespace for the spawn function.
uiNamespace setVariable [QGVAR(selectionCounter), _selectedIndex]; 

// Get the list of vehicles from the uiNamespace.
private _listVehicles = (uiNamespace getVariable [QGVAR(listVehicles), []]);
if (_selectedIndex >= count _listVehicles) exitWith {
	WARNING("Index out of bounds");
};

private _selectedVehicleClass =  _listVehicles select _selectedIndex;

// Get the display name and editor preview for the selected vehicle.
private _vehicleDisplayName = getText (configFile >> "CfgVehicles" >> _selectedVehicleClass >> "displayName");
private _vehicleEditorPreview = getText (configFile >> "CfgVehicles" >> _selectedVehicleClass >> "editorPreview");

// Update the display with the selected vehicle's information.
_displayNameVehicleControl ctrlSetText _vehicleDisplayName;
_displayImageVehicleControl ctrlSetText _vehicleEditorPreview;




