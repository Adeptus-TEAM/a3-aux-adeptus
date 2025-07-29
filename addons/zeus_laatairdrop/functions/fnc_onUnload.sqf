#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to handle the unloading of the Laat Air drop module.
	 *
	 * Arguments:
	 * 0: _display (default: displayNull) <DISPLAY> - The display from which the Laat Air drop module will be unloaded.
	 * 1: _exitCode (default: 0) <NUMBER> - The exit code for the unload operation.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay, 0] call ar_zeus_laatAirDrop_fnc_onUnload
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]],
	["_exitCode", 0, [0]]
];

TRACE_1("ar_zeus_laatAirDrop_fnc_onUnload",_this);

// Clean up the module variable in the uiNamespace
private _module = uiNamespace getVariable [QGVAR(laatAirDropModule), objNull];
uiNamespace setVariable [QGVAR(laatAirDropModule), objNull];

// Clean up the display variable
uiNamespace setVariable [QGVAR(RscLaatAirDrop), displayNull];

switch (_exitCode) do {
	case 1: {
		// Handle OK case
		if (!isNull _module) then {
			private _dropList = uiNamespace getVariable [QGVAR(laatAirDropSupply), []];
			private _sliderSetDir = _display displayCtrl 1003;
			private _sliderSetHeight = _display displayCtrl 1005;

			private _dropHeight = sliderPosition _sliderSetHeight;
			private _dropDirection = [0, 45, 90, 135, 180, 225, 270, 315] select (sliderPosition _sliderSetDir);

			// call the function to perform the air drop
			[_module, _dropList, _dropHeight, _dropDirection] call SUBFUNC(dropSupply);
		} else {
			WARNING("ar_zeus_laatAirDrop_fnc_onUnload: Module not found in uiNamespace");
			_display closeDisplay 0;
		};
	};
	default {
		// Handle Cancel or other cases
			[
				LSUBLSTRING(header),
				LSUBLSTRING(drop_cancel),
				5
			] call BIS_fnc_curatorHint;

		// Delete the module if it exists
		deleteVehicle _module;
	};
};
