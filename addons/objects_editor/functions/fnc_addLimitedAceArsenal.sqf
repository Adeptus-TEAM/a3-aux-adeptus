#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Adds a limited ACE arsenal to a crate.
	 *              Runs locally on every machine (config init event handler, JIP included),
	 *              so nothing is broadcast: each client builds and filters its own arsenal.
	 *
	 * Arguments:
	 * 0: _crate (default: objNull) <OBJECT> - The object to which the arsenal will be added.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_objects_editor_fnc_addLimitedAceArsenal
	 *
	 * Public: No
 */

params [
	["_crate", objNull, [objNull]]
];

if (is3DEN || {!hasInterface} || {isNull _crate}) exitWith {};

TRACE_1("ar_objects_editor_fnc_addLimitedAceArsenal",_this);

// Initialize the arsenal locally (global = false). A global init would re-broadcast the full
// item list through a JIP event and overwrite the filtered list on other / joining clients.
[_crate, true, false] call ace_arsenal_fnc_initBox;

private _allowedWeapons = getMissionConfigValue [QEGVAR(missions,allowedWeapons), []];

if (_allowedWeapons isNotEqualTo []) then {
	private _allowedLower = _allowedWeapons apply {toLower _x};
	private _allVirtualItems = ((_crate call ace_arsenal_fnc_getVirtualItems) toArray true) select 0; // Item classnames, without quantities

	// Keep only primary weapons (1), handguns (2) and launchers (4) that are not whitelisted
	private _blacklistedWeapons = _allVirtualItems select {
		private _cfg = configFile >> "CfgWeapons" >> _x;
		isClass _cfg
		&& {getNumber (_cfg >> "type") in [1, 2, 4]}
		&& {!((toLower _x) in _allowedLower)}
	};

	[_crate, _blacklistedWeapons, false] call ace_arsenal_fnc_removeVirtualItems;
	TRACE_1("Blacklisted weapons removed",count _blacklistedWeapons);
};

// Scroll-wheel action to open the ACE arsenal (addAction is local, which is what we want here)
_crate addAction ["ACE Arsenal",
	{
		params ["_target", "_caller"];
		[_target, _caller] call ace_arsenal_fnc_openBox;
	},
	nil,
	1,
	true,
	true,
	"",
	"true",
	5,
	false
];
