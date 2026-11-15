#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to open the garage interface.
	 *
	 * Arguments:
	 * 0: _terminal (default: objNull) <OBJECT> - The terminal object to open the garage interface for.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [monTerminal] call ar_dialogs_garage_fnc_openInterface
	 *
	 * Public: No
 */

params [
	["_terminal", objNull, [objNull]]
];

TRACE_1("ar_dialogs_garage_fnc_openInterface",_this);

uiNamespace setVariable [QGVAR(garageObject), _terminal];

createDialog "RscGarage";
