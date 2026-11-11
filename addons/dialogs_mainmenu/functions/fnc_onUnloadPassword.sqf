#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: On "Connect" (exit code 1): saves or forgets the password, then connects to the selected server.
 *
 * Arguments:
 * 0: _display <DISPLAY> - The password dialog
 * 1: _exitCode <NUMBER> - 1 when "Connect" was pressed
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [_display, 1] call AR_Dialogs_MainMenu_fnc_onUnloadPassword
 *
 * Public: No
 */

params [["_display", displayNull, [displayNull]], ["_exitCode", 0, [0]]];

TRACE_1("fnc_onUnloadPassword",_exitCode);

if (_exitCode != 1) exitWith {};

private _password = ctrlText (_display displayCtrl IDC_PWD_INPUT);
private _remember = cbChecked (_display displayCtrl IDC_PWD_REMEMBER);

// The password is only kept on this PC if the player asked for it
profileNamespace setVariable [PROFILE_REMEMBER, _remember];
profileNamespace setVariable [PROFILE_PASSWORD, ["", _password] select _remember];
saveProfileNamespace;

(uiNamespace getVariable [QGVAR(server), []]) params [["_address", ""], ["_port", 2302]];
if (_address isEqualTo "") exitWith {
	WARNING("No server selected");
};

INFO_2("Connecting to %1:%2",_address,_port);
connectToServer [_address, _port, _password];
