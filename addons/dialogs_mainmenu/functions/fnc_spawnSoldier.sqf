#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Shows the player's soldier in the main menu scene, dressed with the "Main" loadout
 *              cached on this PC (see fnc_cacheLoadout). Without a cached loadout, the unit keeps its default gear.
 *
 *              The scene decides where the soldier stands, with an object named "menu_soldier" (3DEN, Variable Name):
 *              - a unit: it is dressed directly, keeping its position and animation;
 *              - any other object (helper arrow, sign...): it is hidden and a unit is created at its place.
 *              Without "menu_soldier", the soldier is placed in front of the camera ("cam_pos"), on the right.
 *              In every case the soldier is turned to face the camera.
 *
 * Arguments:
 * 0: _defaultClass (default: "AR_V1_P2_Unit") <STRING> - Unit class created when the scene has no "menu_soldier" unit
 *
 * Return Value:
 * <OBJECT> - The soldier, or objNull
 *
 * Example:
 * ["AR_V1_P1_Unit"] call (uiNamespace getVariable "AR_Dialogs_MainMenu_fnc_spawnSoldier")
 *
 * Public: No
 */

params [["_defaultClass", "AR_V1_P2_Unit", [""]]];

// Fallback placement, in meters from the camera
#define SOLDIER_FORWARD 3.2
#define SOLDIER_RIGHT 0.85

private _marker = missionNamespace getVariable ["menu_soldier", objNull];
private _soldier = objNull;
private _keepPose = false;

if (!isNull _marker && {_marker isKindOf "CAManBase"}) then {
	// The scene placed the soldier itself
	_soldier = _marker;
	_keepPose = true;
} else {
	private "_pos";
	if (!isNull _marker) then {
		_pos = getPosASL _marker;
		_marker hideObject true;
	} else {
		private _camera = missionNamespace getVariable ["cam_pos", objNull];
		if (isNull _camera) exitWith {};
		private _camDir = getDir _camera;
		_pos = (getPosASL _camera) vectorAdd [
			(sin _camDir) * SOLDIER_FORWARD + (sin (_camDir + 90)) * SOLDIER_RIGHT,
			(cos _camDir) * SOLDIER_FORWARD + (cos (_camDir + 90)) * SOLDIER_RIGHT,
			0
		];
	};
	if (isNil "_pos") exitWith {};

	_soldier = createAgent [_defaultClass, [0, 0, 0], [], 0, "CAN_COLLIDE"];
	_soldier setPosASL _pos;
	{_soldier disableAI _x} forEach ["MOVE", "ANIM", "FSM", "TARGET", "AUTOTARGET"];
};

if (isNull _soldier) exitWith {
	WARNING("Main menu scene: no menu_soldier and no cam_pos, no soldier shown");
	objNull
};

// Always face the camera. The scene camera is created at the "cam_pos" object; the engine camera itself
// may not be in place yet when this runs, so cam_pos is the reliable reference.
private _camera = missionNamespace getVariable ["cam_pos", objNull];
if (!isNull _camera) then {
	_soldier setDir (_soldier getDir _camera);
};

private _loadout = profileNamespace getVariable [PROFILE_LOADOUT, []];
if (_loadout isEqualType [] && {_loadout isNotEqualTo []}) then {
	_soldier setUnitLoadout _loadout;
};

// Relaxed standing pose (the idle loops of BIS_fnc_ambientAnim "STAND" / "STAND_U1"), with or without rifle.
// BIS_fnc_ambientAnim itself relies on sleep / time, which may not run in the menu scene, so the loop is
// done here: when one idle animation ends, another one starts.
// A unit placed by the scene keeps its own animation (set in its init field).
if (!_keepPose) then {
	private _poses = [
		["HubStandingUA_idle1", "HubStandingUA_idle2", "HubStandingUA_idle3"],
		["HubStanding_idle1", "HubStanding_idle2", "HubStanding_idle3"]
	] select (primaryWeapon _soldier != "");

	_soldier setVariable [QGVAR(poses), _poses];
	_soldier switchMove selectRandom _poses;
	_soldier addEventHandler ["AnimDone", {
		params ["_soldier"];
		_soldier switchMove selectRandom (_soldier getVariable [QGVAR(poses), ["HubStanding_idle1"]]);
	}];
};

_soldier
