#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Handles the unloading of mission parameters.
	 *
	 * Arguments:
	 * 0: _display (default: displayNull) <DISPLAY> - The display from which the Laat Air drop module will be unloaded.
	 * 1: _exitCode (default: 0) <NUMBER> - The exit code for the unload operation.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay, 0] call ar_missions_builder_fnc_onUnload
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]],
	["_exitCode", 0, [0]]
];

TRACE_1("ar_missions_builder_fnc_onUnload",_this);

// Clean up the display variable
uiNamespace setVariable [QGVAR(RscMissionParameters), displayNull];

switch (_exitCode) do {
	case 1: {
		// Handle OK case
		private _missionName = _display displayCtrl 1001;
		private _missionDescription = _display displayCtrl 1002;
		private _missionPhase = _display displayCtrl 1003;
		private _underfireTime = _display displayCtrl 1004;
		private _respawnButtonTime = _display displayCtrl 1005;
		private _respawnDelay = _display displayCtrl 1006;

		private _nameText = ctrlText _missionName;
		private _descriptionText = ctrlText _missionDescription;
		private _phaseIndex = _missionPhase lbData (lbCurSel _missionPhase);
		private _underfireTimeValue = ctrlText _underfireTime;
		private _respawnButtonTimeValue = ctrlText _respawnButtonTime;
		private _respawnDelayValue = ctrlText _respawnDelay;

		[_nameText, _descriptionText, _phaseIndex, _underfireTimeValue, _respawnButtonTimeValue, _respawnDelayValue] call SUBFUNC(generateDescriptionEXT);
	};
	default {
		// Handle Cancel or other cases
		[LSUBLSTRING(cancelledGenerationDescriptionEXT), 1] call BIS_fnc_3DENNotification;
	};
};
