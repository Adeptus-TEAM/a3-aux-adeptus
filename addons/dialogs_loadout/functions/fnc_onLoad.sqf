#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to initialize the loadout dialog.
	 *
	 * Arguments:
	 * 0: _display (default: displayNull) <DISPLAY> - The display to which the dialog will be attached.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay] call ar_dialogs_loadout_fnc_onLoad
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]]
];

TRACE_1("ar_dialogs_loadout_fnc_onLoad",_this);

private _listClass = _display displayCtrl 1001;
private _listSubClass = _display displayCtrl 1002;
private _listEquipement = _display displayCtrl 1003;
private _infoIsEngineer = _display displayCtrl 1004;
private _infoIsEOD = _display displayCtrl 1005;
private _infoIsMedic = _display displayCtrl 1006;
private _titleSubClass = _display displayCtrl 1007;
private _titleEquipement = _display displayCtrl 1008;

// hide unused controls
_listSubClass ctrlShow false;
_listEquipement ctrlShow false;
_infoIsEngineer ctrlShow false;
_infoIsEOD ctrlShow false;
_infoIsMedic ctrlShow false;
_titleSubClass ctrlShow false;
_titleEquipement ctrlShow false;

// set listclass
private _allLoadout = "true" configClasses (configFile >> "CfgLoadouts");

{
    private _classname = configName _x;
	private _index = _listClass lbAdd ([configFile >> "CfgLoadouts" >> _classname] call BIS_fnc_displayName);
    _listClass lbSetPicture [_index, getText (configFile >> "CfgLoadouts" >> _classname >> "icon")];
    _listClass lbSetData [_index, _classname];
} forEach _allLoadout;

private _playerData = uiNamespace getVariable [QGVAR(playerLoadoutData), []];
_playerData params ["_player", "_target"];

// init player animation
[_player, selectRandom ["STAND1", "STAND2", "STAND_U1", "STAND_U2", "STAND_U3"], "ASIS"] call BIS_fnc_ambientAnim;

// create simple camera
private _simpleCamObj = "#particleSource" createVehicleLocal position _player;
private _camera = "camera" camCreate (ASLToAGL eyePos _target);
[
	{
		params ["_simpleCamObj", "_camera", "_player", "_target"];
		// set camera properties
		_simpleCamObj attachTo [_player, [0.02, 0, 0.05], "Pelvis"];
		_camera cameraEffect ["internal", "back"];
		_camera attachTo [_target, [0, 0, 0], "head"];
		_camera camPrepareTarget _simpleCamObj;
		_camera camPreparePos getPos _target;
		_camera camPrepareFov 0.5;
		_camera camCommitPrepared 0;
		showCinemaBorder false;
	},
	[_simpleCamObj, _camera, _player, _target],
	0.1
] call CBA_fnc_waitAndExecute;
