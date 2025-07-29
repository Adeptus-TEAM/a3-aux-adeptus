#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Initializes the medical task system.
	 *
	 * Arguments:
	 * <NONE>
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [] call ar_missions_fnc_initMedicalTask
	 *
	 * Public: No
 */

TRACE_1("fnc_initMedicalTask",_this);

["ace_unconscious", {
	params [ "_unit", "_state" ];

	if (_state && !(_unit in GVAR(unconsciousPlayers)) && (isPlayer _unit)) then {
	TRACE_2("fnc_initMedicalTask",_unit,"is unconscious, creating task and playing sound.");

		// Play a random death sound for the unconscious player
		playSound3D [ (FORMAT_1(QPATHTOF(data\sounds\cloneDeathSound_%1.ogg),(selectRandom[ARR_5(1,2,3,4,5)]))), _unit, false, getPosASL _unit, 1, 1, 60];

		// Add the unit to the unconscious players list
		[_unit] call FUNC(unconsciousPlayerTasks);
	};
}] call CBA_fnc_addEventHandler;

// init variable
GVAR(unconsciousPlayers) = [];
publicVariable QGVAR(unconsciousPlayers);
