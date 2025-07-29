#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Handles tasks for players when they are unconscious.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to handle tasks for.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_missions_fnc_unconsciousPlayerTasks
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

TRACE_1("fnc_unconsciousPlayerTasks",_this);

PUSH(GVAR(unconsciousPlayers),_unit);

// Create the task for medics when a player is unconscious
private _medics = allPlayers select {
	(_x getUnitTrait "Medic")
};

private _taskID = FORMAT_2(QGVAR(TRIPLES(unconsciousTask,%1,%2)),(round time),_unit);

private _taskDescription = [
	FORMAT_4(LLSTRING(unconscious_task_description),name _unit,systemTime#3,systemTime#4,mapGridPosition _unit), // "%1 a besoin d'un médecin!<br/><br/>Il est blessé depuis %2h%3. Il se trouve en %4."
	FORMAT_1(LLSTRING(unconscious_task_name),(name _unit)), //"Soigner : %1"
	"heal"
];

private _task = [_medics, _taskID, _taskDescription, [_unit, true], "AUTOASSIGNED", 0, true, "heal"] call BIS_fnc_taskCreate;

// Spawn a new thread to handle the unconscious player
[
	{
		params ["_unit"];
		(lifeState _unit != "INCAPACITATED") || (isNull _unit)
	},
	{
		_this call FUNC(consciousPlayerTasks);		
	},
	[_unit, _taskID]
] call CBA_fnc_waitUntilAndExecute;
