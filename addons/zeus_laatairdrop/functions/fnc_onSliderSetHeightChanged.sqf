#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Function to handle the slider position change for the height setting in the Laat Air drop module.
 *
 * Arguments:
 * 0: _control (default: controlNull) <CONTROL> - The control that triggered the slider position change.
 * 1: _sliderValue (default: 50) <NUMBER> - The new position of the slider.
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [_control, _sliderValue] call ar_zeus_laatAirDrop_fnc_onSliderSetHeightChanged
 *
 * Public: No
 */

params [
	["_control", controlNull, [controlNull]],
	["_sliderValue", 100, [100]]
];

TRACE_1("ar_zeus_laatAirDrop_fnc_onSliderSetHeightChanged",_this);

private _display = ctrlParent _control;
private _infoSetHeight = _display displayCtrl 1006;

// Update the info text with the new height
_infoSetHeight ctrlSetText FORMAT_1("%1 m",_sliderValue);
