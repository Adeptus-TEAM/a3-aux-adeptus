#include "script_component.hpp"

if (!hasInterface || {!isMultiplayer}) exitWith {};

// Attendre l'unité du joueur : un objet nul envoyé au serveur ne serait jamais résolu
[
	{!isNull player},
	{[QGVAR(playerReady), [player]] call CBA_fnc_serverEvent}
] call CBA_fnc_waitUntilAndExecute;

// Sauvegarde dès que l'équipement change. L'évènement CBA "loadout" se déclenche aussi à chaque tir
// (munitions), donc on n'envoie la demande que quelques secondes après le dernier changement.
GVAR(loadoutChangeId) = 0;
["loadout", {
	GVAR(loadoutChangeId) = GVAR(loadoutChangeId) + 1;
	[{
		params ["_changeId"];
		if (_changeId == GVAR(loadoutChangeId)) then {
			[QGVAR(requestSave), [player]] call CBA_fnc_serverEvent;
		};
	}, [GVAR(loadoutChangeId)], 5] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addPlayerEventHandler;
