#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Handle the respawn of a unit
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit object that has respawned.
	 * 1: _corpse (default: objNull) <OBJECT> - The corpse object of the unit that has respawned.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player, oldPlayer] call ar_missions_fnc_onRespawn
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

TRACE_1("ar_missions_fnc_onRespawn",_this);

// This is not needed anymore, thx ace !
// private _oldPlayerLoadout = getUnitLoadout _corpse;
// deleteVehicle _corpse;
// _unit setUnitLoadout _oldPlayerLoadout;

_unit switchMove "amovpercmstpsraswrfldnon";

[_unit] call FUNC(playRespawnAnimation);
