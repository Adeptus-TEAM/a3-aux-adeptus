#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Returns the template for description.ext file.
	 *
	 * Arguments:
	 * 0: _nameText (default: "Mission Adeptus") <STRING> - The name of the mission.
	 * 1: _descriptionText (default: "Vous êtes un Clone Trooper à la solde de la Grande Armée de la République.") <STRING> - The description of the mission.
	 * 2: _phaseIndex (default: 2) <NUMBER> - The phase index of the mission.
	 * 3: _underfireTime (default: 60) <NUMBER> - The underfire time value.
	 * 4: _respawnButtonTime (default: 60) <NUMBER> - The respawn button time value.
	 * 5: _respawnDelay (default: 5) <NUMBER> - The respawn time value.
	 *
	 * Return Value:
	 * _formattedData <STRING> - A string containing the processed description template, typically formatted for 'Arma3FileWriter'.
	 *
	 * Example:
	 * ["Mission Adeptus", "Description...", 2, 60, 60, 60] call ar_missions_builder_fnc_getDescriptionTemplate
	 *
	 * Public: No
 */

params [
	["_nameText", "Mission Adeptus", [""]],
	["_descriptionText", "Vous êtes un Clone Trooper à la solde de la Grande Armée de la République.", [""]],
	["_phase", 2, [0]],
	["_underfireTime", 60, [0]],
	["_respawnButtonTime", 60, [0]],
	["_respawnDelay", 5, [0]]
];

TRACE_1("ar_missions_builder_fnc_getDescriptionTemplate",_this);

// Prepare replacement values
private _replacements = createHashMap;
_replacements set ["%MINIMAL_VERSION%", QUOTE(GVAR(minimalVersion))];
_replacements set ["%MINIMAL_VERSION_VALUE%", QUOTE(VERSION_AR)];
_replacements set ["%LOADSCREEN_PATH%", QPATHTOEF(missions,data\loadscreen_co.paa)];
_replacements set ["%AUTHOR%", str profileName];
_replacements set ["%MISSION_NAME%", str _nameText];
_replacements set ["%MISSION_DESCRIPTION%", str _descriptionText];
_replacements set ["%COMBAT_TIME%", QUOTE(GVAR(combatTime))];
_replacements set ["%COMBAT_TIME_VALUE%", str _underfireTime];
_replacements set ["%RESPAWN_BUTTON_TIMER%", QUOTE(GVAR(respawnButtonTimer))];
_replacements set ["%RESPAWN_BUTTON_TIMER_VALUE%", str _respawnButtonTime];
_replacements set ["%CLONE_PHASE%", QUOTE(GVAR(clonePhase))];
_replacements set ["%CLONE_PHASE_VALUE%", str _phase];
_replacements set ["%TERRESTRIAL_VEHICLES%", QGVAR(TerrestrialVehicles)];
_replacements set ["%TRANSPORT_AERIAL_VEHICLES%", QGVAR(TransportAerialVehicles)];
_replacements set ["%ATTACK_AERIAL_VEHICLES%", QGVAR(AttackAerialVehicles)];
_replacements set ["%SUPPLY_CRATE%", QGVAR(SupplyCrate)];
_replacements set ["%RESPAWN_DELAY_VALUE%", str _respawnDelay];

// Load template from external file
private _templatePath = QPATHTOF(data\description_template.inc);
private _templateContent = loadFile _templatePath;

// Apply replacements to template
{
    _templateContent = [_templateContent, _x, _y] call CBA_fnc_replace;
} forEach _replacements;

_templateContent
