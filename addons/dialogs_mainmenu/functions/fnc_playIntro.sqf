#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Opening animation of the main menu: each element fades in while sliding into place.
 *              The cascade comes from longer animation times for lower elements (the menu has no timer to delay them).
 *
 *              Called in onLoad: hides the elements at their start position and stores the function that plays
 *              the animation. The opening sequence (fnc_introTick) plays it when the black screen fades away.
 *
 * Arguments:
 * 0: _display <DISPLAY> - The main menu display
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [findDisplay 0] call AR_Dialogs_MainMenu_fnc_playIntro
 *
 * Public: No
 */

params [["_display", displayNull, [displayNull]]];

// Slide distance, as a share of the screen width
#define SLIDE (0.025 * safeZoneW)

// Animation of one control from its class name (without the "AR_Dialogs_MainMenu_" prefix):
// [duration in seconds, slide direction (-1 from the left, 1 from the right, 0 fade only)], or [] to leave it still
private _fnc_animation = {
	params ["_name"];
	if (_name find "row" == 0) exitWith {
		// Server rows one after the other: rowBg_1, rowName_2...
		[0.65 + 0.15 * parseNumber (_name select [count _name - 1]), -1]
	};
	switch (true) do {
		case (_name in ["logo", "brand", "headerBg", "headerLine"]);
		case (_name find "nav_" == 0): {[0.45, 0]};
		case (_name find "news" == 0): {[0.5, -1]};
		case (_name in ["title", "tagline"]): {[0.6, -1]};
		case (_name find "deploy" == 0): {[0.7, -1]};
		case (_name find "link_" == 0);
		case (_name == "version"): {[1.25, 0]};
		case (_name find "profile" == 0): {[1.1, 1]};
		default {[]};
	}
};

// 1. Hide every animated element at its start position, and remember where it goes
private _animated = [];
{
	private _class = ctrlClassName _x;
	if (_class find "AR_Dialogs_MainMenu_" == 0) then {
		private _animation = [_class select [20]] call _fnc_animation;
		if (_animation isNotEqualTo []) then {
			_animation params ["_duration", "_direction"];
			private _pos = ctrlPosition _x;
			_x ctrlSetPosition [(_pos select 0) + _direction * SLIDE, _pos select 1];
			_x ctrlSetFade 1;
			_x ctrlCommit 0;
			_animated pushBack [_x, [_pos select 0, _pos select 1], _duration];
		};
	};
} forEach allControls _display;
_display setVariable [QGVAR(introControls), _animated];

// 2. Played by the opening sequence (fnc_introTick)
private _fnc_play = {
	params ["_display"];
	private _animated = _display getVariable [QGVAR(introControls), []];
	if (_animated isEqualTo []) exitWith {};
	_display setVariable [QGVAR(introControls), []];
	{
		_x params ["_ctrl", "_pos", "_duration"];
		_ctrl ctrlSetPosition _pos;
		_ctrl ctrlSetFade 0;
		_ctrl ctrlCommit _duration;
	} forEach _animated;
};
_display setVariable [QGVAR(introPlay), _fnc_play];

