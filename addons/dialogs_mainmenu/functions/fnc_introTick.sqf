#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Opening sequence of the main menu, advanced one step per call:
 *              black screen -> logo grows in -> title rises in -> yellow line opens -> they rise and fade out
 *              -> the black fades away on the 3D scene while the menu elements come in (fnc_playIntro).
 *
 *              Called every frame by the scene (fnc_initScene) and on the menu's mouse events (fnc_onLoad),
 *              which also tick when the game runs without the scene (-skipIntro).
 *              It waits for the scene to be ready (and the loading screen to be gone), or starts anyway
 *              after a few seconds without scene.
 *
 * Arguments:
 * 0: _display <DISPLAY> - The main menu display
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [findDisplay 0] call AR_Dialogs_MainMenu_fnc_introTick
 *
 * Public: No
 */

params [["_display", displayNull, [displayNull]]];

// Wait after the scene is ready (the loading screen stays a moment after it), and the longest wait without scene
#define SCENE_SETTLE 1.5
#define NO_SCENE_TIMEOUT 4

// Positions from the 1600x900 mockup, like MX/MY/MW/MH in the config
#define PX(v) (safeZoneX + safeZoneW * (v) / 1600)
#define PY(v) (safeZoneY + safeZoneH * (v) / 900)
#define PW(v) (safeZoneW * (v) / 1600)
#define PH(v) (safeZoneH * (v) / 900)

private _stage = _display getVariable [QGVAR(introStage), 0];
if (_stage >= 7) exitWith {};

private _now = diag_tickTime;
private _ctrlBlack = _display displayCtrl IDC_INTRO_BLACK;
private _ctrlLogo = _display displayCtrl IDC_INTRO_LOGO;
private _ctrlTitle = _display displayCtrl IDC_INTRO_TITLE;
private _ctrlLine = _display displayCtrl IDC_INTRO_LINE;

// Stage 0: black screen until the scene is ready. Logo, title and line wait at their start position.
if (_stage == 0) exitWith {
	private _firstTick = _display getVariable [QGVAR(introFirstTick), -1];
	if (_firstTick < 0) then {
		_firstTick = _now;
		_display setVariable [QGVAR(introFirstTick), _now];

		// Logo: a point in the middle of the screen
		_ctrlLogo ctrlSetPosition [PX(800), PY(330), 0, 0];
		_ctrlLogo ctrlSetFade 1;
		// Title: 40 px lower than its place
		_ctrlTitle ctrlSetPosition [PX(300), PY(500), PW(1000), PH(80)];
		_ctrlTitle ctrlSetFade 1;
		// Line: no width, in the middle
		_ctrlLine ctrlSetPosition [PX(800), PY(556), 0, PH(3)];
		_ctrlLine ctrlSetFade 1;
		{_x ctrlCommit 0} forEach [_ctrlLogo, _ctrlTitle, _ctrlLine];
	};

	private _sceneReadyAt = uiNamespace getVariable [QGVAR(sceneReadyAt), -1];
	private _ready = (_sceneReadyAt > 0 && {_now > _sceneReadyAt + SCENE_SETTLE}) || {_now > _firstTick + NO_SCENE_TIMEOUT};
	if (!_ready) exitWith {};

	_display setVariable [QGVAR(introStart), _now];
	_display setVariable [QGVAR(introStage), 1];
	uiNamespace setVariable [QGVAR(introPlayed), true];
};

private _elapsed = _now - (_display getVariable [QGVAR(introStart), _now]);

// [stage, start time in seconds, action]
private _steps = [
	// Logo grows from the center to 160 px
	[1, 0, {
		_ctrlLogo ctrlSetPosition [PX(720), PY(250), PW(160), PH(160)];
		_ctrlLogo ctrlSetFade 0;
		_ctrlLogo ctrlCommit 1.1;
	}],
	// Title rises 40 px into place
	[2, 0.6, {
		_ctrlTitle ctrlSetPosition [PX(300), PY(460), PW(1000), PH(80)];
		_ctrlTitle ctrlSetFade 0;
		_ctrlTitle ctrlCommit 1;
	}],
	// Yellow line opens from the center
	[3, 1.1, {
		_ctrlLine ctrlSetPosition [PX(640), PY(556), PW(320), PH(3)];
		_ctrlLine ctrlSetFade 0;
		_ctrlLine ctrlCommit 1;
	}],
	// Everything rises a little and fades out
	[4, 3.6, {
		{
			private _pos = ctrlPosition _x;
			_x ctrlSetPosition [_pos select 0, (_pos select 1) - PH(30), _pos select 2, _pos select 3];
			_x ctrlSetFade 1;
			_x ctrlCommit 0.7;
		} forEach [_ctrlLogo, _ctrlTitle, _ctrlLine];
	}],
	// The black fades away on the scene, the menu comes in
	[5, 4.2, {
		_ctrlBlack ctrlSetFade 1;
		_ctrlBlack ctrlCommit 1.5;
		[_display] call (_display getVariable [QGVAR(introPlay), {}]);
	}],
	// Done: remove the intro controls so they never get in the way
	[6, 6.2, {
		{_x ctrlShow false} forEach [_ctrlBlack, _ctrlLogo, _ctrlTitle, _ctrlLine];
	}]
];

{
	_x params ["_step", "_time", "_action"];
	if (_stage == _step && {_elapsed >= _time}) then {
		call _action;
		_stage = _step + 1;
		_display setVariable [QGVAR(introStage), _stage];
	};
} forEach _steps;
