#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: This function checks if the Forward Command Post (FCP) can be undeployed.
	 *
	 * Arguments:
	 * 0: _object (default: objNull) <OBJECT> - The object to be checked for undeployment.
	 * 1: _unit (default: objNull) <OBJECT> - The unit attempting to undeploy the FCP.
	 *
	 * Return Value:
	 * <BOOLEAN> - Returns true if the FCP can be undeployed, false otherwise.
	 *
	 * Example:
	 * [this, player] call ar_objects_fcp_fnc_canUndeploy
	 *
	 * Public: No
 */

params [
	["_object", objNull, [objNull]],
	["_unit", objNull, [objNull]]
];

// Check if the FCP is deployed
if ((_object animationSourcePhase "ramp") >= 0.5) exitWith {
	false
};

// Check if the unit has the required trait
if (_unit getUnitTrait 'Engineer' != true) exitWith {
	false
};

true
