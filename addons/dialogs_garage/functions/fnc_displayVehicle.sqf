#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Displays the vehicle image and display name in the garage dialog.
 *
 * Arguments:
 * 0: Display <DISPLAY>
 * 1: Vehicle class name <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_display, "B_MRAP_01_F"] call ar_dialogs_garage_fnc_displayVehicles
 *
 * Public: No
 */

params [
	["_display", displayNull, [displayNull]],
	["_vehicleClass", "", [""]]
];
TRACE_1("ar_dialogs_garage_fnc_displayVehicles",_this);

if(isNull _display)exitWith{
	WARNING("No display found");
};

private _vehicleImage = (getText (configFile >> "CfgVehicles" >> _vehicleClass >> "editorPreview"));
private _vehicleDisplayName = [configFile >> "CfgVehicles" >> _vehicleClass] call BIS_fnc_displayName;

if (_vehicleImage == "") then {
	_vehicleImage = QPATHTOEF(dialogs_garage,data\notFound_co.jpg);
};

if(_vehicleDisplayName == "")then{
	_vehicleDisplayName = "N/A";
};


(_display displayCtrl 1000) ctrlSetText _vehicleImage;
(_display displayCtrl 1001) ctrlSetText _vehicleDisplayName;
