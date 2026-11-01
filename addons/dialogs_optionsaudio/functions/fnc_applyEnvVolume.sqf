#include "..\script_component.hpp"
/*
 * Author: Archer
 * Re-applies the stored environment volume at mission start.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call ar_dialogs_optionsaudio_fnc_applyEnvVolume
 *
 * Public: No
 */
if (!hasInterface) exitWith {};
0 fadeEnvironment (profileNamespace getVariable [QGVAR(envVolume), 1]);
