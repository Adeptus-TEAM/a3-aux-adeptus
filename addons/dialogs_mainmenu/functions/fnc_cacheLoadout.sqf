#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Keeps a copy of the player's loadout in their Arma profile, so the main menu can show their soldier.
 *              Only in multiplayer missions using the main database (db_mode "Main", the default):
 *              campaign loadouts are not shown in the menu.
 *              The first minute is skipped: the server is still applying the saved profile over the mission loadout.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [] call AR_Dialogs_MainMenu_fnc_cacheLoadout
 *
 * Public: No
 */

// Delay before the first copy, and after the last loadout change (the CBA event also fires on every shot)
#define FIRST_DELAY 60
#define CHANGE_DELAY 5

if (!hasInterface) exitWith {};
if (!isMultiplayer) exitWith {};
if ((getMissionConfigValue ["db_mode", "Main"]) != "Main") exitWith {};

GVAR(cacheReady) = false;
GVAR(cacheChangeId) = 0;

GVAR(fnc_writeCache) = {
	if (isNull player || {!alive player}) exitWith {false};
	profileNamespace setVariable [PROFILE_LOADOUT, getUnitLoadout player];
	saveProfileNamespace;
	true
};

[
	{!isNull player},
	{
		[{
			GVAR(cacheReady) = true;
			// Dead or respawning at that moment: save as soon as the player is alive again
			[{call GVAR(fnc_writeCache)}, {}] call CBA_fnc_waitUntilAndExecute;
		}, [], FIRST_DELAY] call CBA_fnc_waitAndExecute;
	}
] call CBA_fnc_waitUntilAndExecute;

["loadout", {
	if (!GVAR(cacheReady)) exitWith {};
	GVAR(cacheChangeId) = GVAR(cacheChangeId) + 1;
	[{
		params ["_changeId"];
		if (_changeId == GVAR(cacheChangeId)) then {
			call GVAR(fnc_writeCache);
		};
	}, [GVAR(cacheChangeId)], CHANGE_DELAY] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addPlayerEventHandler;
