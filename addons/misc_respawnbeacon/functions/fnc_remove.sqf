#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Removes a respawn beacon and creates a ground item at its position.
 *
 * Arguments:
 * 0: _object (default: objNull) <OBJECT> - The respawn beacon object to be removed.
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [this] call ar_misc_respawnBeacon_fnc_remove
 *
 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("ar_misc_respawnBeacon_fnc_remove",_this);

private _respawnPos = getPosATL _object;
(_object getVariable [QSUBCVAR(respawnEntity), objNull]) call BIS_fnc_removeRespawnPosition;
deleteVehicle _object;
private _respawnBeaconItem = createVehicle [QSUBCVAR(GroundItem), _respawnPos, [], 0, "NONE"];
_respawnBeaconItem setPosATL _respawnPos;
