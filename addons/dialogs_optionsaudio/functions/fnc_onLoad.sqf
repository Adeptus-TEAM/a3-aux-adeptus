#include "..\script_component.hpp"
/*
 * Author: Archer
 * Initialises the environment volume slider of the audio options display.
 *
 * Arguments:
 * 0: Display <DISPLAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [findDisplay 6] call ar_dialogs_optionsaudio_fnc_onLoad
 *
 * Public: No
 */
params [["_display", displayNull, [displayNull]]];
if (isNull _display) exitWith {};

private _slider = _display displayCtrl 115100;
if (isNull _slider) exitWith {};

private _value = profileNamespace getVariable [QGVAR(envVolume), 1];
_slider sliderSetRange [0, 1];
_slider sliderSetSpeed [0.05, 0.1];
_slider sliderSetPosition _value;

_display displayAddEventHandler ["Unload", {
	saveProfileNamespace;
}];
