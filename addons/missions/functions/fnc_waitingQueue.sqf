#include "..\script_component.hpp"
/*
 * Authors: Archer
 * This code create a waiting queue with a trigger so that a code can be executed after all of the conditions are met.
 *
 * Arguments:
 * 0: _thisTrigger (not optional, default: objNull) <OBJECT>
 * 1: _thisList (not optional, default: []) <ARRAY>
 * 2: _code (optional, default: {}) <CODE>
 * 3: _codeArgs (optional, default: []) <ARRAY>
 * 4: _percentageNecessary (optional, default: 0.5) <NUMBER>
 * 5: _waitTime (optional, default: 10) <NUMBER>
 * Return Value:
 * Return true|false <BOOL>
 *
 * Example:
 * [thisTrigger, thisList, { systemChat (_this select 0);},["test"]] call AR_missions_fnc_waitingQueue;
 *
 * Public: yes
 */
params [
    ["_thisTrigger", objNull, [objNull]],
    ["_thisList", [], [[]]],
    ["_code",{},[{}]],
    ["_codeArgs",[],[[]]],
    ["_percentageNecessary", 0.51, [0]],
    ["_waitTime", 10, [0]]
];

TRACE_1("fnc_waitingQueue",_this);

private _handler = _thisTrigger getVariable [QGVAR(perFrameHandler),0]; // Get the perFrameEventHandler (pFEH) ID. if it doesn't exist use 0.
private _missionStatus = missionNamespace getVariable [QGVAR(missionStatus),"notStarted"]; // Get The missionStatus value if it doesn't exist use "notStarted".

missionNamespace setVariable [QGVAR(countDown), _waitTime]; // Set the waitTime variable in the missionNamespace to reuse it in the pFEH

if(isNull _thisTrigger)exitWith{ // If the trigger doesn't exist then exit the code and return false.
    WARNING("WaitingQueue Trigger doesn't exist");
    false;
};

if(_waitTime < 1)then{ // If wait time is under 1 then use the default value. You don't want people waiting 0 seconds.
    WARNING("The wait time is too low. Using Default (10)");
    _waitTime = 10;
};

if (_percentageNecessary > 1 || _percentageNecessary < 0.1)then{ // if the percentage is too high then it's going to ask for more players than currently present.
    WARNING("The percentage of player is incorrect. Going with default (0.5)");
    _percentageNecessary = 0.5;
};

if((triggerActivated _thisTrigger) && (_handler == 0) && (_missionStatus isNotEqualTo "started"))then{ // If the trigger has been activated and the pFEH HandlerID does not already exist and the mission isn't started.
    _handler = [
        {
            params ["_args","_handlerID"];
            _args params ["_thisTrigger","_thisList","_percentageNecessary","_waitTime","_code","_codeArgs"];

            private _countPlayerListIn = ({alive _x} count _thisList); // Count all of the player already waiting inside the trigger (With the pFEH it checks every second).
            private _countAllPlayers = count allPlayers; // Count all of the currently connected player on the server.
            private _amountOfPlayerNeeded = floor(_countAllPlayers * _percentageNecessary); // Calculate the amount of player necessary to start the mission.
            private _countDown = missionNamespace getVariable [QGVAR(countDown),_waitTime]; // Get the countDown if it doesn't exist use the specified waitTime.

            if( _countPlayerListIn > _amountOfPlayerNeeded )then{ // If the amount of player that are waiting is stricly superior to the one needed then continue.
                
                if(_countDown <= 0)then{ // If the countdown is equal or less than 0 then start the code specified.
                    _codeArgs call _code; // Execute the code specified in the function.
                    _handlerID call CBA_fnc_removePerFrameHandler; // Remove the handler because it is not necessary from executing it anymore.
                    missionNamespace setVariable [QGVAR(missionStatus),"started"]; // Set the mission to started to not reexecute the script.
                    INFO("WaitingQueue : Handler Removed after mission Start"); // Log the handler being removed.
                }else{ // if the countDown is superior to 0.
                    [FORMAT_1(LLSTRING(waitingQueueStart),_countDown),0,0,1,0] remoteExec["BIS_fnc_dynamicText", 0, true];
					
                    [["\A3\Sounds_F_Bootcamp\SFX\VR\Simulation_Restart.wss",0.25]] remoteExec["playSoundUI",0, true];
                    _countDown = _countDown - 1;
                    missionNamespace setVariable [QGVAR(countDown),_countDown]; // Set the ar_countDown var to the current countDown value.
                };
            }else{ // This make it that the countdown is reset when someones leaves the trigger or if the amount of player is not respected.
                [FORMAT_3(LLSTRING(waitingQueue),_countPlayerListIn,_countAllPlayers,_amountOfPlayerNeeded + 1),0,0,1,0] remoteExec["BIS_fnc_dynamicText", 0, true];
                
                if(_countDown != _waitTime)then{ // If the _countDown is different than the _waitTime then
                    missionNamespace setVariable [QGVAR(countDown),_waitTime]; // Set the ar_countDown to the _waitTime
                }; 
            };
        },
        1, 
        [_thisTrigger,_thisList,_percentageNecessary,_waitTime,_code,_codeArgs] // Args for the pFEH function
    ] call CBA_fnc_addPerFrameHandler; // The pFEH execute a code every second.

    _thisTrigger setVariable [QGVAR(perFrameHandler),_handler,true]; // Set the pFEH handlerID in the missionNamespace.
}else{
    _handler = _thisTrigger getVariable [QGVAR(perFrameHandler),0]; // Get the pFEH HandlerID
    if(_handler > 0)then{ // If _handler is superior from 0 then it means a pFEH HandlerID exist.
        _handler call CBA_fnc_removePerFrameHandler; // remove the pFEH.
        INFO("Waiting Queue : Handler Removed");
        _thisTrigger setVariable [QGVAR(perFrameHandler),0,true]; // Set the handler value to 0 because it has been removed.
    };
};

true;
