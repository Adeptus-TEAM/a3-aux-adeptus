#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Checks the version of the mod and mission template.
	 *
	 * Arguments:
	 * <NONE>
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [] call ar_missions_fnc_initCheckVersion
	 *
	 * Public: No
 */

if (is3DEN) exitWith {
	INFO("ar_missions_fnc_initCheckVersion: This function should not be called in 3DEN editor.");
};

if (!isMultiplayer) exitWith {
	INFO("ar_missions_fnc_initCheckVersion: This function is only applicable in multiplayer.");
};

if (isServer) then { // Server-side code to check the mod version
	if ((!fileExists "description.ext") && isMultiplayer) exitWith { // Check if the description.ext file exists and if the mission is multiplayer
		ERROR("ar_missions_fnc_initCheckVersion: description.ext file not found.");
		"missingDescriptionExt" call BIS_fnc_endMissionServer; // End the mission on the server side
	};

	GVAR(modVersionServer) = [configFile >> "CfgMods" >> "AdeptusRepublica","versionAr",[0,0,0]] call BIS_fnc_returnConfigEntry; // Get the mod version from the config file
	publicVariable QGVAR(modVersionServer);

	private _formatedServerVersion = FORMAT_3("%1.%2.%3",ARG_1(GVAR(modVersionServer),0),ARG_1(GVAR(modVersionServer),1),ARG_1(GVAR(modVersionServer),2)); // Format the server mod version

	INFO_1(LLSTRING(modVersionServer),_formatedServerVersion);

	// Check if the mod version is compatible with the mission template
	private _minimalVersion = getMissionConfigValue [QGVAR(minimalVersion), [0,0,0]]; // Get the minimal version from the mission config
	private _formatedMinimalVersion = FORMAT_3("%1.%2.%3",ARG_1(_minimalVersion,0),ARG_1(_minimalVersion,1),ARG_1(_minimalVersion,2)); // Format the minimal version

	{
		if (_x < (_minimalVersion # _forEachIndex)) exitWith {
			ERROR_2(LLSTRING(modVersionIncompatible),_formatedServerVersion,_formatedMinimalVersion);
			"modVersionIncompatible" call BIS_fnc_endMissionServer; // End the mission on the server side
		};
	} forEach GVAR(modVersionServer);
};

if (hasInterface) then { // Client-side code to check the mod version
	[
		{
			!isNil QGVAR(modVersionServer) // Wait until the server version is available
		},
		{
			private _modVersionClient = [configFile >> "CfgMods" >> "AdeptusRepublica","versionAr",[0,0,0]] call BIS_fnc_returnConfigEntry; // Get the mod version from the config file on the client side
			private _formatedVersionClient = FORMAT_3("%1.%2.%3",ARG_1(_modVersionClient,0),ARG_1(_modVersionClient,1),ARG_1(_modVersionClient,2)); // Format the client mod version
			private _formatedVersionServer = FORMAT_3("%1.%2.%3",ARG_1(GVAR(modVersionServer),0),ARG_1(GVAR(modVersionServer),1),ARG_1(GVAR(modVersionServer),2)); // Format the server mod version
			if (_modVersionClient isEqualTo GVAR(modVersionServer)) then { // Compare the client and server mod versions
				INFO_2(LLSTRING(modVersionMatch),_formatedVersionClient,_formatedVersionServer);
			} else { // If the versions do not match, display an error message and end the mission for the player
				ERROR_2(LLSTRING(modVersionMismatch),_formatedVersionClient,_formatedVersionServer);
				[
					{
						!isNull player // Wait until the player is not null
					},
					{
						["modVersionMismatch"] remoteExec ["endMission", player, true]; // End the mission for the player
					}
				] call CBA_fnc_waitUntilAndExecute;
			};
		}
	] call CBA_fnc_waitUntilAndExecute;
};
