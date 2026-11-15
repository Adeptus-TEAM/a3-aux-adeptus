#include "..\script_component.hpp"
/*
 * Author: Archer
 * Applies and stores the environment volume chosen on the slider.
 *
 * Arguments:
 * 0: Slider control <CONTROL>
 * 1: New position <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_ctrl, 0.5] call ar_dialogs_optionsaudio_fnc_onEnvVolumeChanged
 *
 * Public: No
 */
params ["_ctrl", ["_value", 1, [0]]];

_value = 0 max _value min 1;
0 fadeEnvironment _value;
profileNamespace setVariable [QGVAR(envVolume), _value];
