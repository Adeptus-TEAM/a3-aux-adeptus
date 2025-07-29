#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Initialize welcome message for the mission
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The player object to which the welcome message will be applied.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_missions_fnc_initWelcome
	 *
	 * Public: No
 */

params [
	["_player", objNull, [objNull]]
];

TRACE_1("fnc_initWelcome",_this);

_player switchMove "amovpercmstpsraswrfldnon";

if (!isMultiplayer) exitWith {
	// In singleplayer, don't show the welcome message
	INFO("Singleplayer detected, skipping welcome message.");
};

[
	{
		params ["_player"];
		!isNull _player // Wait until the player is not null
	},
	{
		params ["_player"];
		private _playerName = name _player;
		private _serverName = GVAR(serverName);
		private _missionName = getMissionConfigValue ["onLoadName", "N/A"];
		[
			[
				// Line1
				[LLSTRING(welcomeMSG_Line1), "<t align = 'left' shadow = '1' size = '0.7'>%1</t>"],
				[FORMAT_1(" %1.",_serverName), "<t align = 'left' shadow = '1' size = '0.7' color='#4649FF'>%1</t><br/>"],
				// Line2
				[LLSTRING(welcomeMSG_Line2), "<t align = 'left' shadow = '1' size = '0.7'>%1</t>"],
				[FORMAT_1(" %1.",_missionName), "<t align = 'left' shadow = '1' size = '0.7' color='#00ffff'>%1</t><br/>"],
				// Line3
				[LLSTRING(welcomeMSG_Line3), "<t align = 'left' shadow = '1' size = '0.7'>%1</t>"],
				[FORMAT_1(" %1!",_playerName), "<t align = 'left' shadow = '1' size = '0.7' color='#ffd200'>%1</t><br/>", 15]
			],
			safeZoneX + safeZoneW * 0.025, safeZoneY + safeZoneH * 0.05
		] remoteExec ["BIS_fnc_typeText", _player, false];
	},
	[_player]
] call CBA_fnc_waitUntilAndExecute;
