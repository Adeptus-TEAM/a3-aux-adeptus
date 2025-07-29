#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Opens the mission parameters dialog.
	 *
	 * Arguments:
	 * <NONE>
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * call ar_missions_builder_fnc_openInterface
	 *
	 * Public: No
 */

TRACE_1("ar_missions_builder_fnc_openInterface",_this);

if (is3DEN) then {
	if (!fileExists "description.ext") then {
		(findDisplay 313) createDisplay "rscMissionParameters";
	} else {
		[LSUBLSTRING(descriptionExtExistsError), 1] call BIS_fnc_3DENNotification;
		WARNING("ar_missions_builder_fnc_openInterface: This function should only be called in 3DEN editor context.");
	};
} else {
	ERROR("ar_missions_builder_fnc_openInterface: description.ext file already exists. Cannot open mission parameters interface.");
};
