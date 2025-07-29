#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Initializes NVGs for a player.
	 *
	 * Arguments:
	 * 0: _player (default: objNull) <OBJECT> - The player object to initialize NVGs for.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_characters_nvgs_fnc_init
	 *
	 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

if (is3DEN) exitWith {};

TRACE_1("ar_characters_nvgs_fnc_init",_this);

[
	_player,
	"VisionModeChanged",
	{
		_this remoteExec [QSUBFUNC(setColor), _this#0, false];
	},
	nil
] call CBA_fnc_addBISEventHandler;
