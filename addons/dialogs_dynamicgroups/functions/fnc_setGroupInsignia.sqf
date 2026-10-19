#include "..\script_component.hpp"
/*
 * Authors: Archer
 * Sets the insignia for a group.
 *
 * Arguments:
 * 0: _group (default: grpNull) <GROUP>
 * 1: _insigniaClass (default: "") <STRING>
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [_group, _insigniaClass] call ar_dialogs_dynamicgroups_fnc_setGroupInsignia
 *
 * Public: No
 */
params [
	["_group", grpNull, [ grpNull ]],
	["_insigniaClass", "", [""]]
];
TRACE_1("fnc_setGroupInsignia",_this);

if(isNull _group)exitWith{
	ERROR("The provided group is null");
	false;
};

if(_insigniaClass isEqualTo "")exitWith{
	ERROR("The insignia class is null");
	false;
};

_group setVariable ["BIS_dg_ins", _insigniaClass, true]; // Set the insignia of the group inside of the Display
{ 
	[_x, _insigniaClass] call BIS_fnc_setUnitInsignia 
} forEach units _group; 

true;
