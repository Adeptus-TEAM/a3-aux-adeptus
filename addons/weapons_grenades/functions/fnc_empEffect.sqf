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

private _droidClassList = [
"ls_droid_base",
"WBK_3AS_B1_Baseclass",
"WBK_LS_B1_Baseclass",
"JLTS_Droid_B1_AR",
"JLTS_Droid_B1_AT",
"JLTS_Droid_B1_Commander",
"JLTS_Droid_B1_Crew",
"JLTS_Droid_B1_E5",
"JLTS_Droid_B1_Marine",
"JLTS_Droid_B1_OOM9",
"JLTS_Droid_B1_Pilot",
"JLTS_Droid_B1_Prototype",
"JLTS_Droid_B1_UAV_prowler",
"JLTS_Droid_B1_Rocket",
"JLTS_Droid_B1_SBB3",
"JLTS_Droid_B1_Security",
"JLTS_Droid_B1_Sniper",
"3AS_CIS_TS_Base",
"WBK_LS_B2_Baseclass"
];

private _dekaInZone = (nearestObjects [_pos, ["3AS_Deka_Static_Base"],5,true]);
private _droidInZone = (nearestObjects [_pos, _droidClassList,5,true]);

{
if(alive _x)then{
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
};
} forEach _dekaInZone;

{
if(alive _x)then{
	private _particleSource = "#particleSource" createVehicleLocal ASLToAGL getPosASL _x;
	_particleSource attachTo [_x, [0,0,0]];
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
	/* Scale */				[0.008, 0.008],
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

_x setDamage 1;


};
} forEach _droidInZone;