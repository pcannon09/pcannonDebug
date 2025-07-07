#pragma  once

#if __cplusplus >= 201103L

#if __cplusplus < 201703L
# 	ifdef __PD_NO_FULL_SUPPORT
# 		undef __PD_NO_FULL_SUPPORT
# 	endif
# 	define __PD_NO_FULL_SUPPORT
# 	warning "No full support for the current C++ standard (Full Support is in C++17)"
#endif

#include <string>
#include <fstream>
#include <utility>

namespace pd
{
	typedef struct DebugSettings
	{
		bool timeStamp = true;
		bool debugID = true;
		bool timeZone = false;
		bool output = true;
		bool blockedSave = false;
		bool custom = false;

		std::string filePath;
		std::string startMsg;
		std::string preStartMsg;
		std::string endMsg;
		std::string postEndMsg;
		std::string totalEndMsg;
		std::string totalCustom;

		std::ios::openmode openMode = std::fstream::app | std::fstream::in | std::fstream::out;
	} DebugSettings;

	class Debug
	{
	private:
		std::string id;

		std::fstream *file;

		const DebugSettings settings;

		bool constructed;
		std::string constructError;

		bool __init();

	public:
		Debug(const std::string &_id, const pd::DebugSettings &_settings);
		~Debug();

		bool close();

		std::pair<bool, std::string> constructInfo();

		std::string log(const std::string &_type, const std::string &_msg);

		std::string getID() const;
		std::fstream *getFile() const;
		DebugSettings getSettings() const;
	};
}
#else
# 	include "../inc/macros.hpp"
# 	warn "Must use C++11 or later"
#endif // __cplusplus

