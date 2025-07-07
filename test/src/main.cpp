#include "../../inc/Debug.hpp"

int main()
{
	pd::DebugSettings debugSettings;
	debugSettings.debugID = true;
	debugSettings.blockedSave = false;
	debugSettings.timeStamp = false;
	debugSettings.timeZone = true;
	debugSettings.output = true;
	debugSettings.custom = false;

	// NOTE: CAN BE USED IF WANTED, UNCOMMENT THIS CODE TO USE THE FEATURE
	/*
	debugSettings.preStartMsg = "PRESTARTMSG - ";
	debugSettings.startMsg = "STARTMSG - ";
	
	debugSettings.endMsg = "- ENDMSG ";
	debugSettings.postEndMsg = "- POSTENDMSG ";
	debugSettings.totalEndMsg = " - TOTAL END";
	debugSettings.totalCustom = "Custom text for debug label";
	*/

	debugSettings.filePath = "./logs/log.log";

	pd::Debug debug("main-debug", debugSettings);

	debug.log("information", "This is a simple test for debugging");
	debug.log("error", "This is a simple test for debugging 2");
	debug.log("warning", "This is a simple test for debugging 3");

	return 0;
}

