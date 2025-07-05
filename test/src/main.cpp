#include "../../inc/Debug.hpp"

int main()
{
	pd::DebugSettings debugSettings;
	debugSettings.debugID = true;
	debugSettings.blockedSave = false;
	debugSettings.timeStamp = true;
	debugSettings.timeZone = true;
	debugSettings.output = true;

	debugSettings.blockedSave = false;
	debugSettings.custom = false;

	debugSettings.filePath = "./logs/log.log";

	pd::Debug debug("main-debug", debugSettings);

	debug.log("INFORMATION", "This is a simple test for debugging");
	debug.log("ERROR", "This is a simple test for debugging 2");
	debug.log("WARNING", "This is a simple test for debugging 3");

	return 0;
}

