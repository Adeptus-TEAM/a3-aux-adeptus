#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Play respawn animation for the player
	 *
	 * Arguments:
	 * 0: _player (default: objNull) <OBJECT> - The player object for whom the respawn animation will be played.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_missions_fnc_playRespawnAnimation
	 *
	 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

TRACE_1("fnc_playRespawnAnimation",_this);

private _handle = ppEffectCreate ["ChromAberration", 200];
_handle ppEffectEnable true;
_handle ppEffectAdjust [0.05, 0.05, true];
_handle ppEffectCommit 1;
[
	{
		params ["_handle"];
		_handle ppEffectEnable false;
		ppEffectDestroy _handle;
	},
	[_handle],
	5
] call CBA_fnc_waitAndExecute;

private _playerName = name _player;

[
	[
		[FORMAT_1(" %1.",_playerName), "<t align = 'left' shadow = '1' size = '0.7' color='#00ffff'>%1</t>"],
		[LLSTRING(respawnMSG), "<t align = 'left' shadow = '1' size = '0.7'>%1</t>"]
	],
	safeZoneX + safeZoneW * 0.025, safeZoneY + safeZoneH * 0.05
] remoteExec ["BIS_fnc_typeText", _player, false];
