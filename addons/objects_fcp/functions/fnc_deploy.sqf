#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: This function deploys the Forward Command Post (FCP) object.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The object to be deployed.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_objects_fcp_fnc_deploy
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

TRACE_1("ar_objects_fcp_fnc_deploy",_this);

private _objectToAdd = [
	["AR_Objects_Editor_arsenalBox", [-0.2, 1.7, -1.1], 90],
	["AR_Objects_Editor_unitTraitTerminal", [-0.2, -1.8, -1.1], 180],
	["Land_HelipadEmpty_F", [-0.2, 0, -1.1], 0]
];

{
	_x params ["_className", "_offset", "_rotation"];
	private _extObject = createVehicle [_className, getPosATL _object, [], 0, "NONE"];
	_extObject setDir ((getDir _object) + _rotation);
	
	private _worldPos = _object modelToWorld _offset;
	_extObject setPosATL _worldPos;

	_object setVariable [FORMAT_1(QGVAR(deployed_%1),_className), _extObject, true];
} forEach _objectToAdd;

private _respawnObject = _object getVariable [QGVAR(deployed_Land_HelipadEmpty_F), objNull];

private _respawn = [west, _respawnObject] call BIS_fnc_addRespawnPosition;

_object setVariable [QGVAR(attachedRespawn), _respawn, true];

_object animateSource ["ramp", 0];
