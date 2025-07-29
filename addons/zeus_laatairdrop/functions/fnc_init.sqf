#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to initialize the Laat Air drop module and save position.
	 *
	 * Arguments:
	 * 0: _curator (default: objNull) <OBJECT> - The curator to initialize the Laat Air drop module for.
	 * 1: _entity (default: objNull) <OBJECT> - The entity that was placed by the curator.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myModule] call ar_zeus_laatAirDrop_fnc_init
	 *
	 * Public: No
 */

params [
	["_curator", objNull, [objNull]],
	["_entity", objNull, [objNull]]
];

if ((getAssignedCuratorUnit _curator) != player) exitWith {};

TRACE_1("ar_zeus_laatAirDrop_fnc_init",_this);

uiNamespace setVariable [QGVAR(laatAirDropModule), _entity];

createDialog "RscLaatAirDrop";
