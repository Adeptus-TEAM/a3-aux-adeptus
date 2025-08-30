#include "script_component.hpp"

if (isServer) then {
	// Initialize the medical task system
	[] call FUNC(initMedicalTask);
	// Initialize the fortify system
	[] call FUNC(initFortify);
	// Initialize the server name for the welcome message
	[] call FUNC(setServerName);
	// Initialize the dynamic groups system server side
	["Initialize"] call BIS_fnc_dynamicGroups;
};

if (hasInterface) then {
	private _unit = player;
	[_unit] call FUNC(initUnderfire);
	[_unit] call FUNC(initWelcome);
	[_unit] call FUNC(initRespawn);
	[_unit] call FUNC(initVerifyLoadout);
	["InitializePlayer",[_unit]] call BIS_fnc_dynamicGroups;
};
