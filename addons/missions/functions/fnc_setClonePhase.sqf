#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Sets the clone phase for a object.
 *
 * Arguments:
 * 0: _object (default: "objNull") <OBJECT> - The object to set the clone phase for.
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [this] call ar_missions_fnc_setClonePhase
 *
 * Public: No
 */

params [
	["_object", objNull, [objNull]]
];

if (!isServer) exitWith {
	INFO("ar_missions_fnc_setClonePhase: This function can only be executed on the server.");
};

TRACE_1("ar_missions_fnc_setClonePhase",_this);

private _phase = getMissionConfigValue [QGVAR(clonePhase), 2];

if (isNull _object) exitWith {
	WARNING("ar_missions_fnc_setClonePhase: Invalid object");
};

if (_object isKindOf "Man") then {
	// It's a unit
	if (_phase != 2) then {
		_object addHeadgear "AR_V2_P1_helmet";
		TRACE_1("ar_missions_fnc_setClonePhase: Set phase 1 for unit",_object);
	} else {
		_object addHeadgear "AR_V2_P2_helmet";
		TRACE_1("ar_missions_fnc_setClonePhase: Set phase 2 for unit",_object);
	};
} else {
	// It's a object
	private _helmets = [];
	if (_phase != 2) then {
		_helmets = ["AR_V1_P1_Headgear", "AR_V2_P1_Headgear"];
		TRACE_1("ar_missions_fnc_setClonePhase: Set phase 1 for object",_object);
	} else {
		_helmets = ["AR_V1_P2_Headgear", "AR_V2_P2_Headgear"];
		TRACE_1("ar_missions_fnc_setClonePhase: Set phase 2 for object",_object);
	};
	private _helmet = selectRandom _helmets;
	private _dir = vectorDir _object;
	private _up = vectorUp _object;
	private _pos = getPosATL _object;
	deleteVehicle _object;
	private _newHelmet = createVehicle [_helmet, _pos, [], 0, "NONE"];
	_newHelmet setPosATL _pos;
	_newHelmet setVectorDirAndUp [_dir, _up];
};
