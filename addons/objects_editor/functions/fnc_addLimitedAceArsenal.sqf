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

_crate addAction ["ACE Arsenal",
{
	params ["_target", "_caller", "_actionId", "_arguments"];
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

// list of items to include in the arsenal
_availableWeapon = [
	"3AS_DC15A_F",
	"3AS_DC15A_GL",
	"3AS_DC15C_F",
	"3AS_DC15C_GL",
	"3AS_DC15L_F",
	"3AS_DC15S_F",
	"3AS_DC15S_GL",
	"3AS_DC17S_F",
	"3AS_DC17S_Dual_F",
	"3AS_DC15X_F",
	"3AS_DP23_F",
	"3AS_DP23_GL",
	"3AS_Flamer_Base",
	"3AS_Valken38X_F",
	"3AS_WestarM5_F",
	"3AS_WestarM5_GL",
	"AR_Weapons_Rifles_z6",
	"Police_Bat",
	"Shovel_Russian",
	"Shovel_Russian_Rotated",
	"UNSC_Knife",
	"WBK_survival_weapon_3",
	"WBK_survival_weapon_4",
	"WBK_survival_weapon_4_r",
	"Weap_melee_knife",
	"AR_Weapons_Launchers_RPS6_F",
	"3AS_PLX1_AA"
];

private _allVirtualItems = ((_crate call ace_arsenal_fnc_getVirtualItems) toArray true) select 0;
private _allWeapons = [];

{

    _itemInfo = [_x] call BIS_fnc_itemType;
    _itemCategory = _itemInfo select 0; // "Weapon"
    _itemType = _itemInfo select 1;      // "AssaultRifle", "Handgun", etc.

    // On vérifie si c'est une arme et on exclut les accessoires/objets
    if(_itemCategory == "Weapon" && !(_itemType in ["Magazine", "Throw"]))then{
		_allWeapons pushBack _x;
	};

}forEach _allVirtualItems;

_blacklistedWeapons = _allWeapons - _availableWeapon;

[_crate, _blacklistedWeapons] call ace_arsenal_fnc_removeVirtualItems;
