#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

ADDON = true;

if (!isDedicated) exitWith {};

// Base de la mission (description.ext : db_mode = "MaCampagne";). "Main" par défaut.
// Un nom invalide désactive la sauvegarde plutôt que d'écrire par erreur dans "Main".
GVAR(dbMode) = getMissionConfigValue ["db_mode", DEFAULT_DB_MODE];
if !(GVAR(dbMode) isEqualType "" && {GVAR(dbMode) regexMatch "^[A-Za-z0-9_-]{1,32}$"}) exitWith {
	ERROR_1("[DATABASE] Invalid db_mode in description.ext: %1 (letters, digits, _ or -, 32 max). Player data will not be saved.",GVAR(dbMode));
};
// "main", "MAIN"... -> "Main", pour que le site retrouve toujours la base principale sous ce nom
if (GVAR(dbMode) == DEFAULT_DB_MODE) then {
	GVAR(dbMode) = DEFAULT_DB_MODE;
};
INFO_1("[DATABASE] db_mode: %1",GVAR(dbMode));

// Connexion à MySQL via extDB3
if !([] call FUNC(init)) exitWith {};

// SteamID64 dont le profil a été chargé (ou créé) pendant cette session.
// Seuls ceux-là sont sauvegardés : l'équipement par défaut de la mission n'écrase jamais une sauvegarde.
GVAR(loadedUIDs) = createHashMap;
// SteamID64 dont une sauvegarde est déjà programmée
GVAR(pendingSaves) = createHashMap;

// Un client signale que son unité est prête : chargement ou création du profil
[QGVAR(playerReady), {
	params ["_player"];
	[_player] call FUNC(initPlayer);
}] call CBA_fnc_addEventHandler;

// Un client (ou le serveur) signale un changement d'équipement ou de spécialité
[QGVAR(requestSave), {
	params ["_player"];
	[_player] call FUNC(requestSave);
}] call CBA_fnc_addEventHandler;

addMissionEventHandler ["HandleDisconnect", {
	params ["_unit", "_id", "_uid", "_name"];
	if (_uid in GVAR(loadedUIDs)) then {
		[_unit, _uid] call FUNC(savePlayer);
		GVAR(loadedUIDs) deleteAt _uid;
		GVAR(pendingSaves) deleteAt _uid;
	};
	false
}];

// Sauvegarde périodique de secours (les changements sont déjà sauvegardés au fil de l'eau)
[{
	{
		private _uid = getPlayerUID _x;
		if (_uid in GVAR(loadedUIDs)) then {
			[_x, _uid] call FUNC(savePlayer);
		};
	} forEach allPlayers;
}, SAVE_INTERVAL] call CBA_fnc_addPerFrameHandler;

INFO("[DATABASE] Handlers initialized on dedicated server.");
