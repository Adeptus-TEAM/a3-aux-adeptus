#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to update the subclass loadout.
	 *
	 * Arguments:
	 * 0: _listSubClass (default: controlNull) <CONTROL> - The control for the subclass list.
	 * 1: _classSel (default: "") <STRING> - The selected class for the loadout.
	 *
	 * Return Value:
	 * Return description <NONE>
	 *
	 * Example:
	 * [_listSubClass, "className"] call ar_dialogs_loadout_fnc_updateSubClass
	 *
	 * Public: No
 */

params [
	["_listSubClass", controlNull, [controlNull]],
	["_classSel", "", [""]]
];

TRACE_1("ar_dialogs_loadout_fnc_updateSubClass",_this);

private _phase = getMissionConfigValue [QEGVAR(missions,clonePhase), 0];

private _subClassList = "true" configClasses (configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo");

{
	private _subClassName = configName _x;
	private _subClassPhase = getNumber (configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName >> "phase");

	switch (_phase) do {
		case 1: {
			// INCLUDES ONLY PHASE 1
			if ((_subClassPhase == 1) || (_subClassPhase == 0)) then {
				private _index = _listSubClass lbAdd ([configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName] call BIS_fnc_displayName);
				_listSubClass lbSetPicture [_index, getText (configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName >> "icon")];
				_listSubClass lbSetData [_index, _subClassName];
			};
		};
		case 2: {
			// INCLUDES ONLY PHASE 2
			if ((_subClassPhase == 2) || (_subClassPhase == 0)) then {
				private _index = _listSubClass lbAdd ([configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName] call BIS_fnc_displayName);
				_listSubClass lbSetPicture [_index, getText (configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName >> "icon")];
				_listSubClass lbSetData [_index, _subClassName];
			};
		};
		default {
			// INCLUDES ALL PHASES
			switch (_subClassPhase) do {
				case 0: {
					_listSubClass lbAdd ([configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName] call BIS_fnc_displayName);
				};
				case 1: {
					_listSubClass lbAdd (FORMAT_2("%1 %2",[configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName] call BIS_fnc_displayName,"(P1)"));
				};
				case 2: {
					_listSubClass lbAdd (FORMAT_2("%1 %2",[configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName] call BIS_fnc_displayName,"(P2)"));
				};
			};
			_listSubClass lbSetPicture [_forEachIndex, getText (configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassName >> "icon")];
			_listSubClass lbSetData [_forEachIndex, _subClassName];
		};
	};
} forEach _subClassList;
