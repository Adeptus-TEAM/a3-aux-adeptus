#include "script_component.hpp"

if (hasInterface) then {
	// Wait for the player unit: a null object sent to the server would never resolve
	[
		{!isNull player},
		{[player] remoteExec [QFUNC(initPlayerData), 2]}
	] call CBA_fnc_waitUntilAndExecute;
};
