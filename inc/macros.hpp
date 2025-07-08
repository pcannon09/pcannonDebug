#pragma once

// Versioning
#define PD_VERSION_MAJOR          0
#define PD_VERSION_MINOR          0
#define PD_VERSION_PATCH          1

// Version states:
// dev - Develoment
// build - Built Version
#define PD_VERSION_STATE          "dev"

#define PD_VERSION                ((STT_VERSION_MAJOR<<16)|(STT_VERSION_MINOR<<8)|(STT_VERSION_PATCH)|(STT_VERSION_STATE << 24))

#define PD_VERSION_CHECK(STT_VERSION_MAJOR, STT_VERSION_MINOR, STT_VERSION_PATCH, STT_VERSION_STATE) \
    ((PD_VERSION_MAJOR<<16)|(STT_VERSION_MINOR<<8)|(STT_VERSION_PATCH)|(STT_VERSION_STATE << 24))

/**
 * @brief Debug log with file and line output capabilities using pd::Debug for debugging
 * Output it to the standard output
 * @param _logger Set the logger for pd::Debug capabilities
 * @param _type Set the type of the log (Ex: Information, Warning, Successs, Error, ...)
 * @param _msg Set the message to log
 */
#define PD_DEBUGLOG(_logger, _type, _msg) \
    _logger.log(_type, std::string(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " " + _msg), 0)

/**
 * @brief Simple debug log with file and line output capabilities with fully custom message without any setting needed
 * Output it to the standard output
 * @param _type Set the type of the log (Ex: Information, Warning, Successs, Error, ...)
 * @param _msg Set the message to log
 */
#define PD_SIMPLE_DEBUGLOG(_type, _msg) \
    std::cout << _type << " [" << std::string(std::string(__FILE__) + ":" + std::to_string(__LINE__)) << "] " << _msg << "\n";

// Macro utils
#define PD_STRINGIFY(x) #x
#define PD_TOSTRING(x) STT_STRINGIFY(x)

#ifndef PD_DEV
#	define PD_DEV true
#endif

