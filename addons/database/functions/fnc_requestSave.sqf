#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Schedules a save after a loadout or trait change.
 *              Several changes close together only produce one write.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [QGVAR(requestSave), [player]] call CBA_fnc_serverEvent
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

if (isNull _player) exitWith {};
private _uid = getPlayerUID _player;

// Profile not loaded yet (the change comes from the mission's default loadout), or save already scheduled
if (!(_uid in GVAR(loadedUIDs)) || {_uid in GVAR(pendingSaves)}) exitWith {};

GVAR(pendingSaves) set [_uid, true];
[{
	params ["_player", "_uid"];
	// Skipped if the player disconnected meanwhile (already saved by HandleDisconnect)
	if (_uid in GVAR(pendingSaves)) then {
		GVAR(pendingSaves) deleteAt _uid;
		[_player, _uid] call FUNC(savePlayer);
	};
}, [_player, _uid], SAVE_DELAY] call CBA_fnc_waitAndExecute;
