#include "script_component.hpp"

// A mission (or the menu scene) starts: the opening sequence will play again on the next main menu
if (hasInterface) then {
	uiNamespace setVariable [QGVAR(introPlayed), false];
};

// Keep a copy of the player's "Main" loadout on this PC, so the main menu can dress the soldier with it
[] call SUBFUNC(cacheLoadout);
