#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Initializes the fortification system for the mission.
	 *
	 * Arguments:
	 * 0: _side (optional, default: west) <side> - The side for which the fortification system will be initialized.
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [east] call ar_missions_fnc_initFortify
	 *
	 * Public: No
 */

params [
	["_side", west, [west]]
];
TRACE_1("fnc_initFortify",_this);

[west, 500, [
	["3AS_Cover1", 15],
	["3AS_Cover2", 20],
	["3AS_Barricade_2_C_prop", 25],
	["3AS_H_barrier_small_1", 40],
	["3AS_H_barrier_small_3", 50],
	["land_3as_GenericStairsS", 50],
	["3AS_H_barrier_small_5", 50],
	["land_3as_Ladder3", 15],
	["3AS_Short_Wall_Bunker", 80],
	["cwa_HeliH", 5],
	["Land_Plank_01_8m_F", 6],
	["Land_Plank_01_4m_F", 6],
	["3AS_HeavyRepeater_Unarmoured", 110],
	["3AS_Republic_Mortar", 125]
]] call acex_fortify_fnc_registerObjects;
