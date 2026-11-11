#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Connects extDB3 to the MySQL database and registers the SQL_CUSTOM protocol.
 *              extDB3 keeps its connection across missions, so this is only done once per server start.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <BOOL> - true if the database is ready
 *
 * Example:
 * [] call ar_database_fnc_init
 *
 * Public: No
 */

TRACE_1("fnc_init",_this);

GVAR(enabled) = false;

if (EXTDB callExtension "9:VERSION" isEqualTo "") exitWith {
	ERROR("[DATABASE] extDB3 is not loaded on the server: player data will not be saved.");
	false
};

// Already set up by a previous mission since the server started
if (uiNamespace getVariable [QGVAR(ready), false]) exitWith {
	GVAR(enabled) = true;
	INFO("[DATABASE] extDB3 already connected.");
	true
};

private _result = parseSimpleArray (EXTDB callExtension format ["9:ADD_DATABASE:%1", DB_NAME]);
if ((_result select 0) isNotEqualTo 1) exitWith {
	ERROR_1("[DATABASE] Database connection failed: %1",_result);
	false
};

_result = parseSimpleArray (EXTDB callExtension format ["9:ADD_DATABASE_PROTOCOL:%1:SQL_CUSTOM:%2:%3", DB_NAME, DB_PROTOCOL, DB_SQL_FILE]);
if ((_result select 0) isNotEqualTo 1) exitWith {
	ERROR_1("[DATABASE] SQL_CUSTOM protocol registration failed: %1",_result);
	false
};

// Lock extDB3: no more databases or protocols can be added until the server restarts
EXTDB callExtension "9:LOCK";

uiNamespace setVariable [QGVAR(ready), true];
GVAR(enabled) = true;
INFO("[DATABASE] extDB3 connected.");
true
