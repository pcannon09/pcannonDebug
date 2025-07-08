#include <iostream>
#include <string>

#include "../../inc/Debug.hpp"
#include "../../inc/macros.hpp"

int main()
{
	// NOTE:
	// Set the settings for the debugger
	// This is not required, but if needed to customize the output, it can be used
	pd::DebugSettings debugSettings;
	debugSettings.debugID = true;
	debugSettings.blockedSave = false;
	debugSettings.timeStamp = false;
	debugSettings.timeZone = true;
	debugSettings.output = true;
	debugSettings.custom = false;
	debugSettings.logLevelIgnoreOutput = false;
	debugSettings.logLevelIgnoreSave = false;
	debugSettings.logLevel = 0;

	debugSettings.filePath = "./logs/log.log";

	// NOTE: CAN BE USED IF WANTED, UNCOMMENT THIS CODE TO USE THE FEATURE
	/*
	debugSettings.preStartMsg = "PRESTARTMSG - ";
	debugSettings.startMsg = "STARTMSG - ";
	
	debugSettings.endMsg = "- ENDMSG ";
	debugSettings.postEndMsg = "- POSTENDMSG ";
	debugSettings.totalEndMsg = " - TOTAL END";
	debugSettings.totalCustom = "Custom text for debug label";
	*/

	// Create the debug object instance with the specified ID and settings
	pd::Debug debug("main-debug", debugSettings);

	// Log the output with desired log level, message and debug type (Information, Error...)
	debug.log("information", "This is a simple test for debugging (DEBUG LEVEL 1)", 1);
	debug.log("error", "This is a simple test for debugging 2 (DEBUG LEVEL 2)", 2);
	debug.log("warning", "This is a simple test for debugging 3 (DEBUG LEVEL 3)", 3);

	// Set a complex debug log with the specified debugger, type and message
	// Type is always set to 0 for maximized debugging
	PD_DEBUGLOG(debug, "information", "This is a complex PD_DEBUGLOG message");

	// Set a simple debug log without setting up the debugger nor creating a new object
	PD_SIMPLE_DEBUGLOG("information", "This is a simple PD_SIMPLE_DEBUGLOG message");

	return (debug.close() ? 0 : 1);
}

