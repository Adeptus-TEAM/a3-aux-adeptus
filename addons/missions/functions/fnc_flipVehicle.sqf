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

_vehicle addAction [LLSTRING(FLIPVEHICLE), 
{
	params ["_target", "_caller", "_actionId", "_arguments"];

    private _up = vectorUp _target;
    _target setVectorUp [_up select 0, _up select 1, 1];
	_target setPosATL ((getPosATL _target) vectorAdd [0,0,1.5]);

},
nil,
1.5,
true,
true,
"",
"(vectorUp _target) select 2 < 0",
8
];

true
