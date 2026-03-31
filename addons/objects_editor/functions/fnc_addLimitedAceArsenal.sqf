#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Adds a limited ACE arsenal to a crate.
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

if (is3DEN) exitWith {};

TRACE_1("ar_objects_editor_fnc_addLimitedAceArsenal",_this);


// Initialize the arsenal on the crate
[_crate, true] call ace_arsenal_fnc_initBox;

// Create an Arma Interaction System action on the crate
_crate addAction ["ACE Arsenal",
{
	
	params ["_target", "_caller", "_actionId", "_arguments"];
	INFO("ar_objects_editor_fnc_addLimitedAceArsenal : ACE Arsenal box opened by " + name _caller);
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


private _allVirtualItems = ((_crate call ace_arsenal_fnc_getVirtualItems) toArray true) select 0; // Get all virtual items currently in the crate and convert to array to get rid of quantity.
private _allWeapons = [];
INFO("ar_objects_editor_fnc_addLimitedAceArsenal : Total virtual items in crate before filtering: " + str (count _allVirtualItems));

{

    private _itemInfo = [_x] call BIS_fnc_itemType;
    private _itemCategory = _itemInfo select 0; // "Weapon"
    private _itemType = _itemInfo select 1; // "AssaultRifle", "Handgun", etc.

    // On vérifie si c'est une arme et on exclut les accessoires/objets
    if(_itemCategory == "Weapon" && !(_itemType in ["Magazine", "Throw"]))then{
		_allWeapons pushBack _x;
	};
}forEach _allVirtualItems;
INFO("ar_objects_editor_fnc_addLimitedAceArsenal : Total virtual items in crate: " + str (count _allWeapons));

private _allowedWeapons = getMissionConfigValue QEGVAR(missions,allowedWeapons);

if (_allowedWeapons isNotEqualTo []) then {
	private _blacklistedWeapons = _allWeapons - _allowedWeapons; // Substract are whitelist with all of the weapons to have the blacklisted ones
	[_crate, _blacklistedWeapons, true] call ace_arsenal_fnc_removeVirtualItems; // Remove blacklisted weapons from the crate, keeping magazines and other items intact.
	INFO("ar_objects_editor_fnc_addLimitedAceArsenal : Arsenal ACE limited to " + str _allowedWeapons);
};
