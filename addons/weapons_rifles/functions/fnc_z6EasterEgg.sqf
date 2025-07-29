#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to handle the firing of the Z6 weapon.
	 *
	 * Arguments:
	 * 0: _unit (default: objNull) <OBJECT> - The unit that fired the weapon.
	 * extra information be passed in the _this array, see : https://community.bohemia.net/wiki/Arma_3:_Event_Handlers#Fired
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * _this call ar_weapons_rifles_fnc_z6EasterEgg
	 *
	 * Public: No
 */

params [
	["_unit", objNull, [objNull]]
];

TRACE_1("ar_weapons_rifles_fnc_z6EasterEgg",_this);

private _bulletCount = _unit getVariable [QGVAR(Z6_bulletCount), 0];

INC(_bulletCount); // Increment the bullet count
_unit setVariable [QGVAR(Z6_bulletCount), _bulletCount, true]; // Update the bullet count variable

if (_bulletCount >= 100) then { // If the bullet count reaches 100, play a sound and reset the count
	private _coinFlip = (random 1);
	if (_coinFlip > 0.5) then {
		playSound3D [QPATHTOF(data\sounds\z6_easteregg.ogg), _unit, false, _unit, 5, 1];
	};
	_unit setVariable [QGVAR(Z6_bulletCount), 0, true]; // Reset the bullet count
};

[
	{
		params ["_unit", "_bulletCount"];
		if (_bulletCount != _unit getVariable [QGVAR(Z6_bulletCount), 0]) exitWith {};
		// Reset the bullet count
		_unit setVariable [QGVAR(Z6_bulletCount), 0, true];
	},
	[_unit, _bulletCount],
	10
] call CBA_fnc_waitAndExecute;
