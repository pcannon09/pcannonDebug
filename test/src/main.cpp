#include <iostream>
#include <string>

#include "../../inc/Debug.hpp"
#include "../../inc/macros.hpp"

int main()
{
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

	pd::Debug debug("main-debug", debugSettings);

	debug.log("information", "This is a simple test for debugging (DEBUG LEVEL 1)", 1);
	debug.log("error", "This is a simple test for debugging 2 (DEBUG LEVEL 2)", 2);
	debug.log("warning", "This is a simple test for debugging 3 (DEBUG LEVEL 3)", 3);

	PD_DEBUGLOG(debug, "information", "This is a complex PD_DEBUGLOG message");
	PD_SIMPLE_DEBUGLOG("information", "This is a simple PD_SIMPLE_DEBUGLOG message");

	return 0;
}

