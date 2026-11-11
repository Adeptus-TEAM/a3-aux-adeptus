#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Initializes the garage module. Links every synchronized terminal to the module,
 *              which is used as the spawn point. A terminal can only be linked to one module.
 *
 * Arguments:
 * 0: Module <OBJECT>
 * 1: Synchronized objects (terminals) <ARRAY>
 * 2: Activated <BOOL>
 *
 * Return Value:
 * <BOOL>
 *
 * Example:
 * Called automatically by the engine at mission start.
 *
 * Public: No
 */

params [
	["_module", objNull, [objNull]],
	["_terminals", [], [[]]],
	["_activated", true, [true]]
];
TRACE_1("fnc_moduleGarageSpawn",_this);

// Safety check: server only, and only if the module is activated.
if (!isServer || {!_activated}) exitWith {true};

if (isNull _module) exitWith {
	WARNING("Invalid garage module");
	true
};

if (_terminals isEqualTo []) exitWith {
	WARNING_1("Garage module %1 is not synchronized to any terminal",_module);
	true
};

{
	// Is this terminal already linked to another garage module?
	private _existingModule = _x getVariable [QGVAR(garageModule), objNull];

	if (!isNull _existingModule && {_existingModule != _module}) then {
		WARNING_2("Terminal %1 is already linked to garage module %2, ignored",_x,_existingModule);
	} else {
		// Link the terminal to this module, broadcast to all clients (JIP included).
		_x setVariable [QGVAR(garageModule), _module, true];
		INFO_2("Terminal %1 linked to garage module %2",_x,_module);
	};
} forEach _terminals;

true
