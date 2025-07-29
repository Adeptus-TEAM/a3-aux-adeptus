#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Function to add a supply crate to the Laat Air drop module.
 *
 * Arguments:
 * 0: _control (default: controlNull) <CONTROL> - The control from which the supply crate will be added.
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [myControl] call ar_zeus_laatAirDrop_fnc_addSupply
 *
 * Public: No
 */

params [
	["_control", controlNull, [controlNull]]
];

TRACE_1("ar_zeus_laatAirDrop_fnc_addSupply",_this);

private _display = ctrlParent _control;
private _comboSupply = _display displayCtrl 1001;
private _listSeeSupply = _display displayCtrl 1002;
private _supplyList = uiNamespace getVariable [QGVAR(laatAirDropSupply), []];

private _lbselected = lbCurSel _comboSupply;

if (_lbselected < 0) exitWith {
	WARNING("fnc_addSupplyLaatAirDrop: No supply crate selected");
};

private _supplyData = _comboSupply lbData _lbselected;

private _displayname = [configFile >> "CfgVehicles" >> _supplyData] call BIS_fnc_displayName;
private _editorPreview = getText (configFile >> "CfgVehicles" >> _supplyData >> "editorPreview");

_listSeeSupply lbAdd _displayname;
_listSeeSupply lbSetData [(lbSize _listSeeSupply) - 1, _supplyData];
_listSeeSupply lbSetPicture [(lbSize _listSeeSupply) - 1, _editorPreview];

PUSH(_supplyList,_supplyData);
uiNamespace setVariable [QGVAR(laatAirDropSupply), _supplyList];
