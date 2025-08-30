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
private _playerName = _data getOrDefault ["Name", name _player]; // Get the player's name, or use the provided data
private _playerLoadout = _data getOrDefault ["Loadout", getUnitLoadout _player]; // Get the player's loadout, or use the provided data
private _playerTraits = _data getOrDefault ["Traits", [_player getUnitTrait "Medic", _player getUnitTrait "Engineer", _player getUnitTrait "ExplosiveSpecialist"]]; // Get the player's traits, or use the provided data

// Write player data to the INIDBI instance
["Write", ["GameData", "Name", _playerName]] call _inidbi;
["Write", ["GameData", "SteamID64", _UID]] call _inidbi;
["Write", ["GameData", "Loadout", _playerLoadout]] call _inidbi;
["Write", ["GameData", "Traits", _playerTraits]] call _inidbi;

INFO_1("[INIDBI] %1 profile has been updated",_UID);

TRACE_1("fnc_updatePlayerData (Done)",true);
