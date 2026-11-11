#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Hover effect of a server row: lighter background and brighter "join" button.
 *
 * Arguments:
 * 0: _ctrl <CONTROL> - The row button (idc 6101 to 6103)
 * 1: _hover <BOOL> - true when the mouse enters, false when it leaves
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [_ctrl, true] call AR_Dialogs_MainMenu_fnc_setHover
 *
 * Public: No
 */

params [["_ctrl", controlNull, [controlNull]], ["_hover", false, [false]]];

private _display = ctrlParent _ctrl;
private _index = ctrlIDC _ctrl - 6100;

(_display displayCtrl IDC_ROW_BG(_index)) ctrlSetBackgroundColor ([ARR_ROW, ARR_ROW_HOVER] select _hover);

(_display displayCtrl IDC_ROW_JOIN(_index)) ctrlSetTextColor ([ARR_BTN, ARR_BTN_HOVER] select _hover);
