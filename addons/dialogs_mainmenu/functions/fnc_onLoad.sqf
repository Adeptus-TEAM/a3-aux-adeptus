#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Sets up the Adeptus main menu after the vanilla RscDisplayMain script has run:
 *              hides the vanilla controls, fills the dynamic texts and wires buttons and hover effects.
 *
 * Arguments:
 * 0: _display <DISPLAY> - The main menu display
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [findDisplay 0] call AR_Dialogs_MainMenu_fnc_onLoad
 *
 * Public: No
 */

params [["_display", displayNull, [displayNull]]];

TRACE_1("fnc_onLoad",_display);

if (isNull _display) exitWith {};

// Hide every vanilla control. They stay in the display because the engine and RscDisplayMain.sqf use them.
// They are also moved off screen: the vanilla script shows the menu titles again on its own (ctrlShow true),
// but never moves them back.
private _fnc_hideVanilla = {
	params ["_display"];
	{
		if ((ctrlClassName _x) find "AR_Dialogs_MainMenu_" != 0) then {
			// Only touch what needs it: this also runs every frame from the scene (fnc_initScene)
			if (ctrlShown _x) then {
				_x ctrlShow false;
			};
			// Also fully transparent: when Arma rebuilds the menu (back from the profile screen...) its script shows
			// some controls again (e.g. the "Unit" icon), but never makes them opaque again
			if (ctrlFade _x < 1) then {
				_x ctrlSetFade 1;
				_x ctrlCommit 0;
			};
			if (isNull ctrlParentControlsGroup _x && {(ctrlPosition _x) select 0 > -9}) then {
				_x ctrlSetPosition [-10, -10, 0.01, 0.01];
				_x ctrlCommit 0;
			};
		};
	} forEach allControls _display;
};
_display setVariable [QGVAR(hideVanilla), _fnc_hideVanilla];
[_display] call _fnc_hideVanilla;

// The vanilla script shows some of them again when a child display (options, editor...) closes
// (the profile name is refreshed too: it may have been changed in the profile screen)
_display displayAddEventHandler ["ChildDestroyed", {
	params ["_display"];
	[_display] call (_display getVariable QGVAR(hideVanilla));
	(_display displayCtrl IDC_PROFILE_NAME) ctrlSetText toUpper profileName;
}];

// Dynamic texts
(_display displayCtrl IDC_PROFILE_NAME) ctrlSetText toUpper profileName;
(_display displayCtrl IDC_VERSION) ctrlSetText format ["Adeptus Auxiliaire %1", QUOTE(VERSION_STR)];
(_display displayCtrl IDC_TAGLINE) ctrlSetStructuredText parseText format [
	"%1 <t color='#51A2FF'>%2</t> %3",
	LSUBLSTRING(tagline1), LSUBLSTRING(taglineBacta), LSUBLSTRING(tagline2)
];

// News panel: page from the website. The fallback text stays until the page is loaded
// (checked now, then on the menu mouse events in case the page arrives a bit later).
private _ctrlNews = _display displayCtrl IDC_NEWS;
_ctrlNews htmlLoad NEWS_URL;
private _fnc_checkNews = {
	params ["_display"];
	private _loaded = ctrlHTMLLoaded (_display displayCtrl IDC_NEWS);
	(_display displayCtrl IDC_NEWS_FALLBACK) ctrlShow !_loaded;
	_loaded
};
_display setVariable [QGVAR(checkNews), _fnc_checkNews];
if !([_display] call _fnc_checkNews) then {
	{
		_display displayAddEventHandler [_x, {
			params ["_display"];
			if ([_display] call (_display getVariable QGVAR(checkNews))) then {
				_display displayRemoveEventHandler [_thisEvent, _thisEventHandler];
			};
		}];
	} forEach ["MouseMoving", "MouseHolding"];
};

// Player name panel: opens the vanilla profile screen
(_display displayCtrl IDC_PROFILE_BUTTON) ctrlAddEventHandler ["ButtonClick", {
	[ctrlParent (_this select 0), 109] call UIFUNC(openVanilla);
}];

// Server rows: hover + click
{
	private _ctrl = _display displayCtrl IDC_ROW_BUTTON(_x);
	_ctrl ctrlAddEventHandler ["MouseEnter", {[_this select 0, true] call UIFUNC(setHover)}];
	_ctrl ctrlAddEventHandler ["MouseExit", {[_this select 0, false] call UIFUNC(setHover)}];
	_ctrl ctrlAddEventHandler ["ButtonClick", {[ctrlIDC (_this select 0) - 6100] call UIFUNC(selectServer)}];
} forEach [1, 2, 3];

// Options dropdown: hidden until OPTIONS is clicked
private _fnc_showOptions = {
	params ["_display", "_show"];
	{(_display displayCtrl (IDC_OPTIONS_BG + _x)) ctrlShow _show} forEach [0, 1, 2, 3, 4];
};
_display setVariable [QGVAR(showOptions), _fnc_showOptions];
[_display, false] call _fnc_showOptions;

// Header buttons and options entries: open the matching vanilla menu entry (-1: toggle the options dropdown)
{
	_x params ["_idc", "_vanillaIdc"];
	private _ctrl = _display displayCtrl _idc;
	_ctrl setVariable [QGVAR(vanillaIdc), _vanillaIdc];
	_ctrl ctrlSetTextColor ARR_MUTED;
	_ctrl ctrlAddEventHandler ["MouseEnter", {(_this select 0) ctrlSetTextColor ARR_WHITE}];
	_ctrl ctrlAddEventHandler ["MouseExit", {(_this select 0) ctrlSetTextColor ARR_MUTED}];
	_ctrl ctrlAddEventHandler ["ButtonClick", {
		params ["_ctrl"];
		private _display = ctrlParent _ctrl;
		private _vanillaIdc = _ctrl getVariable QGVAR(vanillaIdc);
		private _fnc_showOptions = _display getVariable QGVAR(showOptions);
		if (_vanillaIdc == -1) exitWith {
			[_display, !ctrlShown (_display displayCtrl IDC_OPTIONS_BG)] call _fnc_showOptions;
		};
		[_display, false] call _fnc_showOptions;
		[_display, _vanillaIdc] call UIFUNC(openVanilla);
	}];
} forEach [
	[6161, 142],                // Editor
	[6162, 140],                // Mods (vanilla "Expansions" screen)
	[6163, -1],                 // Options (dropdown)
	[6165, 106],                // Quit
	[IDC_OPTIONS_BG + 1, 301],  // Video
	[IDC_OPTIONS_BG + 2, 302],  // Audio
	[IDC_OPTIONS_BG + 3, 303],  // Controls
	[IDC_OPTIONS_BG + 4, 307]   // Game
];

// Footer links: url set by script too (must be whitelisted in CfgCommands, see config.cpp), and hover color
{
	_x params ["_idc", "_url", "_color"];
	private _ctrl = _display displayCtrl _idc;
	_ctrl ctrlSetURL _url;
	_ctrl setVariable [QGVAR(linkColor), _color];
	_ctrl ctrlAddEventHandler ["MouseEnter", {(_this select 0) ctrlSetTextColor ARR_WHITE}];
	_ctrl ctrlAddEventHandler ["MouseExit", {(_this select 0) ctrlSetTextColor ((_this select 0) getVariable QGVAR(linkColor))}];
} forEach [
	[6181, "https://discord.com/invite/dPgxPgv", [0.345, 0.396, 0.949, 1]],
	[6182, "https://adeptus-team.eu", ARR_MUTED],
	[6183, "https://wiki.adeptus-team.eu", ARR_MUTED],
	[6184, "ts3server://ts3.adeptus-team.eu", ARR_MUTED]
];

// Opening sequence: menu elements hidden now, played by fnc_introTick. The scene ticks it every frame;
// these mouse events tick it too, for a game launched without the scene (-skipIntro).
// Played once per return to the main menu: Arma rebuilds the menu when some screens close (profile...),
// it then shows up directly. Reset by XEH_postInit when a mission (or the menu scene) starts.
if (uiNamespace getVariable [QGVAR(introPlayed), false]) then {
	{(_display displayCtrl _x) ctrlShow false} forEach [IDC_INTRO_BLACK, IDC_INTRO_LOGO, IDC_INTRO_TITLE, IDC_INTRO_LINE];
	_display setVariable [QGVAR(introStage), 7];
} else {
	[_display] call UIFUNC(playIntro);
	{
		_display displayAddEventHandler [_x, {[_this select 0] call UIFUNC(introTick)}];
	} forEach ["MouseMoving", "MouseHolding"];
};

