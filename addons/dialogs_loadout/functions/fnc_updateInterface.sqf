#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to update the loadout menu.
	 *
	 * Arguments:
	 * 0: _control (default: controlNull) <CONTROL> - The control that triggered the update.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myControl] call ar_dialogs_loadout_fnc_updateInterface
	 *
	 * Public: No
 */

params [
	["_control", controlNull, [controlNull]]
];

TRACE_1("ar_dialogs_loadout_fnc_updateInterface",_this);

private _display = ctrlParent _control;

private _listClass = _display displayCtrl 1001;
private _listSubClass = _display displayCtrl 1002;
private _listEquipement = _display displayCtrl 1003;
private _infoIsEngineer = _display displayCtrl 1004;
private _infoIsEOD = _display displayCtrl 1005;
private _infoIsMedic = _display displayCtrl 1006;
private _titleSubClass = _display displayCtrl 1007;
private _titleEquipement = _display displayCtrl 1008;

lbClear _listSubClass;
lbClear _listEquipement;

private _curSelListClass = lbCurSel _listClass;

if (_curSelListClass != -1) then {
	_listSubClass ctrlShow true;
	_titleSubClass ctrlShow true;
	private _classSel = _listClass lbData _curSelListClass;
	[_listSubClass, _classSel] call SUBFUNC(updateSubClass);
	private _curSelListLoadoutType = lbCurSel _listSubClass;
	if (_curSelListLoadoutType != -1) then {
		_listEquipement ctrlShow true;
		_infoIsEngineer ctrlShow true;
		_infoIsEOD ctrlShow true;
		_infoIsMedic ctrlShow true;
		_titleEquipement ctrlShow true;
		private _subClassSel = _listSubClass lbData _curSelListLoadoutType;
		[_listEquipement, _classSel, _subClassSel] call SUBFUNC(updateEquipments);
		[_classSel, _infoIsEngineer, _infoIsEOD, _infoIsMedic] call SUBFUNC(updateInfoTraits);
	} else {
		_listEquipement ctrlShow false;
		_infoIsEngineer ctrlShow false;
		_infoIsEOD ctrlShow false;
		_infoIsMedic ctrlShow false;
		_titleEquipement ctrlShow false;
	};
} else {
	_listSubClass ctrlShow false;
	_listEquipement ctrlShow false;
	_infoIsEngineer ctrlShow false;
	_infoIsEOD ctrlShow false;
	_infoIsMedic ctrlShow false;
	_titleSubClass ctrlShow false;
	_titleEquipement ctrlShow false;
};
