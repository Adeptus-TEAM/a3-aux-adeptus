#include "..\script_component.hpp"
/*
 * Authors: Archer
 * Pressed
 *
 * Arguments:
 * 0: _ctrlMode (default: "") <STRING>
 *
 * Return Value:
 * Return <BOOL>
 *
 * Example:
 * [_ctrlMode] call ar_dialogs_dynamicgroups_fnc_onButtonPressed
 *
 * Public: No
 */
params [
	["_ctrlMode", "", [ "" ]]
];
TRACE_1("fnc_onButtonPressed",_this);

private _player = [] call CBA_fnc_currentUnit;
private _group = group _player;
private _availableInsignias = uiNamespace getVariable [QGVAR(availableInsignia),[]];
private _availableInsigniasCount = (count _availableInsignias);

private _current = _group getVariable ["BIS_dg_ins", ""];
private _selectorIndex = (_availableInsignias find _current) max 0;

if (_availableInsigniasCount == 0) exitWith {
	ERROR("No insignia available");
	false
};

if (isNull _player || {leader _group isNotEqualTo _player}) exitWith {
	WARNING("The player isn't the leader of the group, cannot change the insignia");
	false
};

if !(_ctrlMode in ["left", "right"]) exitWith {
	ERROR_1("Invalid _ctrlMode: %1",_ctrlMode);
	false
};
switch (_ctrlMode) do {
	case "left":  { _selectorIndex = _selectorIndex - 1 };
	case "right": { _selectorIndex = _selectorIndex + 1 };
};
if(_selectorIndex < 0)then{
	_selectorIndex = _availableInsigniasCount - 1;
	
};

if(_selectorIndex > (_availableInsigniasCount - 1))then{
	_selectorIndex = 0;
};

[_group, _availableInsignias select _selectorIndex] call SUBFUNC(setGroupInsignia);
true;
