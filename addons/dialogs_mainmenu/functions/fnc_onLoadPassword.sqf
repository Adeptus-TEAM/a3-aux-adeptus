#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Fills the password dialog: server name, saved password, "remember" box and button hover effects.
 *
 * Arguments:
 * 0: _display <DISPLAY> - The password dialog
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [_display] call AR_Dialogs_MainMenu_fnc_onLoadPassword
 *
 * Public: No
 */

params [["_display", displayNull, [displayNull]]];

TRACE_1("fnc_onLoadPassword",_display);

(uiNamespace getVariable [QGVAR(server), ["", 0, ""]]) params ["", "", "_name"];
(_display displayCtrl IDC_PWD_TITLE) ctrlSetText toUpper _name;

private _remember = profileNamespace getVariable [PROFILE_REMEMBER, true];
(_display displayCtrl IDC_PWD_REMEMBER) cbSetChecked _remember;
if (_remember) then {
	(_display displayCtrl IDC_PWD_INPUT) ctrlSetText (profileNamespace getVariable [PROFILE_PASSWORD, ""]);
};
ctrlSetFocus (_display displayCtrl IDC_PWD_INPUT);

// Hover: recolor the skewed button shape under the transparent text button
{
	_x params ["_buttonIdc", "_imageIdc", "_normal", "_hover"];
	private _ctrl = _display displayCtrl _buttonIdc;
	_ctrl setVariable [QGVAR(hoverData), [_imageIdc, _normal, _hover]];
	_ctrl ctrlAddEventHandler ["MouseEnter", {
		params ["_ctrl"];
		(_ctrl getVariable QGVAR(hoverData)) params ["_imageIdc", "", "_hover"];
		((ctrlParent _ctrl) displayCtrl _imageIdc) ctrlSetTextColor _hover;
	}];
	_ctrl ctrlAddEventHandler ["MouseExit", {
		params ["_ctrl"];
		(_ctrl getVariable QGVAR(hoverData)) params ["_imageIdc", "_normal"];
		((ctrlParent _ctrl) displayCtrl _imageIdc) ctrlSetTextColor _normal;
	}];
} forEach [
	[IDC_PWD_CANCEL, IDC_PWD_CANCEL_IMG, ARR_BTN2, ARR_BTN2_HOVER],
	[IDC_PWD_CONFIRM, IDC_PWD_CONFIRM_IMG, ARR_BTN, ARR_BTN_HOVER]
];
