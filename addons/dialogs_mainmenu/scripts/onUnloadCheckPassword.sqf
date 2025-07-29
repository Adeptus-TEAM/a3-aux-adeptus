#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to check if the password is correct before unloading the dialog.
	 *
	 * Arguments:
	 * 0: _display (default: displayNull) <DISPLAY> - The display that is being unloaded.
	 * 1: _exitCode (default: 0) <NUMBER> - The exit code for the unload operation.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay,1] execVM '\x\ar\addons\dialogs_mainmenu\scripts\onUnloadCheckPassword.sqf';
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]],
	["_exitCode", 0, [0]]
];

TRACE_1("onUnloadCheckPassword.sqf",_this);

switch (_exitCode) do {
	case 1: {
		INFO("Exit code is 1, checking password.");
		private _inputPassword = profileNamespace getVariable [QGVAR(PasswordSaved), ""];
		TRACE_1("Password input retrieved",_inputPassword);
		if (_inputPassword isEqualTo "") then {
			INFO("Password input is empty.");
		} else {
			TRACE_1("Password input is not empty.",_inputPassword);
			INFO("Attempting to connect to server with provided password.");
			connectToServer [
				uiNamespace getVariable [QGVAR(ServerAddress), "localhost"],
				uiNamespace getVariable [QGVAR(ServerPort), 2302],
				_inputPassword
			];
		};
	};
	default {
		INFO("Exit code is not 1, closing display without checking password.");
	};
};
