#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Applies a profile loaded from the database to the player unit.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit
 * 1: _row (default: []) <ARRAY> - [name, loadout, isMedic, isEngineer, isEOD] (see getPlayer in adeptus.ini)
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [player, _row] call ar_database_fnc_applyPlayerData
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]],
	["_row", [], [[]]]
];

TRACE_1("fnc_applyPlayerData",_this);

// Wait until the unit is alive, then a few seconds more so the mission's own loadout scripts run first
[
	{
		params ["_player"];
		!isNull _player && {isPlayer _player} && {alive _player}
	},
	{
		[{
			params ["_player", "_row"];
			_row params [["_name", ""], ["_loadout", []], ["_isMedic", 0], ["_isEngineer", 0], ["_isEOD", 0]];
			private _uid = getPlayerUID _player;

			if (_loadout isEqualType [] && {_loadout isNotEqualTo []}) then {
				_player setUnitLoadout _loadout;
				INFO_1("[DATABASE] Loadout applied for %1",_uid);
			} else {
				WARNING_1("[DATABASE] No saved loadout for %1",_uid);
			};

			[_player, "medic", _isMedic > 0] call EFUNC(missions,setUnitTrait);
			[_player, "engineer", _isEngineer > 0] call EFUNC(missions,setUnitTrait);
			[_player, "eod", _isEOD > 0] call EFUNC(missions,setUnitTrait);
			INFO_4("[DATABASE] Traits applied for %1; isMedic: %2, isEngineer: %3, isEOD: %4",_uid,_isMedic,_isEngineer,_isEOD);

			// From now on this player's data can be saved
			GVAR(loadedUIDs) set [_uid, true];
		}, _this, 5] call CBA_fnc_waitAndExecute;
	},
	[_player, _row]
] call CBA_fnc_waitUntilAndExecute;
