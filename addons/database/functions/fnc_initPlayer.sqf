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

["getPlayer", [GVAR(dbMode), _uid], {
	params ["_rows", "_args"];
	_args params ["_player", "_uid"];

	// No row: unknown player. hasData = 0: known player, but nothing yet in this db_mode (new campaign).
	// In both cases the current unit (mission loadout) becomes the profile for this db_mode.
	private _hasData = _rows isNotEqualTo [] && {((_rows select 0) param [5, 0]) > 0};

	if (_hasData) then {
		INFO_2("[DATABASE] Loading profile of %1 (%2)",_uid,GVAR(dbMode));
		[_player, _rows select 0] call FUNC(applyPlayerData);
	} else {
		INFO_2("[DATABASE] Creating profile of %1 (%2)",_uid,GVAR(dbMode));
		GVAR(loadedUIDs) set [_uid, true];
		[_player, _uid] call FUNC(savePlayer);
	};
}, [_player, _uid]] call FUNC(query);
