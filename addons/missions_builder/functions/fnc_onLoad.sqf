#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Initializes mission parameters.
	 *
	 * Arguments:
	 * 0: _display (default: displayNull) <DISPLAY> - The display on which the mission parameters will be initialized.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myDisplay] call ar_missions_builder_fnc_onLoad
	 *
	 * Public: No
 */

params [
	["_display", displayNull, [displayNull]]
];

TRACE_1("ar_missions_builder_fnc_onLoad",_this);

// Set the display in the uiNamespace for later access
uiNamespace setVariable [QGVAR(RscMissionParameters), _display];

// Initialize the mission parameters display controls
private _selectMissionPhase = _display displayCtrl 1003;
private _underfireTime = _display displayCtrl 1004;
private _respawnButtonTime = _display displayCtrl 1005;
private _respawnDelay = _display displayCtrl 1006;

// set up the mission phase selection
private _missionPhases = [["Phase 1", 1], ["Phase 2", 2]];
{
	_x params ["_name", "_value"];
	private _index = _selectMissionPhase lbAdd _name;
	_selectMissionPhase lbSetData [_index,str _value];
} forEach _missionPhases;

_selectMissionPhase lbSetCurSel 2; // Default to Phase 2

// Set default values for the other controls
_underfireTime ctrlSetText "60"; // Default underfire time
_underfireTime ctrlSetTooltip LSUBLSTRING(underfireTimeTooltip);

_respawnButtonTime ctrlSetText "60"; // Default respawn button time
_respawnButtonTime ctrlSetTooltip LSUBLSTRING(respawnButtonTimeTooltip);

_respawnDelay ctrlSetText "5"; // Default respawn time
_respawnDelay ctrlSetTooltip LSUBLSTRING(respawnDelayTooltip);
