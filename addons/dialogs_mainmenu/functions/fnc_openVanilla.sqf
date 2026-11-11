#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Opens a vanilla main menu entry (editor, options, profile...) by activating its hidden button.
 *              The engine handles these buttons by idc, so we reuse them instead of rebuilding their actions.
 *
 * Arguments:
 * 0: _display <DISPLAY> - The main menu display
 * 1: _idc <NUMBER> - Idc of the vanilla button (142 editor, 140 mods, 301-307 options, 109 profile, 106 quit)
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [findDisplay 0, 142] call AR_Dialogs_MainMenu_fnc_openVanilla
 *
 * Public: No
 */

params [["_display", displayNull, [displayNull]], ["_idc", -1, [0]]];

TRACE_1("fnc_openVanilla",_idc);

private _ctrl = _display displayCtrl _idc;
if (isNull _ctrl) exitWith {
	WARNING_1("Vanilla main menu control %1 not found",_idc);
};

// A hidden control may ignore activation: show it (and its group) for the click, then hide everything again
private _group = ctrlParentControlsGroup _ctrl;
_group ctrlShow true;
_ctrl ctrlShow true;
ctrlActivate _ctrl;
[_display] call (_display getVariable [QGVAR(hideVanilla), {}]);
