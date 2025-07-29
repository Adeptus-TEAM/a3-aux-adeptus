#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Creates a new INIDBI instance.
 *
 * Arguments:
 * 0: _UID (default: "") <OBJECT> - The unique identifier for the player.
 *
 * Return Value:
 * <INIDB2 OBJECT> - Returns a new INIDBI instance for the specified UID.
 *
 * Example:
 * ["123456789"] call ar_inidbi_fnc_createInstance
 *
 * Public: No
 */

params [
	["_UID", "", [""]]
];

TRACE_1("fnc_createInstance",_this);

if (_UID isEqualTo "") exitWith {
	ERROR_1("[INIDBI] Invalid UID provided: %1",_UID);
};

private _inidbi = ["new", _UID] call OO_inidbi; // Create a new INIDBI instance

if (isNil "_inidbi") exitWith {
	ERROR_1("[INIDBI] Failed to create INIDBI instance for %1",_UID);
};

TRACE_1("fnc_createInstance (Done)",_inidbi);
_inidbi
