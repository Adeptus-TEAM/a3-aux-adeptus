#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Adds a respawn beacon to the object.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to add the respawn beacon to.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_misc_respawnBeacon_fnc_createNew
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

if (is3DEN) exitWith {};

TRACE_1("ar_misc_respawnBeacon_fnc_createNew",_this);

// play anim for the unit
_unit setVariable [QGVAR(isBuilding), true, true]; // Set the isBuilding variable to true
_unit playMoveNow "AinvPknlMstpSnonWnonDnon_medic4"; // Animation de construction

// S'assurer que l'animation continue tant que la progress bar est active
private _handler = [
	{
		_this#0 params ["_unit"];
		if(!(_unit getVariable [QGVAR(isBuilding), false])) exitWith {
			// If the unit is not building, stop the animation
			_unit playMoveNow "";
		};
		// If the unit is building, continue the animation
		_unit playMoveNow "AinvPknlMstpSnonWnonDnon_medic4";
	},
	3,  // toutes les 3 secondes
	[_unit]
] call CBA_fnc_addPerFrameHandler;

// Progress bar for creating the respawn beacon
[
	LSUBLSTRING(Building),
	30, // Duration in seconds
	{true},
	{
		_this#0 params ["_unit", "_handler"];
		// Stop the animation for the unit
		_unit setVariable [QGVAR(isBuilding), false, true]; // Set the isBuilding variable to false
		_handler call CBA_fnc_removePerFrameHandler; // Remove the per frame handler

		// delete item from the unit's inventory
		_unit removeItem QSUBCVAR(item); // Remove the respawn beacon item from the unit's inventory

		// Get the position of the unit in ATL coordinates
		private _posATL = getPosATL _unit;

		// Adjust the position in front of the unit
		private _offsetPos = [
			(_posATL select 0) + (sin (getDir _unit) * 2),
			(_posATL select 1) + (cos (getDir _unit) * 2),
			_posATL select 2 + 0.1
		];

		// Create the respawn beacon objects
		private _object1 = createVehicle [QSUBCVAR(Active), [0,0,0]];
		
		_object1 enableSimulationGlobal false; // Disable simulation for the object to prevent it from being affected by physics
		_object1 setPosATL [0,0,0]; // Set the position of the active beacon object to a temporary position
		_object1 setVectorUp [0, 0, 1]; // Set the up vector of the active beacon object to ensure it is upright
		_object1 setPosATL _offsetPos; // Set the position of the active beacon object to the calculated offset position
		_object1 setVectorUp (surfaceNormal (getPosATL _object1)); // Set the up vector of the active beacon object to the surface normal at its position

		// Create a respawn position for the object
		private _respawn = [west, getPosATL _object1] call BIS_fnc_addRespawnPosition;
		_object1 setVariable [QSUBCVAR(respawnEntity), _respawn];
	},
	{
		_this#0 params ["_unit"];
		// Stop the animation for the unit
		_unit setVariable [QGVAR(isBuilding), false, true];

		hint LSUBLSTRING(aborted);
	},
	[_unit, _handler]
] call CBA_fnc_progressBar;
