#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Development tool. Lists the maps that define their own intro (other than the menu scene),
 *              grouped by mod, with their real parent class and the addons that define them, and copies
 *              the result to the clipboard. Run it from the debug console with the unit's preset loaded,
 *              after adding or removing map mods.
 *
 *              Only maps that define "cutscenes" themselves are listed: a map that inherits its intro from its
 *              parent follows the parent once the parent is patched. DefaultWorld (base of all maps) is skipped.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <STRING> - The text copied to the clipboard ("" if every map already uses the menu scene)
 *
 * Example:
 * [] call (uiNamespace getVariable "AR_Dialogs_MainMenu_fnc_exportWorlds")
 *
 * Public: No
 */

private _scene = QCVAR(intro1_P2_VR);
private _byMod = createHashMap; // mod -> [lines, addons]
private _count = 0;

{
	private _parent = inheritsFrom _x;
	if (
		!isNull _parent
		&& {(configProperties [_x, "configName _x == 'cutscenes'", false]) isNotEqualTo []}
		&& {!(_scene in getArray (_x >> "cutscenes"))}
	) then {
		private _mod = configSourceMod _x;
		if (_mod isEqualTo "") then {_mod = "Arma 3"};
		private _entry = _byMod getOrDefault [_mod, [[], []], true];
		(_entry select 0) pushBack format ["    WORLD_CUTSCENE(%1,%2);", configName _x, configName _parent];
		private _source = configSourceAddonList _x;
		if (_source isNotEqualTo []) then {
			(_entry select 1) pushBackUnique (_source select 0);
		};
		_count = _count + 1;
	};
} forEach ("true" configClasses (configFile >> "CfgWorlds"));

if (_count == 0) exitWith {
	systemChat "Every map already uses the main menu scene.";
	""
};

private _nl = toString [13, 10];
private _blocks = [];
{
	_y params ["_lines", "_addons"];
	_blocks pushBack format [
		"// Mod: %1%2// requiredAddons: %3%2%4",
		_x, _nl, (_addons apply {str _x}) joinString ", ", _lines joinString _nl
	];
} forEach _byMod;

private _text = _blocks joinString (_nl + _nl);
copyToClipboard _text;
systemChat format ["%1 map(s) in %2 mod(s): copied to the clipboard.", _count, count _byMod];
_text
