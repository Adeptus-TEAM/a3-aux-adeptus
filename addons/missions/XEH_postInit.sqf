#include "script_component.hpp"

if (isServer) then {
	// Initialize the medical task system
	[] call FUNC(initMedicalTask);
	
	// Initialize the server name for the welcome message
	[] call FUNC(setServerName);
};

if (hasInterface) then {
	private _unit = player;
	
	[_unit] call FUNC(initUnderfire);
	[_unit] call FUNC(initWelcome);
	[_unit] call FUNC(initRespawn);
};
