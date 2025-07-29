#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Function to delete a supply crate from the Laat Air drop module.
 *
 * Arguments:
 * 0: _control (default: controlNull) <CONTROL> - The control from which the supply crate will be deleted.
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [myControl] call ar_zeus_fnc_deleteSupply
 *
 * Public: No
 */

params [
	["_control", controlNull, [controlNull]]
];

TRACE_1("ar_zeus_fnc_deleteSupply",_this);

private _display = ctrlParent _control;
private _listSeeSupply = _display displayCtrl 1002;
private _supplyList = uiNamespace getVariable [QGVAR(laatAirDropSupply), []];

private _lbselected = lbCurSel _listSeeSupply;

if (_lbselected < 0) exitWith {
	WARNING("ar_zeus_fnc_deleteSupply: No supply crate selected");
};

private _supplyData = _listSeeSupply lbData _lbselected;

_listSeeSupply lbDelete _lbselected;

REM(_supplyList,_supplyData);
uiNamespace setVariable [QGVAR(laatAirDropSupply), _supplyList];
