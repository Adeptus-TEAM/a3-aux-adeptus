#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to handle the unloading of the loadout dialog.
	 *
	 * Arguments:
	 * 0: _display (optional, default: displayNull) <DISPLAY> - The display to which the dialog is attached.
	 * 1: _exitCode (optional, default: 0) <NUMBER> - The exit code for the unload operation.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay, 1] call ar_dialogs_loadout_fnc_onUnload
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]],
	["_exitCode", 0, [0]]
];

TRACE_1("ar_dialogs_loadout_fnc_onUnload",_this);

private _playerData = uiNamespace getVariable [QGVAR(playerLoadoutData), []];
_playerData params ["_player", "_target", "_loadoutData", "_isMedic", "_isEngineer", "_isEOD"];

if (_exitCode == 1) then {
		// Handle OK case
		private _listClass = _display displayCtrl 1001;
		private _listSubClass = _display displayCtrl 1002;

		private _curSelListClass = lbCurSel _listClass;
		private _curSelListSubClass = lbCurSel _listSubClass;

		private _classSel = _listClass lbData _curSelListClass;
		private _subClassSel = _listSubClass lbData _curSelListSubClass;

		_loadoutData = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassSel >> "loadoutArray"));
		_isMedic = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "isMedic"));
		_isEngineer = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "isEngineer"));
		_isEOD = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "isEOD"));

		private _LoadoutName = [configFile >> "CfgLoadouts" >> _classSel] call BIS_fnc_displayName;
		private _LoadoutType = [configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassSel] call BIS_fnc_displayName;

		[parseText FORMAT_2(LSUBLSTRING(loadMsg),_LoadoutName,_LoadoutType), true, nil, 7, 0.7, 0] remoteExec ["BIS_fnc_textTiles", _player];
};

_player setUnitLoadout _loadoutData;

[_player, "medic", _isMedic] call EFUNC(missions,setUnitTrait);
[_player, "engineer", _isEngineer] call EFUNC(missions,setUnitTrait);
[_player, "eod", _isEOD] call EFUNC(missions,setUnitTrait);

_player cameraEffect ["terminate", "back"];
_player call BIS_fnc_ambientAnim__terminate;
