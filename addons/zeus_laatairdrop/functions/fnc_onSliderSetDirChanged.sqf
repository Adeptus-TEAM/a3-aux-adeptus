#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Function to handle the slider position change for the direction setting in the Laat Air drop module.
 *
 * Arguments:
 * 0: _control (default: controlNull) <CONTROL> - The control that triggered the slider position change.
 * 1: _sliderValue (default: 0) <NUMBER> - The new position of the slider.
 *
 * Return Value:
 * Return description <NONE>
 *
 * Example:
 * [_control, _sliderValue] call ar_zeus_laatAirDrop_fnc_onSliderSetDirChanged
 *
 * Public: No
 */

params [
	["_control", controlNull, [controlNull]],
	["_sliderValue", 0, [0]]
];

TRACE_1("ar_zeus_laatAirDrop_fnc_onSliderSetDirChanged",_this);

private _display = ctrlParent _control;
private _infoSetDir = _display displayCtrl 1004;

// Calculate the direction based on the slider value
private _direction = ["North", "North-East", "East", "South-East", "South", "South-West", "West", "North-West"] select _sliderValue;

// Update the info text with the new direction
_infoSetDir ctrlSetText _direction;
