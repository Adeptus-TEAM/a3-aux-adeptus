#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Applies a delay for the respawn button during incapacitation.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to which the script will be applied.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_missions_fnc_initRespawnDelay
	 *
	 * Public: Yes
 */

params [
	["_unit", objNull, [objNull]]
];

TRACE_1("fnc_initRespawnDelay",_this);

GVAR(respawnButtonTimer) = getMissionConfigValue [QGVAR(respawnButtonTimer), 60]; // Default respawn button timer is 60 seconds if not set in the mission config
publicVariable QGVAR(respawnButtonTimer);

[
	{
		_this#0 params ["_unit"];
		private _respawnButton = (findDisplay 49) displayCtrl 1010; // get the respawn button control
		private _respawnButtonTimer = _unit getVariable [QGVAR(respawnButtonTimer), GVAR(respawnButtonTimer)]; // Get the current respawn timer for the unit
		if (!isNull _respawnButton) then { // Check if the respawn button exists
			TRACE_2("fnc_initRespawnDelay (PerFrameHandler)",_unit,_respawnButtonTimer);
			if (_respawnButtonTimer > 0) then {
				// if the respawn timer is greater than 0
				_respawnButton ctrlSetText FORMAT_1(LLSTRING(RespawnDelayCountdown),floor _respawnButtonTimer);
				_respawnButton ctrlEnable false; // Disable the respawn button
				SUB(_respawnButtonTimer,0.1); // Decrease the timer by 0.1 seconds
				_unit setVariable [QGVAR(respawnButtonTimer), _respawnButtonTimer]; // Update the unit's respawn timer
			} else {
				// if the timer has reached 0
				_respawnButton ctrlSetText LLSTRING(Respawn);
				_respawnButton ctrlEnable true; // Enable the respawn button
			};
		} else {
			_unit setVariable [QGVAR(respawnButtonTimer), GVAR(respawnButtonTimer)]; // Reset the respawn timer if the button is not found
		};
	},
	0.1, // every 0.1 seconds
	[_unit]
] call CBA_fnc_addPerFrameHandler;
