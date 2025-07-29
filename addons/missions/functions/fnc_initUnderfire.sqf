#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Initialize under fire behavior for a unit
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to which the under fire behavior will be applied.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [player] call ar_missions_fnc_initUnderfire
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

TRACE_1("fnc_initUnderfire",_this);

[
	_unit,
	"FiredNear",
	{
		params ["_unit"];

		private _combatTime = getMissionConfigValue [QGVAR(combatTime), 60]; // Default combat time is 60 seconds if not set in the mission config

		TRACE_2("fnc_initUnderfire (EventHandler)",_unit,_combatTime);

		// Check if the unit is remote controlling, in a vehicle, not alive, or not a player
		if ((isRemoteControlling _unit) || !(isNull objectParent _unit) || !(alive _unit) || !(isPlayer _unit)) exitWith {};

		// Check if the unit is already under fire
		if (_unit getVariable [QGVAR(combatTimeUnit), 0] == 0) then {
			// Set the combat time to default value
			_unit setVariable [QGVAR(combatTimeUnit), _combatTime, true];

			private _bar = findDisplay 46 ctrlCreate ["RscProgress", -1];
			_bar ctrlSetPosition [safeZoneX + safeZoneW * 0, safeZoneY + safeZoneH * 0, safeZoneW, safeZoneH * .002];
			_bar ctrlCommit 0;
			_bar progressSetPosition 1;

			private _handler = [
				{
					_this#0 params ["_unit", "_combatTime", "_bar"];

					private _combatTimeUnit = _unit getVariable [QGVAR(combatTimeUnit), 0];

					// Subtract .5 seconds from the combat time
					SUB(_combatTimeUnit,.5);
					_unit setVariable [QGVAR(combatTimeUnit), _combatTimeUnit, true];

					// If the unit is remote controlling, in a vehicle, not alive, not a player, or combat time is greater than 0, reset the combat time
					if ((isRemoteControlling _unit) || !(isNull objectParent _unit) || !(alive _unit) || !(isPlayer _unit) || (_combatTimeUnit < 0)) exitWith {
						_unit setVariable [QGVAR(combatTimeUnit), 0, true];
					};

					// If the camera view is external and the unit is not parented to an object, is a player, and is alive, switch the camera to internal view
					if ((cameraView == "External") && (isNull objectParent _unit) && (isPlayer _unit) && (alive _unit)) then {
						_unit switchCamera "Internal";

						TRACE_1("fnc_initUnderfire (Switch Camera to Internal)",_unit);
					};

					// Update the progress bar
					_bar progressSetPosition (_combatTimeUnit / _combatTime);
					
					TRACE_1("fnc_initUnderfire (PerFrameHandler)",_combatTimeUnit);
				},
				.5, // every .5 seconds
				[_unit, _combatTime, _bar]
			] call CBA_fnc_addPerFrameHandler;
	
			// Wait until the unit is no longer under fire
			[
				{
					params ["_unit"];
					_unit getVariable [QGVAR(combatTimeUnit), 0] == 0 // Check if the combat time is reset to 0
				},
				{
					params ["_unit", "_handler", "_bar"];
					TRACE_1("fnc_initUnderfire (Combat Time Ended)",_unit);

					[_handler] call CBA_fnc_removePerFrameHandler;
					
					// Remove the progress bar
					ctrlDelete _bar;
				},
				[_unit, _handler, _bar]
			] call CBA_fnc_waitUntilAndExecute;

		} else {
			// If the unit is already under fire, reset the combat time to the specified value
			_unit setVariable [QGVAR(combatTimeUnit), _combatTime, true];
		};
	}
] call CBA_fnc_addBISEventHandler;
