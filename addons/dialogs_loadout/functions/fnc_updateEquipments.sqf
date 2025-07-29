#include "..\script_component.hpp"
/*
	 * Authors: Adeptus TEAM
	 * Description: Function to update the loadout equipment list.
	 *
	 * Arguments:
	 * 0: _listEquipement (default: controlNull) <CONTROL> - The control for the equipment list.
	 * 1: _classSel (default: "") <STRING> - The selected class for the loadout.
	 * 2: _subClassSel (default: "") <STRING> - The selected subclass for the loadout.
	 *
	 * Return Value:
	 * Return description <NONE>
	 *
	 * Example:
	 * [_listEquipement, "className", "subClassName"] call ar_dialogs_loadout_fnc_updateEquipments
	 *
	 * Public: No
 */

params [
	["_listEquipement", controlNull, [controlNull]],
	["_classSel", "", [""]],
	["_subClassSel", "", [""]]
];

TRACE_1("ar_dialogs_loadout_fnc_updateEquipments",_this);

private _loadout = call compile (getText(configFile >> "CfgLoadouts" >> _classSel >> "loadoutsInfo" >> _subClassSel >> "loadoutArray"));

private _playerData = uiNamespace getVariable [QGVAR(playerLoadoutData), []];
_playerData params ["_player"];

_player setUnitLoadout _loadout;

lbClear _listEquipement;

private _primaryWeapon = ARG_2(_loadout,0,0);
if (_primaryWeapon != "") then {
	private _primaryWeaponName = FORMAT_1("=== %1 ===",[configFile >> "CfgWeapons" >> _primaryWeapon] call BIS_fnc_displayName);
    private _index = _listEquipement lbAdd _primaryWeaponName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _primaryWeapon >> "picture")];
};

private _secondaryWeapon = ARG_2(_loadout,1,0);
if (_secondaryWeapon != "") then {
	private _secondaryWeaponName = FORMAT_1("=== %1 ===",[configFile >> "CfgWeapons" >> _secondaryWeapon] call BIS_fnc_displayName);
    private _index = _listEquipement lbAdd _secondaryWeaponName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _secondaryWeapon >> "picture")];
};

private _handgun = ARG_2(_loadout,2,0);
if (_handgun != "") then {
	private _handgunName = FORMAT_1("=== %1 ===",[configFile >> "CfgWeapons" >> _handgun] call BIS_fnc_displayName);
    private _index = _listEquipement lbAdd _handgunName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _handgun >> "picture")];
};

_listEquipement lbAdd " ";	//Add a space before

private _headgear = ARG_1(_loadout,6);
if (_headgear != "") then {
	private _headgearName = FORMAT_1("=== %1 ===",[configFile >> "CfgWeapons" >> _headgear] call BIS_fnc_displayName);
    private _index = _listEquipement lbAdd _headgearName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _headgear >> "picture")];
};

private _goggles = ARG_1(_loadout,7);
if (_goggles != "") then {
    private _gogglesName = [configFile >> "CfgWeapons" >> _goggles] call BIS_fnc_displayName;
    private _index = _listEquipement lbAdd _gogglesName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _goggles >> "picture")];
};

private _binoculars = ARG_2(_loadout,8,0);
if (_binoculars != "") then {
    private _binocularsName = [configFile >> "CfgWeapons" >> _binoculars] call BIS_fnc_displayName;
    private _index = _listEquipement lbAdd _binocularsName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _binoculars >> "picture")];
};

private _assignedItems = ARG_1(_loadout,9);
{
    private _item = _x;
    if (_item != "") then {
        private _itemName = [configFile >> "CfgWeapons" >> _item] call BIS_fnc_displayName;
        private _index = _listEquipement lbAdd _itemName;
        _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _item >> "picture")];
    };
} forEach _assignedItems;

private _uniform = ARG_2(_loadout,3,0);
if (_uniform != "") then {
    _listEquipement lbAdd " ";	//Add a space before

    private _uniformName = FORMAT_1("=== %1 ===",[configFile >> "CfgWeapons" >> _uniform] call BIS_fnc_displayName);
    private _index = _listEquipement lbAdd _uniformName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _uniform >> "picture")];
};

private _uniformItems = ARG_2(_loadout,3,1);
{
    _x params ["_item", "_count"];
    if (_item != "") then {
        private _cfgSource = configFile >> "CfgWeapons" >> _item;
        private _itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
        if (_itemDisplayName isEqualTo "") then {
            _cfgSource = configFile >> "CfgMagazines" >> _item;
            _itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
        };
        private _itemName = FORMAT_2("%1 (x%2)",_itemDisplayName,_count);
        private _index = _listEquipement lbAdd _itemName;
        _listEquipement lbSetPicture [_index, getText (_cfgSource >> "picture")];
    };
} forEach _uniformItems;

private _vest = ARG_2(_loadout,4,0);
if (_vest != "") then {
    _listEquipement lbAdd " ";	//Add a space before

    private _vestName = FORMAT_1("=== %1 ===",[configFile >> "CfgWeapons" >> _vest] call BIS_fnc_displayName);
    private _index = _listEquipement lbAdd _vestName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgWeapons" >> _vest >> "picture")];
};

private _vestItems = ARG_2(_loadout,4,1);
{
    _x params ["_item", "_count"];
    if (_item != "") then {
        private _cfgSource = configFile >> "CfgWeapons" >> _item;
        private _itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
        if (_itemDisplayName isEqualTo "") then {
            _cfgSource = configFile >> "CfgMagazines" >> _item;
            _itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
        };
        private _itemName = FORMAT_2("%1 (x%2)",_itemDisplayName,_count);
        private _index = _listEquipement lbAdd _itemName;
        _listEquipement lbSetPicture [_index, getText (_cfgSource >> "picture")];
    };
} forEach _vestItems;

private _backpack = ARG_2(_loadout,5,0);
if (_backpack != "") then {
    _listEquipement lbAdd " ";	//Add a space before
    private _backpackName = FORMAT_1("=== %1 ===",[configFile >> "CfgVehicles" >> _backpack] call BIS_fnc_displayName);
    private _index = _listEquipement lbAdd _backpackName;
    _listEquipement lbSetPicture [_index, getText (configFile >> "CfgVehicles" >> _backpack >> "picture")];
};

private _backpackItems = ARG_2(_loadout,5,1);
{
    _x params ["_item", "_count"];
    if (_item != "") then {
        private _cfgSource = configFile >> "CfgWeapons" >> _item;
        private _itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
        if (_itemDisplayName isEqualTo "") then {
            _cfgSource = configFile >> "CfgMagazines" >> _item;
            _itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
        };
        private _itemName = FORMAT_2("%1 (x%2)",_itemDisplayName,_count);
        private _index = _listEquipement lbAdd _itemName;
        _listEquipement lbSetPicture [_index, getText (_cfgSource >> "picture")];
    };
} forEach _backpackItems;
