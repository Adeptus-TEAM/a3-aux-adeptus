#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to initialize the Laat Air drop interface.
	 *
	 * Arguments:
	 * 0: _display (default: displayNull) <DISPLAY> - The display on which the Laat Air drop interface will be initialized.
	 *
	 * Return Value:
	 * Return description <NONE>
	 *
	 * Example:
	 * [myDisplay] call ar_zeus_laatAirDrop_fnc_onLoad
	 *
	 * Public: No
 */
	
params [
	["_display", displayNull, [displayNull]]
];

TRACE_1("ar_zeus_laatAirDrop_fnc_onLoad",_this);

uiNamespace setVariable [QGVAR(RscLaatAirDrop), _display];

private _module = uiNamespace getVariable QGVAR(laatAirDropModule);

if (isNull _module) exitWith {
	WARNING("ar_zeus_laatAirDrop_fnc_onLoad: Module not found in uiNamespace");
	_display closeDisplay 0;
};

private _comboSupply = _display displayCtrl 1001;
private _sliderSetDir = _display displayCtrl 1003;
private _sliderSetHeight = _display displayCtrl 1005;

// set up the supply crate combo box
private _comboSupplyOptions = getMissionConfigValue [QEGVAR(missions,SupplyCrate), ["C_IDAP_supplyCrate_F"]];
{
	private _displayname = [configFile >> "CfgVehicles" >> _x] call BIS_fnc_displayName;
    private _editorPreview = getText (configFile >> "CfgVehicles" >> _x >> "editorPreview");
    _comboSupply lbAdd _displayname;
    _comboSupply lbSetData [_forEachIndex, _x];
    _comboSupply lbSetPicture [_forEachIndex, _editorPreview];
} forEach _comboSupplyOptions;

uiNamespace setVariable [QGVAR(laatAirDropSupply), []];

_comboSupply lbSetCurSel 0;

// set up the direction list box
_sliderSetDir sliderSetRange [0, 7];
_sliderSetDir sliderSetSpeed [1, 1, 1];
_sliderSetDir sliderSetPosition 0;
[_sliderSetDir, 0] call SUBFUNC(onSliderSetDirChanged);

// set up the height slider
_sliderSetHeight sliderSetRange [100, 500];
_sliderSetHeight sliderSetSpeed [50, 50, 50];
_sliderSetHeight sliderSetPosition 100;
[_sliderSetHeight, 100] call SUBFUNC(onSliderSetHeightChanged);
