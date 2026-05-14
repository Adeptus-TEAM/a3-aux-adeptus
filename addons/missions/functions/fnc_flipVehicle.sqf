#include "..\script_component.hpp"
/*
 * Authors: You
 * Description.
 *
 * Arguments:
 * 0: Argument (optional, default: value) <OBJECT>
 *
 * Return Value:
 * Return description <NONE>
 *
 * Example:
 * [params] call PREFIX_missions_fnc_flipVehicle
 *
 * Public: No
 */

params [
	["_vehicle", objNull, [objNull]]
];
TRACE_1("fnc_flipVehicle",_this);

if(isNull _vehicle) exitWith {
	WARNING("fnc_flipVehicle: No vehicle provided");
	false;
};
/*
 1 : Test if the vehicles is alive.
 2 : Test if the player doing the holdAction has a distance of 8 meters maximum
 3 : Test if the vehicle is flipped.
 4 : Test if the vehicle is at least from 5 meter from the ground
 5 : Test if the player (_this) is on foot, Enable the trigger when the player is on foot
 6 : Test if the vehicle is on water (if it is can't flip).
 7 : Test if the crew has exited the vehicle.
*/
 
private _canBeFlipped = "(alive _target) && 
					  ((_this distance _target) <= 8) &&
                      ((vectorUp _target) select 2 < 0)  && 
                      (((getPosATL _target)select 2) <= 5) && 
                      ((vehicle _this) == _this) &&
                      !(surfaceIsWater (position _target)) &&
					  ((crew _target) isEqualTo [])";

[
	_vehicle,
	LLSTRING(FLIPVEHICLE),
	"\a3\data_f_destroyer\data\UI\IGUI\Cfg\holdactions\holdAction_unloadVehicle_ca.paa", "\a3\data_f_destroyer\data\UI\IGUI\Cfg\holdactions\holdAction_unloadVehicle_ca.paa",
	_canBeFlipped, _canBeFlipped,
	{}, // CodeStart
	{}, // CodeProgress
	{	
	params ["_target", "_caller", "_actionId", "_arguments"];
    private _up = vectorUp _target;
    _target setVectorUp [_up select 0, _up select 1, 1];
	_target setPosATL ((getPosATL _target) vectorAdd [0,0,1.5]);
	
}, // CodeCompleted
	{}, // CodeInterrupted
	[], // Arguments
	5, // Duration
	nil, // Priority
	false, // removeCompleted
	false // ShowUnconscious
] call BIS_fnc_holdActionAdd;

true
