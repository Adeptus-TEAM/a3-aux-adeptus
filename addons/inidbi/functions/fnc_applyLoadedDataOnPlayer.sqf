#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Set player loaded data on the player unit.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit to set the loaded data on.
 * 1: _data (default: []) <HASHMAP> - A hash map containing the loaded player data.
 *
 * Return Value:
 * <BOOL> - Returns true if the data was successfully set, false otherwise.
 *
 * Example:
 * [player, _data] call ar_inidbi_fnc_applyLoadedDataOnPlayer
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]],
	["_data", createHashMap, [createHashMap]]
];

TRACE_1("fnc_applyLoadedDataOnPlayer",_this);

[
	{
		params ["_player"];
		(isPlayer _player) && (alive _player) && (!(isNull _player));
	},
	{
		params ["_player", "_data"];
		TRACE_1("fnc_applyLoadedDataOnPlayer (WaitUntil)",_player);

		// Apply loadout to the player
		private _playerLoadout = _data getOrDefault ["Loadout", []];
		if (isNil "_playerLoadout") then {
			ERROR_1("[INIDBI] No loadout data found for %1",_player);
		} else {
			TRACE_1("[INIDBI] Applying loadout data for %1",_player);
			_player setUnitLoadout _playerLoadout;
			INFO_1("[INIDBI] Loadout data has been applied for %1",_player);
		};

		// Apply traits to the player
		private _isMedic = _data getOrDefault ["isMedic", false];
		private _isEOD = _data getOrDefault ["isEOD", false];
		private _isEngineer = _data getOrDefault ["isEngineer", false];

		[_player, "medic", _isMedic] call EFUNC(missions,setUnitTrait);
		[_player, "eod", _isEOD] call EFUNC(missions,setUnitTrait);
		[_player, "engineer", _isEngineer] call EFUNC(missions,setUnitTrait);
		INFO_1("[INIDBI] Traits data has been applied for %1",_player);
	},
	[_player, _data]
] call CBA_fnc_waitUntilAndExecute;
