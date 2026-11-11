#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Runs an SQL_CUSTOM query asynchronously, without waiting for a result (writes).
 *
 * Arguments:
 * 0: _queryName <STRING> - Query name, as defined in sql_custom/adeptus.ini
 * 1: _inputs (default: []) <ARRAY> - Query inputs (no ":" allowed, it is extDB3's separator)
 *
 * Return Value:
 * <BOOL> - true if extDB3 accepted the query
 *
 * Example:
 * ["savePlayer", ["Main", _uid, _name, _loadout, 1, 0, 0]] call ar_database_fnc_execute
 *
 * Public: No
 */

params [
	["_queryName", "", [""]],
	["_inputs", [], [[]]]
];

TRACE_1("fnc_execute",_queryName);

if (!GVAR(enabled)) exitWith {false};

// Mode 2 = asynchronous, result discarded
private _command = (["2", DB_PROTOCOL, _queryName] + (_inputs apply {if (_x isEqualType "") then {_x} else {str _x}})) joinString ":";
private _result = parseSimpleArray (EXTDB callExtension _command);

if ((_result select 0) isNotEqualTo 1) exitWith {
	ERROR_2("[DATABASE] Query %1 rejected: %2",_queryName,_result);
	false
};

true
