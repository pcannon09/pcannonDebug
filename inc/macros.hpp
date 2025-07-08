#pragma once

// Versioning
#define PD_VERSION_MAJOR          1
#define PD_VERSION_MINOR          0
#define PD_VERSION_PATCH          0

// Version states:
// dev - Develoment
// build - Built Version
#define PD_VERSION_STATE          "build"

#define PD_VERSION                ((PD_VERSION_MAJOR<<16)|(STT_VERSION_MINOR<<8)|(STT_VERSION_PATCH)|(STT_VERSION_STATE << 24))

#define PD_VERSION_CHECK(PD_VERSION_MAJOR, PD_VERSION_MINOR, PD_VERSION_PATCH, PD_VERSION_STATE) \
    ((PD_VERSION_MAJOR<<16)|(PD_VERSION_MINOR<<8)|(PD_VERSION_PATCH)|(STT_VERSION_STATE << 24))

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

// Define _PD_DEBUG_BREAK() macro
#if defined(_MSC_VER)
#   include <intrin.h>
#   define _PD_DEBUG_BREAK() __debugbreak()
#elif defined(__clang__) || defined(__GNUC__)
#   if defined(__has_builtin)
#       define _PD_DEBUG_BREAK() __builtin_debugtrap()
#   elif __has_builtin(__builtin_debugtrap)
#       define _PD_DEBUG_BREAK() __builtin_trap()
#   else
#       include <signal.h>
#       define _PD_DEBUG_BREAK() raise(SIGTRAP)
#   endif // defined(__has_builtin)
#else 
#   include <signal.h>
#   define _PD_DEBUG_BREAK() raise(SIGTRAP)
#endif // defined(_MSC_VER)

#ifndef PD_GLOBAL_DEBUG
#   warning "Must set `PD_GLOBAL_DEBUG` to `true` if debugging with breakpoint traps"
#   define PD_GLOBAL_DEBUG true
#endif // !defined(PD_GLOBAL_DEBUG)

// Define PD_DEBUG_BREAK() macro
#if PD_GLOBAL_DEBUG // Debug in projects are enabled
#   define PD_DEBUG_BREAK(_msg) \
        std::cout << "[ BUILTIN DEBUG BREAK <" __FILE__ << ":" << std::to_string(__LINE__) << "> ] " << _msg << "\n"; \
        _PD_DEBUG_BREAK();
#else // Debug in projects are disabled
#   define PD_DEBUG_BREAK(_msg)
#endif // PD_GLOBAL_DEBUG == true

// Macro utils
#define PD_STRINGIFY(x) #x
#define PD_TOSTRING(x) PD_STRINGIFY(x)

#ifndef PD_DEV
#	define PD_DEV true
#endif // PD_DEV

