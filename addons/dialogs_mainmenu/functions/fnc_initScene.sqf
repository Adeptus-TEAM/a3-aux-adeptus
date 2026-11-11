#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Called by the main menu scenes (initintro.sqf), after their camera is set:
 *              - shows the player's soldier (fnc_spawnSoldier);
 *              - tells the menu the scene is ready, so its opening sequence can start (fnc_introTick);
 *              - while the scene runs: drives the opening sequence every frame, clears the hints and HUD layers
 *                other mods open (e.g. "waiting for Zeus interface", radars) and keeps vanilla controls hidden.
 *
 * Arguments:
 * 0: _defaultClass <STRING> - Unit class for the soldier (see fnc_spawnSoldier)
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * ["AR_V1_P2_Unit"] call (uiNamespace getVariable "AR_Dialogs_MainMenu_fnc_initScene")
 *
 * Public: No
 */

params [["_defaultClass", "AR_V1_P2_Unit", [""]]];

// Once per scene
if (!isNil QGVAR(sceneEH)) exitWith {};

[_defaultClass] call UIFUNC(spawnSoldier);

// diag_tickTime because "time" may not run in the menu scene
uiNamespace setVariable [QGVAR(sceneReadyAt), diag_tickTime];

// EachFrame works in the menu scene without CBA's per-frame handlers
GVAR(sceneEH) = addMissionEventHandler ["EachFrame", {
	// Kept for as long as the scene runs: some mods (radar) open their HUD again later
	hintSilent "";
	{_x cutFadeOut 0} forEach allCutLayers;

	// The menu display may be created after the scene: wait for it
	private _display = findDisplay 0;
	if (isNull _display) exitWith {};

	[_display] call UIFUNC(introTick);

	// Hide again any control that is not ours (vanilla controls shown again, or controls other mods add)
	[_display] call (_display getVariable [QGVAR(hideVanilla), {}]);
}];
