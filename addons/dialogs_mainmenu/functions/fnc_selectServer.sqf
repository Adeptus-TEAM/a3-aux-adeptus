#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Stores the selected server and opens the password dialog.
 *
 * Arguments:
 * 0: _index <NUMBER> - 1: main server, 2: training server, 3: OPEX server
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [1] call AR_Dialogs_MainMenu_fnc_selectServer
 *
 * Public: No
 */

params [["_index", 1, [0]]];

TRACE_1("fnc_selectServer",_index);

private _server = [
	["main.adeptus-team.eu", 2302, LSUBLSTRING(nameMain)],
	["training.adeptus-team.eu", 2332, LSUBLSTRING(nameTraining)],
	["opex.adeptus-team.eu", 2302, LSUBLSTRING(nameOpex)]
] param [_index - 1, []];

if (_server isEqualTo []) exitWith {
	WARNING_1("Unknown server index %1",_index);
};

_server params ["_address", "_port", "_name"];
uiNamespace setVariable [QGVAR(server), [_address, _port, _name]];
INFO_2("Server selected: %1:%2",_address,_port);

(findDisplay 0) createDisplay "RscCheckPassword";
