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
	addMissionEventHandler ["HandleDisconnect", {
		params ["_unit", "_id", "_uid", "_name"];
		[_unit,_uid] call FUNC(updatePlayerData);
		false; 
	}];
	
	[
		{
			{
				private _unit = _x;
				private _uid = getPlayerUID _unit; // Get the player's unique identifier (UID)
				[_unit,_uid] call FUNC(updatePlayerData);
			} forEach allPlayers; // Ensure all players have their data updated
		},
		600, // every 600 seconds (10 minutes)
		nil
	] call CBA_fnc_addPerFrameHandler;

	INFO("[INIDBI] Handler initialized on dedicated server.");
};
