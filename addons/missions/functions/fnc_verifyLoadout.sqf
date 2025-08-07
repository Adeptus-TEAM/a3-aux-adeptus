#include "..\script_component.hpp"
/*
 * Authors: You
 * Empêche les joueurs de dépasser la limite d'objets autorisée.
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [] call AR_missions_fnc_verifyLoadout
 *
 * Public: No
 */

params [];
TRACE_1("fnc_verifyLoadout",_this);

private _playerLoadoutItemWithMagazines = itemsWithMagazines player;

private _blackList = [
	["SquadShieldMagazine", 2],
	["ShieldGrenade_Mag",2],
	["ShieldGrenadePersonal_Mag",0]
];

{
	private _BL_itemClassname = _x select 0;
	private _BL_itemLimit = _x select 1;

	private _itemQuantity = {_BL_itemClassname == _x} count _playerLoadoutItemWithMagazines;
	if(_itemQuantity > _BL_itemLimit)then{
		for[{private _i = 0},{_i < (_itemQuantity - _BL_itemLimit)},{_i = _i + 1}]do{
			player removeItem _BL_itemClassname;
			INFO_2("Removed item:%1 from %2 due to exceeding limit",_BL_itemClassname,player);
		};
		private _BL_itemClassnameDisplayName = getText (configFile >> "CfgMagazines" >> _BL_itemClassname >> "displayName");
		[[format[LLSTRING(verifyLoadout),_BL_itemClassnameDisplayName,_BL_itemLimit], "PLAIN DOWN", -1,false, true]] remoteExec ["cutText",player,false];
		["Alarm"] remoteExec ["playSound", player, false];
	};
}forEach _blackList;
