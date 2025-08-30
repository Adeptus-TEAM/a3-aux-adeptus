#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Adds a limited arsenal to a crate.
	 *
	 * Arguments:
	 * 0: _crate (default: objNull) <OBJECT> - The object to which the arsenal will be added.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_objects_editor_fnc_addLimitedArsenal
	 *
	 * Public: No
 */

params [
	["_crate", objNull, [objNull]]
];

if (is3DEN) exitWith {};

TRACE_1("ar_objects_editor_fnc_addLimitedArsenal",_this);

// Initialize the arsenal on the crate
["AmmoboxInit", [_crate, false, {
	_this distance _target < 5 // Check if the player is close enough
}]] call BIS_fnc_arsenal;

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

// Populate with predefined items and whatever is already in the crate
[_crate, ["%ALL"]] call BIS_fnc_addVirtualBackpackCargo;

[_crate, ["%ALL"]] call BIS_fnc_addVirtualItemCargo;

[_crate, ["%ALL"]] call BIS_fnc_addVirtualMagazineCargo;

[_crate, ((weaponCargo _crate) + _availableWeapon)] call BIS_fnc_addVirtualWeaponCargo;
