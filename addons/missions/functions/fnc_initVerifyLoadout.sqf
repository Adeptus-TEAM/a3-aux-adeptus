#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Initialise le système de vérification de la charge utile des joueurs.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT> - Le joueur à vérifier
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [player] call AR_missions_fnc_initVerifyLoadout
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];
TRACE_1("fnc_initVerifyLoadout",_this);

[
	"loadout",
	{_this call FUNC(verifyLoadout)},
	true
] call CBA_fnc_addPlayerEventHandler;
