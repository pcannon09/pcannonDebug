#include <iostream>
#include <algorithm>
#include <string>

#ifndef __PD_NO_FULL_SUPPORT
# 	include <filesystem>

namespace fs = std::filesystem;
#endif

#include "../inc/Debug.hpp"
#include "../vendor/cpp-time-utils/inc/Time.hpp"

namespace pd
{
	// PRIVATE //
	bool Debug::__init()
	{
		if (!this->settings.filePath.empty())
		{
			this->file = new std::fstream(this->settings.filePath, this->settings.openMode);

			if (!this->file->is_open())
			{
				this->constructError = "File could not open : " + this->id;

				return false;
			}

			if (!this->file->good())
			{
				this->constructError = "File is not good for opening : " + this->id;

				return false;
			}
		}

		return true;
	}
	
	// PUBLIC //
	Debug::Debug(const std::string &_id, const pd::DebugSettings &_settings)
		: id(_id), settings(_settings)
	{
		this->constructed = this->__init();

		if (!this->constructed)
			return;
	}

	Debug::~Debug()
	{
		this->close();
	}

	std::string Debug::log(const std::string &_type, const std::string &_msg, unsigned int _level)
	{
		std::string msg;
		std::string type = _type;

		std::transform(type.begin(), type.end(), type.begin(), ::toupper);

		msg += this->settings.preStartMsg;

		if (!this->settings.custom)
		{
			msg += "[ " + this->settings.startMsg + type + (this->settings.debugID ? + " | " + this->id : "");

			// DATE AND TIME INFORMATION
			if (this->settings.timeStamp)
			{
				timeUtils::TimeInfo timeInfo;
				timeUtils::DateInfo dateInfo;
				timeUtils::Time time("debug-time");

				time.update(timeInfo);
				time.update(dateInfo);

				msg += " | " + std::to_string(dateInfo.year) + "-" + std::to_string(dateInfo.month) + "-" + std::to_string(dateInfo.day) + " | ";
				msg += std::to_string(timeInfo.hour) + ":" + std::to_string(timeInfo.min) + ":" + std::to_string(timeInfo.sec) + "." + std::to_string(timeInfo.ms)
					+ (this->settings.timeZone ? " +" + std::to_string(time.getUTCOffset().hour) + ":" + std::to_string(time.getUTCOffset().min) : "");
			}

			else msg += " ";

			// FINISG MSG
		}

		else msg = "[ " + this->settings.startMsg + this->settings.totalCustom;

		msg += this->settings.endMsg + "] " + (this->settings.postEndMsg) + _msg + this->settings.totalEndMsg + "\n";

		if (this->settings.output)
		{
			if ((!this->settings.logLevelIgnoreOutput && this->settings.logLevel == 0) || 
    				(this->settings.logLevel > 0 && _level <= this->settings.logLevel))
    		{
    			std::cout << msg;
			}
		}

		if (!this->settings.blockedSave && !this->settings.filePath.empty())
		{
			if ((!this->settings.logLevelIgnoreSave && this->settings.logLevel == 0) || 
    				(this->settings.logLevel > 0 && _level <= this->settings.logLevel))
			{
# 				ifndef __PD_NO_FULL_SUPPORT
				if (!fs::exists(fs::path(this->settings.filePath).parent_path()) && !fs::is_regular_file(this->settings.filePath))
				{
					fs::create_directories(fs::path(this->settings.filePath).parent_path());

					this->file->close(); this->file->open(this->settings.filePath, this->settings.openMode);
				}
# 				endif

				*this->file << msg;
			}
		}

		return msg;
	}

	bool Debug::close()
	{
		if (this->file)
		{
			this->file->close();

			delete this->file; this->file = nullptr;
		}

		else return false;

		return true;
	}

	std::pair<bool, std::string> Debug::constructInfo()
	{ return { this->constructed, this->constructError }; }

	std::string Debug::getID() const
	{ return this->id; }

	std::fstream *Debug::getFile() const
	{ return this->file; }

	DebugSettings Debug::getSettings() const
	{ return this->settings; }
}

