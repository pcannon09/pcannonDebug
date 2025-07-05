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

// Macro utils
#define PD_STRINGIFY(x) #x
#define PD_TOSTRING(x) STT_STRINGIFY(x)

#ifndef PD_DEV
#	define PD_DEV true
#endif

