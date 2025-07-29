#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Generates a description.ext for the mission.
	 *
	 * Arguments:
	 * 0: _nameText (default: "Mission Adeptus") <STRING> - The name of the mission.
	 * 1: _descriptionText (default: "Vous êtes un Clone Trooper à la solde de la Grande Armée de la République.") <STRING> - The description of the mission.
	 * 2: _phaseIndex (default: "2") <STRING> - The phase index of the mission.
	 * 3: _underfireTimeValue (default: "60") <STRING> - The underfire time value.
	 * 4: _respawnButtonTimeValue (default: "60") <STRING> - The respawn button time value.
	 * 5: _respawnDelayValue (default: "5") <STRING> - The respawn time value.
	 *
	 * Return Value:
	 * Return description <NONE>
	 *
	 * Example:
	 * [
	 * 	"Mission Adeptus",
	 * 	"Vous êtes un Clone Trooper à la solde de la Grande Armée de la République.",
	 * 	"2",
	 * 	"60",
	 * 	"60",
	 * 	"5"
	 * ] call ar_missions_builder_fnc_generateDescriptionEXT
	 *
	 * Public: No
 */

params [
	["_nameText", "", [""]],
	["_descriptionText", "", [""]],
	["_phaseIndex", "2", ["2"]],
	["_underfireTimeValue", "60", ["60"]],
	["_respawnButtonTimeValue", "60", ["60"]],
	["_respawnDelayValue", "5", ["5"]]
];

TRACE_1("ar_missions_builder_fnc_generateDescriptionEXT",_this);

// Make sure the name and description are not empty
if (_nameText == "") then {
	_nameText = "Mission Adeptus";
};
if (_descriptionText == "") then {
	_descriptionText = "Vous êtes un Clone Trooper à la solde de la Grande Armée de la République.";
};

// check types of the values
private _phase = call compile _phaseIndex;
private _underfireTime = call compile _underfireTimeValue;
private _respawnButtonTime = call compile _respawnButtonTimeValue;
private _respawnDelay = call compile _respawnDelayValue;

{
	if (!IS_SCALAR(_x)) exitWith {
		[LSUBLSTRING(errorGenerationDescriptionEXT), 1] call BIS_fnc_3DENNotification;
	};
} forEach [	_phase, _underfireTime, _respawnButtonTime, _respawnDelay];

// Get the template data for description.ext
private _preparedData = [_nameText, _descriptionText, _phase, _underfireTime, _respawnButtonTime, _respawnDelay] call SUBFUNC(getDescriptionTemplate);

// write the data to the description.ext file
private _handler = ["description.ext", _preparedData] call SUBFUNC(addFile);

if !(_handler) exitWith {
	[LSUBLSTRING(errorGenerationDescriptionEXT), 1] call BIS_fnc_3DENNotification;
};
[LSUBLSTRING(successGenerationDescriptionEXT)] call BIS_fnc_3DENNotification;
