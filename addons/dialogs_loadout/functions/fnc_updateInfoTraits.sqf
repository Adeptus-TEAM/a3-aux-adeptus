#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to update the loadout information traits.
	 *
	 * Arguments:
	 * 0: _classSel (default: "") <STRING> - The selected class for the loadout.
	 * 1: _infoIsEngineer (default: controlNull) <CONTROL> - The control for the engineer info.
	 * 2: _infoIsEOD (default: controlNull) <CONTROL> - The control for the EOD info.
	 * 3: _infoIsMedic (default: controlNull) <CONTROL> - The control for the medic info.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [_classSel, _infoIsEngineer, _infoIsEOD, _infoIsMedic] call ar_dialogs_loadout_fnc_updateInfoTraits
	 *
	 * Public: No
 */

params [
	["_classSel", "", [""]],
	["_infoIsEngineer", controlNull, [controlNull]],
	["_infoIsEOD", controlNull, [controlNull]],
	["_infoIsMedic", controlNull, [controlNull]]
];

TRACE_1("ar_dialogs_loadout_fnc_updateInfoTraits",_this);

private _loadoutIsMedic = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "isMedic"));
private _loadoutIsEngineer = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "isEngineer"));
private _loadoutIsEOD = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "isEOD"));

private _colorGreen = [0.137, 0.608, 0.337, 1];
private _colorRed = [0.796, 0.263, 0.208, 1];

if (_loadoutIsMedic) then {
	_infoIsMedic ctrlSetBackgroundColor _colorGreen;
	_infoIsMedic ctrlSetText FORMAT_2("%1 %2",LSUBLSTRING(infoIsMedic),"[ON]");
} else {
	_infoIsMedic ctrlSetBackgroundColor _colorRed;
	_infoIsMedic ctrlSetText FORMAT_2("%1 %2",LSUBLSTRING(infoIsMedic),"[OFF]");
};

if (_loadoutIsEngineer) then {
	_infoIsEngineer ctrlSetBackgroundColor _colorGreen;
	_infoIsEngineer ctrlSetText FORMAT_2("%1 %2",LSUBLSTRING(infoIsEngineer),"[ON]");
} else {
	_infoIsEngineer ctrlSetBackgroundColor _colorRed;
	_infoIsEngineer ctrlSetText FORMAT_2("%1 %2",LSUBLSTRING(infoIsEngineer),"[OFF]");
};

if (_loadoutIsEOD) then {
	_infoIsEOD ctrlSetBackgroundColor _colorGreen;
	_infoIsEOD ctrlSetText FORMAT_2("%1 %2",LSUBLSTRING(infoIsEOD),"[ON]");
} else {
	_infoIsEOD ctrlSetBackgroundColor _colorRed;
	_infoIsEOD ctrlSetText FORMAT_2("%1 %2",LSUBLSTRING(infoIsEOD),"[OFF]");
};
