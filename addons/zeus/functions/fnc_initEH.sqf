#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to initialize event handlers.
	 *
	 * Arguments:
	 * 0: _curator (default: objNull) <OBJECT> - The curator to initialize event handlers for.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myCuratorModule] call ar_zeus_fnc_initEH
	 *
	 * Public: No
 */

params [
	["_curator", objNull, [objNull]]
];

TRACE_1("ar_zeus_fnc_initEH",_this);

_curator addEventHandler ["CuratorObjectPlaced", {
	params ["_curator", "_entity"];

	switch (typeOf _entity) do {
		case QCVAR(ModuleLaatAirDrop): {
			_this call EFUNC(zeus_laatairdrop,init);
		};
		default {};
	};
}];
