#include "..\script_component.hpp"
/*
 * Authors: Archer
 * Description.
 *
 * Arguments:
 * 0: EventHandler (no, default: 0) <EH>
 *
 * Return Value:
 * Return description <NONE>
 *
 * Example:
 * _this call ar_weapons_grenades_fnc_empEffect
 *
 * Public: No
 */

params ["_shot", "_shooter", "_hitobj", "_pos"];
TRACE_1("fnc_empEffect",_this);

private _dekaInZone = (nearestObjects [_pos, ["3AS_Deka_Static_Base"],10]);

{
_x setVariable ["ShieldStatus", 0, true];
_x animateSource ["ShieldLayer_BaseFront",1,true]; 
_x setHitPointDamage ["HitShield",0,false];

private _particleSource = "#particleSource" createVehicleLocal ASLToAGL getPosASL _x;
_particleSource setParticleCircle [0,[0,0,0]];
_particleSource setParticleParams [
["\A3\data_f\blesk1", 1, 0, 1,0],
/* Animation */			"",
/* Type */				"spaceObject",
/* TimerPer */			1,
/* Lifetime */			0.5,
/* Position */			[0,0,1],
/* MoveVelocity */		[0,0,0.1],
/* Simulation */		0, 8.95, 7, 0, // rotationVel, weight, volume, rubbing
/* Scale */				[0.02, 0.02],
/* Color */				[[1,1,1,1], [1,1,1,1]],
/* AnimSpeed */			[1.5, 0.5],
/* randDirPeriod */		0,
/* randDirIntensity */	0,
/* onTimerScript */		"",
/* DestroyScript */		"",
/* object */			_this
];

_particleSource setParticleRandom [0, [0.25, 0.25, 0], [0.175, 0.175, 0], 0, 0.25, [0, 0, 0, 0.1], 0, 0];
_particleSource setDropInterval 0.05;

[{params["_particleSource"]; deleteVehicle _particleSource;},[_particleSource],1] call CBA_fnc_waitAndExecute;
} forEach _dekaInZone;
