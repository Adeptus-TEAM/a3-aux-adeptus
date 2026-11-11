#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Load player data from the database.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit for which the profile will be loaded.
 *
 * Return Value:
 * <HASHMAP> - Returns a hash map containing the loaded player data.
 *
 * Example:
 * [player] call ar_inidbi_fnc_loadPlayerData
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

TRACE_1("fnc_loadPlayerData",_this);

private _UID = getPlayerUID _player; // Get the player's unique identifier (UID)

private _inidbi = [_UID] call FUNC(createInstance); // Create a new INIDBI instance for the player

if (isNil "_inidbi") exitWith {
	ERROR_1("Failed to create INIDBI instance for %1",_UID);
	createHashMap
};

// Third element = default value returned by iniDBi when the key is missing (otherwise it returns false)
private _playerName = ["Read", ["GameData", "Name", ""]] call _inidbi;
private _playerLoadout = ["Read", ["GameData", "Loadout", []]] call _inidbi;
private _isMedic = ["Read", ["GameData", "isMedic", false]] call _inidbi;
private _isEngineer = ["Read", ["GameData", "isEngineer", false]] call _inidbi;
private _isEOD = ["Read", ["GameData", "isEOD", false]] call _inidbi;

private _data = createHashMapFromArray [
	["Name", _playerName],
	["SteamID64", _UID],
	["Loadout", _playerLoadout],
	["isMedic", _isMedic],
	["isEngineer", _isEngineer],
	["isEOD", _isEOD]
];

_player setVariable [QGVAR(playerData),_data,true]; // Store the player data in the variable AR_IniDBi_playerData

INFO_1("[INIDBI] %1 profile has been loaded",_UID);

TRACE_1("fnc_loadPlayerData (Done)",_data);
_data
