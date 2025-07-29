#include "..\script_component.hpp"
/*
     * Authors: Adeptus TEAM
     * Description: Set and synchronize the server name for the mission
     *
     * Arguments:
     * <NONE>
     *
     * Return Value:
     * <NONE>
     *
     * Example:
     * [] call ar_missions_fnc_setServerName
     *
     * Public: No
 */

params [];

TRACE_1("fnc_setServerName",_this);

GVAR(serverName) = getServerInfo getOrDefault ["hostname", "N/A"];
publicVariable QGVAR(serverName);

INFO_1("Server name set to: %1",GVAR(serverName));
