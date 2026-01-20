#include "..\script_component.hpp"
/*
 * Authors: Archer
 * Description.
 *
 * Arguments:
 * 0: EventHandler (no, default: 0) <EH>
 *
 * Return Value:
 * Return description <NONE>
 *
 * Example:
 * _this call ar_weapons_grenades_fnc_empEffect
 *
 * Public: No
 */

params ["_shot", "_shooter", "_hitobj", "_pos"];
TRACE_1("fnc_empEffect",_this);

private _dekaInZone = (nearestObjects [_pos, ["3AS_Deka_Static_Base"],10]);

{
_x setVariable ["ShieldStatus", 0, true];
_x animateSource ["ShieldLayer_BaseFront",1,true]; 
_x setHitPointDamage ["HitShield",0,false];
} forEach _dekaInZone;