#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Sets the NVG color for a player.
	 *
	 * Arguments:
	 * 0: _person (default: objNull) <OBJECT> - The player object to set the NVG color for.
	 * 1: _visionMode (default: 0) <NUMBER> - The vision mode to set for the player (0 = normal, 1 = NVG, 2 = thermal).
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player, 1] call ar_characters_nvgs_fnc_setColor
	 *
	 * Public: No
 */

params [
	["_person", objNull, [objNull]],
	["_visionMode", 0, [0]]
];

TRACE_1("ar_characters_nvgs_fnc_setColor",_this);

if (_visionMode == 1) then {
	TRACE_1("Setting NVG color for person",_person);

	private _handle = ppEffectCreate ["ColorCorrections", 1502];
	_handle ppEffectEnable true; // Enable the color correction effect for NVG
	_handle ppEffectAdjust [1, 0.6, 0, [0, 0.1, 0.2, 0], [0, 1, 1.2, 0], [1, 1, 1, 0]]; // Adjust the color corrections for NVG
	_handle ppEffectCommit 0; // Commit the effect immediately
	_handle ppEffectForceInNVG true; // Force the effect to be used in NVG mode

	_person setVariable [QGVAR(nvgColor),_handle, true]; // Store the effect on the person object
} else {
	TRACE_1("Removing NVG color for person",_person);

	private _nvgColor = _person getVariable [QGVAR(nvgColor), -1]; // Retrieve the effect from the person object

	if (_nvgColor != -1) then {
		ppEffectDestroy _nvgColor; // Destroy the effect if it exists
	};
};
