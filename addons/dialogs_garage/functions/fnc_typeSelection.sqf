#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description : Handles the type selection for the garage dialog, updating the vehicle list based on the selected type.
 *
 * Arguments:
 * 0: Index of Vehicle Type <NUMBER>
 *		0 = Terrastrial, 1 = Aerial, 2 = Supply
 *
 * Return Value:
 * <NONE>
 *
 * Example:
 * [0] call PREFIX_dialogs_garage_fnc_typeSelection
 *
 * Public: No
 */

params [
	["_selectionIndex", 0, [0]]
];
TRACE_1("fnc_typeSelection",_this);

// Get the list of vehicles based on the selected type index
private _vehicleSelectionList = switch (_selectionIndex) do {
	case 0: {getMissionConfigValue QEGVAR(missions,TerrestrialVehicles);};
	case 1: {getMissionConfigValue QEGVAR(missions,AerialVehicles);};
	case 2: { getMissionConfigValue QEGVAR(missions,SupplyCrate);};
	default { [] };
};

// Store the last type selection index for the next time the dialog is opened
uiNamespace setVariable [QGVAR(lastTypeSelection), _selectionIndex]; // Initialize the last type selection variable on the terminal

// Update the vehicle list in the dialog based on the selected type
[_vehicleSelectionList] call SUBFUNC(updateVehicleList);
