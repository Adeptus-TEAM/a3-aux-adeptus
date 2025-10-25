#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Update player data in the database.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit for which the profile will be updated.
 * 1: _uid (default: "") <STRING> - The player's unique identifier (UID). If not provided, it will be fetched from the player unit.
 * 2: _data (optional, default: []) <HASHMAP> - A hashmap containing data to update. If not provided, default values will be used.
 *
 * Return Value:
 * <BOOL> - Returns true if the player profile was successfully updated, false otherwise.
 *
 * Example:
 * [player,getPlayerUID player] call ar_inidbi_fnc_updatePlayerData
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]],
	["_uid", "", [""]], // The player's unique identifier (UID)
	["_data", createHashMap, [createHashMap]] // Optional data to update, default is an empty hashmap
];

TRACE_1("fnc_updatePlayerData",_this);

private _inidbi = [_uid] call FUNC(createInstance); // Create a new INIDBI instance for the player

if (isNil "_inidbi") exitWith {
	ERROR_1("Failed to create INIDBI instance for %1",_uid);
	false
};

// Get player data
private _playerName = name _player;
private _playerLoadout = getUnitLoadout _player;
private _isMedic = _player getUnitTrait "Medic";
private _isEngineer = _player getUnitTrait "Engineer";
private _isEOD = _player getUnitTrait "ExplosiveSpecialist";

// Write player data to the INIDBI instance
["Write", ["GameData", "Name", _playerName]] call _inidbi;
TRACE_1("fnc_updatePlayerData (Write Name)",_playerName);
["Write", ["GameData", "SteamID64", _UID]] call _inidbi;
TRACE_1("fnc_updatePlayerData (Write SteamID64)",_UID);
["Write", ["GameData", "Loadout", _playerLoadout]] call _inidbi;
TRACE_1("fnc_updatePlayerData (Write Loadout)",_playerLoadout);
["Write", ["GameData", "isMedic", _isMedic]] call _inidbi;
TRACE_1("fnc_updatePlayerData (Write isMedic)",_isMedic);
["Write", ["GameData", "isEngineer", _isEngineer]] call _inidbi;
TRACE_1("fnc_updatePlayerData (Write isEngineer)",_isEngineer);
["Write", ["GameData", "isEOD", _isEOD]] call _inidbi;
TRACE_1("fnc_updatePlayerData (Write isEOD)",_isEOD);

INFO_1("[INIDBI] %1 profile has been updated",_UID);

TRACE_1("fnc_updatePlayerData (Done)",true);
true
