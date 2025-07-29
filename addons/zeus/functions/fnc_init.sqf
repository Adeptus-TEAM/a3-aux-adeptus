#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to initialize the Zeus module.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit to initialize
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [this] call ar_zeus_fnc_init
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

TRACE_1("ar_zeus_fnc_init",_this);

[{
	params ["_unit"];
	// Wait until the unit is not null
	!isNull _unit
}, {
	params ["_unit"];
	[{
		params ["_unit"];
		[_unit] remoteExecCall ["zen_common_fnc_createZeus", 2];
		INFO_1("Zeus module initialized for unit: %1",_unit);
		[{
			params ["_unit"];
			private _curator = getAssignedCuratorLogic _unit;
			[_curator] call FUNC(initEH);
			_curator addCuratorEditableObjects [allUnits, true];
		}, [_unit], 5] call CBA_fnc_waitAndExecute;
	}, [_unit], 5] call CBA_fnc_waitAndExecute;
}, [_unit]] call CBA_fnc_waitUntilAndExecute;
