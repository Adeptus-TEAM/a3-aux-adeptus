#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Initialize the handler for INIDBI.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [] call ar_inidbi_fnc_initHandler
 *
 * Public: No
 */

params [];
TRACE_1("fnc_initHandler",_this);

if (isDedicated) then {
	// UIDs whose profile has been loaded (or created) this session.
	// Only these are saved, so a mission default loadout never overwrites a saved one
	// when a player disconnects (or the periodic save runs) before their profile is applied.
	GVAR(loadedUIDs) = createHashMap;

	addMissionEventHandler ["HandleDisconnect", {
		params ["_unit", "_id", "_uid", "_name"];
		if (_uid in GVAR(loadedUIDs)) then {
			[_unit,_uid] call FUNC(updatePlayerData);
			GVAR(loadedUIDs) deleteAt _uid;
		};
		false;
	}];

	[
		{
			[
				{
					{
						private _unit = _x;
						private _uid = getPlayerUID _unit; // Get the player's unique identifier (UID)
						if (_uid in GVAR(loadedUIDs)) then {
							[_unit,_uid] call FUNC(updatePlayerData);
						};
					} forEach allPlayers; // Ensure all players have their data updated
				},
				600, // every 600 seconds (10 minutes)
				nil
			] call CBA_fnc_addPerFrameHandler;
		},
		nil,
		60
	] call CBA_fnc_waitAndExecute;

	INFO("[INIDBI] Handler initialized on dedicated server.");
};
