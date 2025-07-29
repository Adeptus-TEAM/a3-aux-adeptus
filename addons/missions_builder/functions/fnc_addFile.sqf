#include "..\script_component.hpp"
/*
 * Authors: Adeptus TEAM
 * Description : Adds a file to the mission directory.
 *
 * Arguments:
 * 0: _filename (default: "init.sqf") <STRING> - The name of the file to create or modify in the mission directory.
 * 1: _data (default: "hint 'Hello World';") <STRING> - The content to write into the file.
 *
 * Return Value:
 * <BOOLEAN> - Returns true if the file was successfully written, false otherwise.
 *
 * Example:
 * ["description.ext", ""] call ar_missions_builder_fnc_addFile
 *
 * Public: No
 */

params [
	["_filename", "init.sqf", [""]],
	["_data", "hint 'Hello there';", [""]]
];

TRACE_1("ar_missions_builder_fnc_addFile",_this);

private _filePath = getMissionPath _filename; // Get the full path to the file in the mission directory
private _data = _data; // Data to write to the file

// Enclose the file path in double quotes
private _escapedFilePath = FORMAT_1('"%1"',_filePath);

// Prepare the command string
private _commandString = FORMAT_2("write %1 %2",_escapedFilePath,_data);
// Call the extension
private _result = "Arma3FileWriter" callExtension _commandString;
TRACE_1("ar_missions_builder_fnc_addFile",_result); // Should display "SUCCESS" or an error message

if (_result != "SUCCESS") exitWith {
	WARNING("ar_missions_builder_fnc_addFile - Error writing file: " + _result);
	false
};

true
