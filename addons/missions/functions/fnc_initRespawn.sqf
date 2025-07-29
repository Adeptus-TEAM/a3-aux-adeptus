#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Initialize respawn for the player
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit object to initialize respawn for.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_missions_fnc_initRespawn
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

if (is3DEN) exitWith {};

TRACE_1("ar_missions_fnc_initRespawn",_this);

[
	_unit,
	"Respawn",
	{
		_this remoteExec [QFUNC(onRespawn), _this#0, false];
	},
	nil
] call CBA_fnc_addBISEventHandler;

[_unit] call FUNC(initRespawnDelay);
