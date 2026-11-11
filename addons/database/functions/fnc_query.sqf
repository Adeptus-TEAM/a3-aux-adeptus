#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Runs an SQL_CUSTOM query asynchronously and calls back with its rows.
 *              The server never waits for MySQL: the result is polled once per frame.
 *
 * Arguments:
 * 0: _queryName <STRING> - Query name, as defined in sql_custom/adeptus.ini
 * 1: _inputs (default: []) <ARRAY> - Query inputs (no ":" allowed, it is extDB3's separator)
 * 2: _callback (default: {}) <CODE> - Called with [_rows, _callbackArgs] on success
 * 3: _callbackArgs (default: []) <ANY> - Passed to the callback
 *
 * Return Value:
 * <BOOL> - true if the query was sent
 *
 * Example:
 * ["getPlayer", [_uid], {params ["_rows"]; systemChat str _rows}] call ar_database_fnc_query
 *
 * Public: No
 */

params [
	["_queryName", "", [""]],
	["_inputs", [], [[]]],
	["_callback", {}, [{}]],
	["_callbackArgs", []]
];

TRACE_2("fnc_query",_queryName,_inputs);

if (!GVAR(enabled)) exitWith {false};

// Mode 1 = asynchronous, result kept by extDB3 until we fetch it
private _command = (["1", DB_PROTOCOL, _queryName] + (_inputs apply {if (_x isEqualType "") then {_x} else {str _x}})) joinString ":";
private _sent = parseSimpleArray (EXTDB callExtension _command);

if ((_sent select 0) isNotEqualTo 2) exitWith {
	ERROR_2("[DATABASE] Query %1 rejected: %2",_queryName,_sent);
	false
};

[{
	params ["_args", "_handle"];
	_args params ["_id", "_queryName", "_callback", "_callbackArgs"];

	private _result = EXTDB callExtension format ["4:%1", _id];
	if (_result isEqualTo "[3]") exitWith {}; // Not ready yet

	// Result too large for one call: extDB3 sends it in parts
	if (_result isEqualTo "[5]") then {
		_result = "";
		private _part = EXTDB callExtension format ["5:%1", _id];
		while {_part isNotEqualTo ""} do {
			_result = _result + _part;
			_part = EXTDB callExtension format ["5:%1", _id];
		};
	};

	[_handle] call CBA_fnc_removePerFrameHandler;

	private _parsed = parseSimpleArray _result;
	if ((_parsed select 0) isNotEqualTo 1) exitWith {
		ERROR_2("[DATABASE] Query %1 failed: %2",_queryName,_parsed);
	};
	[_parsed select 1, _callbackArgs] call _callback;
}, 0, [_sent select 1, _queryName, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;

true
