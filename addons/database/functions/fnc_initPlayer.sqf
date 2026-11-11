#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Loads the player's profile from the database, or creates it on first connection.
 *              Runs on the dedicated server, raised by the client once its unit exists.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [player] call ar_database_fnc_initPlayer
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

TRACE_1("fnc_initPlayer",_this);

if (isNull _player) exitWith {};
private _uid = getPlayerUID _player;
if (_uid isEqualTo "") exitWith {
	WARNING_1("[DATABASE] No UID for %1",_player);
};

["getPlayer", [_uid], {
	params ["_rows", "_args"];
	_args params ["_player", "_uid"];

	if (_rows isEqualTo []) then {
		// First connection: create the profile from the current unit
		INFO_1("[DATABASE] Creating new player profile for %1",_uid);
		GVAR(loadedUIDs) set [_uid, true];
		[_player, _uid] call FUNC(savePlayer);
	} else {
		INFO_1("[DATABASE] Loading existing player profile for %1",_uid);
		[_player, _rows select 0] call FUNC(applyPlayerData);
	};
}, [_player, _uid]] call FUNC(query);
