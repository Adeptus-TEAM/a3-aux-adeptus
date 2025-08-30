#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Initialize a new player profile in the database.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - The player unit for which the profile will be initialized.
 *
 * Return Value:
 * <BOOL> - Returns true if the player profile was successfully initialized, false otherwise.
 *
 * Example:
 * [player] call ar_inidbi_fnc_initPlayerData
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

TRACE_1("fnc_initPlayerData",_this);

if (!isDedicated) exitWith {
	INFO("[INIDBI] This function should only be called on a dedicated server.");
	false
};

[
	{
		params ["_player"];
		!isNull _player && isPlayer _player
	}, {
		params ["_player","_UID"];
		private _UID = getPlayerUID _player; // Get the player's unique identifier (UID)

		private _inidbi = [_UID] call FUNC(createInstance); // Create a new INIDBI instance for the player

		if (isNil "_inidbi") exitWith {
			ERROR_1("[INIDBI] Failed to create INIDBI instance for %1",_UID);
			false
		};

		// Check if the player profile already exists in the INIDBI instance
		private _hasProfile = "exists" call _inidbi;

		if (_hasProfile) then {
			INFO_1("[INIDBI] Loading existing player profile for %1",_UID);
			// Load the player data from the INIDBI instance
			private _data = [_player] call FUNC(loadPlayerData);
			if (isNil "_data") exitWith {
				ERROR_1("[INIDBI] Failed to load player data for %1",_UID);
				false
			};
			[_player, _data] call FUNC(applyLoadedDataOnPlayer); // Apply the loaded data to the player unit

			[_player, _UID] call FUNC(updatePlayerData);
			INFO_1("[INIDBI] %1 profile has been loaded",_UID);
			true
		} else {
			INFO_1("[INIDBI] Creating new player profile for %1",_UID);
			// Create a new player profile in the INIDBI instance
			private _handleUpdate = [_player, _UID] call FUNC(updatePlayerData);
			if (!_handleUpdate) exitWith {
				ERROR_1("[INIDBI] Failed to create player data for %1",_UID);
				false
			};
			INFO_1("[INIDBI] %1 profile has been initialized",_UID);
			true
		};
		INFO("fnc_initPlayerData (Done)");
	},
	[_player, _UID]
] call CBA_fnc_waitUntilAndExecute;