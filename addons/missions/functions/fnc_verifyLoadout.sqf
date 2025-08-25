#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Empêche les joueurs de dépasser la limite d'objets autorisée.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - Le joueur à vérifier
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [player] call AR_missions_fnc_verifyLoadout
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

TRACE_1("fnc_verifyLoadout",_this);

private _playerLoadoutItemWithMagazines = itemsWithMagazines _player;

private _blackList = [
	["SquadShieldMagazine", 2],
	["ShieldGrenade_Mag", 4],
	["ShieldGrenadePersonal_Mag", 0]
];

{
	_x params ["_BL_itemClassname","_BL_itemLimit"];

	private _itemQuantity = {_BL_itemClassname == _x} count _playerLoadoutItemWithMagazines;
	if (_itemQuantity > _BL_itemLimit) then {
		for [ {private _i = 0}, {_i < (_itemQuantity - _BL_itemLimit)}, {_i = _i + 1} ] do {
			_player removeItem _BL_itemClassname;
			INFO_2("Removed item:%1 from %2 due to exceeding limit",_BL_itemClassname,_player);
		};
		private _BL_itemClassnameDisplayName = [configFile >> "CfgMagazines" >> _BL_itemClassname] call BIS_fnc_displayName;
		cutText [FORMAT_2(LLSTRING(verifyLoadout),_BL_itemClassnameDisplayName,_BL_itemLimit), "PLAIN DOWN", 0, false, true];
		playSound "Alarm";
	};
} forEach _blackList;
