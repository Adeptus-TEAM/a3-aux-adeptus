#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Handles tasks for players when they are conscious.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to handle tasks for.
	 * 1: _taskID (default: "") <STRING> - The ID of the task to create.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_missions_fnc_consciousPlayerTasks
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]],
	["_taskID", "", [""]]
];

TRACE_1("fnc_consciousPlayerTasks",_this);

// Check if the unit life state
switch (lifeState _unit) do {
	case "HEALTHY": {
		[_taskID, "SUCCEEDED"] call BIS_fnc_taskSetState;
	};
	default {
		[_taskID, "FAILED"] call BIS_fnc_taskSetState;
	};
};

// Remove the unit from the unconscious players list
REM(GVAR(unconsciousPlayers),_unit);

// Delete the task after a delay
[
	{
		params ["_taskID"];
		[_taskID] call BIS_fnc_deleteTask;
	},
	[_taskID],
	60
] call CBA_fnc_waitAndExecute;
