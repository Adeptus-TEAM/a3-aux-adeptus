#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Writes the player's loadout and traits to the database (insert or update).
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit
 * 1: _uid (default: "") <STRING> - The player's SteamID64 (the unit may already be disconnected)
 *
 * Return Value:
 * <BOOL> - true if the write was sent
 *
 * Example:
 * [player, getPlayerUID player] call ar_database_fnc_savePlayer
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]],
	["_uid", "", [""]]
];

TRACE_2("fnc_savePlayer",_player,_uid);

// Never write an empty profile (e.g. a player who disconnects from the lobby has no unit)
if (isNull _player || {_uid isEqualTo ""}) exitWith {
	WARNING_1("[DATABASE] Skipping save, no unit or UID for %1",_uid);
	false
};

// ACE accepts either a number or a boolean for these variables
private _fnc_toFlag = {
	parseNumber (if (_this isEqualType true) then {_this} else {_this > 0})
};

// ":" is extDB3's separator and '"' would break the SQF string returned by getPlayer
private _name = ((name _player) regexReplace ["[:""]", ""]) select [0, 64];

[
	"savePlayer",
	[
		_uid,
		_name,
		str getUnitLoadout _player,
		(_player getVariable ["ace_medical_medicclass", 0]) call _fnc_toFlag,
		(_player getVariable ["ace_isEngineer", 0]) call _fnc_toFlag,
		(_player getVariable ["ace_isExplosiveSpecialist", false]) call _fnc_toFlag
	]
] call FUNC(execute)
