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

[west, 2000, [
    ["Land_BagFence_Corner_F", 10, LLSTRING(fortify_lightcover)],
    ["Land_BagFence_Long_F", 10, LLSTRING(fortify_lightcover)],
    ["Land_BagFence_Round_F", 10, LLSTRING(fortify_lightcover)],
    ["Land_BagFence_Short_F", 10, LLSTRING(fortify_lightcover)],
    ["Land_SandbagBarricade_01_half_F", 20, LLSTRING(fortify_lightcover)],
    ["Land_SandbagBarricade_01_hole_F", 20, LLSTRING(fortify_lightcover)],
    ["Land_SandbagBarricade_01_F", 20, LLSTRING(fortify_lightcover)],
    ["Land_BagBunker_Large_F", 80, LLSTRING(fortify_heavycover)],
    ["3as_hbarricade", 20, LLSTRING(fortify_lightcover)],
    ["Land_TentLamp_01_suspended_F", 5, LLSTRING(fortify_lights)],
    ["Land_TentLamp_01_standing_F", 5, LLSTRING(fortify_lights)],
    ["Land_OPTRE_Light_Column_white", 5, LLSTRING(fortify_lights)],
    ["3AS_FOB_Light_Prop", 5, LLSTRING(fortify_lights)],
    ["3AS_Cover1", 15, LLSTRING(fortify_mediumcover)],
    ["3AS_Cover2", 20, LLSTRING(fortify_mediumcover)],
    ["3AS_Barricade_2_C_prop", 25, LLSTRING(fortify_mediumcover)],
    ["3AS_H_barrier_small_1", 40, LLSTRING(fortify_heavycover)],
    ["3AS_H_barrier_small_3", 50, LLSTRING(fortify_heavycover)],
    ["land_3as_GenericStairsS", 50, LLSTRING(fortify_structure)],
    ["3AS_H_barrier_small_5", 50, LLSTRING(fortify_heavycover)],
    ["land_3as_Ladder3", 15, LLSTRING(fortify_structure)],
    ["3AS_Short_Wall_Bunker", 80, LLSTRING(fortify_heavycover)],
    ["cwa_HeliH", 5, LLSTRING(fortify_structure)],
    ["Land_Plank_01_8m_F", 6, LLSTRING(fortify_structure)],
    ["Land_Plank_01_4m_F", 6, LLSTRING(fortify_structure)],
    ["3AS_HeavyRepeater_Unarmoured", 110, LLSTRING(fortify_weaponry)],
    ["3AS_Republic_Mortar", 125, LLSTRING(fortify_weaponry)],
    ["3as_hbarrier_bunker", 80, LLSTRING(fortify_heavycover)],
    ["3as_hbarrierwall_4r", 80, LLSTRING(fortify_heavycover)],
    ["Land_lsb_fob_hBarrier_5", 80, LLSTRING(fortify_heavycover)],
    ["3as_hbarrierwall_4r", 80, LLSTRING(fortify_heavycover)],
    ["Land_lsb_fob_hBarrier_3",80,LLSTRING(fortify_heavycover)],
    ["Land_lsb_fob_hBarrier_3",80,LLSTRING(fortify_heavycover)],
    ["Land_CamoNetVar_NATO_EP1",10,LLSTRING(fortify_lightcover)],
    ["Land_CamoNetB_NATO_EP1",10,LLSTRING(fortify_lightcover)],
    ["Land_CamoNetVar_NATO",10,LLSTRING(fortify_lightcover)],
    ["Land_CamoNetB_NATO",10,LLSTRING(fortify_lightcover)],
    ["Land_BagFence_Short_F",5,LLSTRING(fortify_lightcover)],
    ["Land_BagFence_Round_F",5,LLSTRING(fortify_lightcover)],
    ["Land_BagFence_Long_F",5,LLSTRING(fortify_lightcover)],
    ["Land_BagFence_Corner_F",5,LLSTRING(fortify_lightcover)],
    ["Land_SandbagBarricade_01_half_F",20,LLSTRING(fortify_mediumcover)],
    ["Land_SandbagBarricade_01_F",20,LLSTRING(fortify_mediumcover)],
    ["Land_SandbagBarricade_01_hole_F",20,LLSTRING(fortify_mediumcover)],
    ["SFA_Imp_tent_open",20,LLSTRING(fortify_mediumcover)],
    ["SFA_Imp_tent_open",20,LLSTRING(fortify_mediumcover)],
    ["3AS_Shield_3_Prop",16,LLSTRING(fortify_mediumcover)],
    ["3AS_Shield_5_Prop",20,LLSTRING(fortify_mediumcover)],
    ["3AS_Shield_C_Prop",30,LLSTRING(fortify_mediumcover)],
    ["Land_JMSLLTE_roadblockbarrier",10,LLSTRING(fortify_lightcover)],
    ["Land_fort_bagfence_round",20,LLSTRING(fortify_mediumcover)],
    ["land_ReachWallBarrier",10,LLSTRING(fortify_lightcover)]
]] call acex_fortify_fnc_registerObjects;
