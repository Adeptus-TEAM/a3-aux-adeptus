#include "..\script_component.hpp"
/*
 * Authors: You
 * Initialise le système de vérification de la charge utile des joueurs.
 *
 * Arguments:
 * 0: _player (default: objNull) <OBJECT>
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [_unit] call AR_missions_fnc_initVerifyLoadout
 *
 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];
TRACE_1("fnc_initVerifyLoadout",_this);

[
	"loadout",
	FUNC(verifyLoadout),
	true
] call CBA_fnc_addPlayerEventHandler;
