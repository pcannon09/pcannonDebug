#pragma  once

#if __cplusplus >= 201103L
#if __cplusplus < 201703L
# 	ifdef __PD_NO_FULL_SUPPORT
# 		undef __PD_NO_FULL_SUPPORT
# 	endif
# 	define __PD_NO_FULL_SUPPORT
# 	warning "No full support for the current C++ standard (Full Support is in C++17)"
#endif // __cplusplus < 201703L

#include <string>
#include <fstream>
#include <utility>

namespace pd
{
	/**
	 * @brief Set debug settings struct with set values, default are already set for the best output
	 */
	typedef struct DebugSettings
	{
		bool timeStamp = true;
		bool debugID = true;
		bool timeZone = false;
		bool output = true;
		bool blockedSave = false;
		bool custom = false;
		bool logLevelIgnoreOutput = false;
		bool logLevelIgnoreSave = false;

		unsigned int logLevel = 0;

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

		/**
		 * @brief Initialize the Debug object that is going (or was) to be constructed
		 * @return bool Did it fail? True = Success, False = Failiture
		 */
		bool __init();

	public:
		/**
		 * @brief Construct the debugger with specified ID and settings
		 * Call the inner `__init()` function to Initialize
		 * @param _id Set the ID of this object
		 * @param _settings Set the settings of this object
		 */
		Debug(const std::string &_id, const pd::DebugSettings &_settings);

		/**
		 * @brief Call the `pd::Debug::close()` function to free all allocated memory
		 */
		~Debug();

		/**
		 * @brief Free all the allocated memory and resources, return true if it succeeded, return false if it did not
		 * @return bool True if success, false if failiture
		 */
		bool close();

		/**
		 * @brief Construct debug information
		 * You can use it if it failed to construct properly to get the error message
		 * @return std::pair<bool, std::string> .first: Did it succeed? .second: Error reason
		 */
		std::pair<bool, std::string> constructInfo();

		/**
		 * @brief Log the message with specific custom type, message and log level
		 * @param _type Set the type of the debug message (Ex: Information, Success, Warning, Error, ...)
		 * @param _msg Set the message for debugging
		 * @param _level Set the debug level level of the log (default as 0, non-debug-level specific)
		 * @return The total string of the total debug message
		 */
		std::string log(const std::string &_type, const std::string &_msg, unsigned int _level = 0);

		/**
		 * @brief Return the ID of the created Debug object
		 * @return std::string The ID of this object
		 */
		std::string getID() const;

		/**
		 * @brief Get file for more control over the processing and for more actions
		 * @return std::fstream Allocated file to Debug object
		 */
		std::fstream *getFile() const;

		/**
		 * @brief Get the settings set for the created Debug object
		 * @return pd::DebugSettings Debug settings to return
		 */
		DebugSettings getSettings() const;
	};
}
#else
# 	include "../inc/macros.hpp"
# 	warn "Must use C++11 or later"
#endif // __cplusplus >= 201103L

