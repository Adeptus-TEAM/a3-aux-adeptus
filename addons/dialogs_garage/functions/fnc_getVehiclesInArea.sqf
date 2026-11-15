#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description: Returns all vehicles inside the garage area (width, length and height).
 *
 * Arguments:
 * <NONE>
 *
 * Return Value:
 * Vehicles in the garage area <ARRAY> - [] on error or if empty
 *
 * Example:
 * 0 call ar_dialogs_garage_fnc_getVehiclesInArea
 *
 * Public: No
 */

params [];
TRACE_1("fnc_getVehiclesInArea",_this);

private _terminalData = 0 call SUBFUNC(getTerminalData);
if (_terminalData isEqualTo []) exitWith {[]};

_terminalData params ["_pos", "_dir", "_sizeA", "_sizeB", "_isRectangle", "_height", "_posASL"];

// Horizontal check: vehicles inside the area footprint.
private _vehicles = vehicles inAreaArray [_pos, _sizeA, _sizeB, _dir, _isRectangle];

// Vertical check: height relative to the module, not to the terrain,
// so it also works on buildings and carriers.
private _baseZ = _posASL select 2;
_vehicles select {
	private _relativeZ = (getPosASL _x select 2) - _baseZ;
	_relativeZ > -2 && {_relativeZ <= _height}
}
