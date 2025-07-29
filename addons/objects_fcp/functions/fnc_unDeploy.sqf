#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: This function undoes the deployment of the Forward Command Post (FCP) object.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The object to be undeployed.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_objects_fcp_fnc_unDeploy
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("ar_objects_fcp_fnc_unDeploy",_this);

private _objectToRemove = [
	"AR_Objects_Editor_arsenalBox",
	"AR_Objects_Editor_unitTraitTerminal",
	"Land_HelipadEmpty_F"
];

// Remove respawn position
private _respawn = _object getVariable [QGVAR(attachedRespawn), []];
_respawn call BIS_fnc_removeRespawnPosition;
_object setVariable [QGVAR(attachedRespawn), [], true];

// Remove all deployed objects
{
	private _extObject = _object getVariable [FORMAT_1(QGVAR(deployed_%1),_x), objNull];
	deleteVehicle _extObject;
	_object setVariable [FORMAT_1(QGVAR(deployed_%1),_x), objNull, true];
} forEach _objectToRemove;

// Reset the ramp animation
_object animateSource ["ramp", 1];
