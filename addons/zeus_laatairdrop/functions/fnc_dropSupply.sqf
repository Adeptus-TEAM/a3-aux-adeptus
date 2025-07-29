#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to perform the Laat Air drop operation.
	 *
	 * Arguments:
	 * 0: _module (default: objNull) <OBJECT> - The module object that contains the Laat Air drop parameters.
	 * 1: _supplyCrate (default: []) <ARRAY> - The type of supply crate to drop.
	 * 2: _height (default: 100) <NUMBER> - The height at which to drop the supply crate.
	 * 3: _direction (default: 0) <NUMBER> - The direction of the drop in degrees (0-360).
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [myModule] call ar_zeus_laatAirDrop_fnc_dropSupply
	 *
	 * Public: No
 */

params [
	["_module", objNull, [objNull]],
	["_supplyCrate", [], [[]]],
	["_height", 100, [100]],
	["_direction", 0, [0]]
];

TRACE_1("ar_zeus_laatAirDrop_fnc_dropSupply",_this);

private _distance = 5000;
private _dropPos = getPosATL _module;

private _originPos = _module getPos [_distance, (_direction - 180)];

private _finalPos = _module getPos [_distance, _direction];

deleteVehicle _module;

if (_supplyCrate isEqualTo []) exitWith {
	[
		LSUBLSTRING(header),
		LSUBLSTRING(drop_cancel),
		5
	] call BIS_fnc_curatorHint;
	WARNING("ar_zeus_laatAirDrop_fnc_dropSupply: No supply crate specified.");
};

private _veh = [_originPos, _distance, "ar_vehicles_laat_i_Mk2", blufor] call BIS_fnc_spawnVehicle;

private _laat = ARG_1(_veh,0);
private _grp = ARG_1(_veh,2);

_laat setPosATL [ARG_1(_originPos,0), ARG_1(_originPos,1), 500];
_laat setDir _direction;
_laat flyInHeight _height;
_laat limitSpeed 200;
_laat allowDamage false;

private _wp1 = _grp addWaypoint [_dropPos vectorAdd [0, 0, _height], 0];
_wp1 setWaypointType "MOVE";
_wp1 setWaypointSpeed "FULL";
_wp1 setWaypointBehaviour "CARELESS";

private _wp2 = _grp addWaypoint [_finalPos, 0];
_wp2 setWaypointType "MOVE";

private _crates = [];

{
	private _crate = _x createVehicle [0, 0, 0];

	[_crate, _laat, true] call ace_cargo_fnc_loadItem;

	PUSH(_crates,_crate);
} forEach _supplyCrate;

[
	LSUBLSTRING(header),
	LSUBLSTRING(drop_confirmed),
	5
] call BIS_fnc_curatorHint;

[
	{
		params ["_laat", "_crates", "_dropPos"];
		((_laat distance2D _dropPos) <= 75)
	},
	{
		params ["_laat", "_crates", "_dropPos", "_finalPos"];
		
		{
			[{
				params ["_crate", "_laat"];
				[_crate, _laat] call ace_cargo_fnc_paradropItem;
				{ _x addCuratorEditableObjects [[_crate], true]; } forEach allCurators;
			}, [_x, _laat], (_forEachIndex * 0.5)] call CBA_fnc_waitAndExecute;
		} forEach _crates;

		[
			{
				params ["_laat", "_finalPos"];
				((_laat distance2D _finalPos) <= 100)
			},
			{
				params ["_laat", "_finalPos"];
				deleteVehicleCrew _laat;
				deleteVehicle _laat;
				TRACE_1("Laat Air drop completed",_laat);
			},
			[_laat, _finalPos]
		] call CBA_fnc_waitUntilAndExecute;
	},
	[_laat, _crates, _dropPos, _finalPos]
] call CBA_fnc_waitUntilAndExecute;
