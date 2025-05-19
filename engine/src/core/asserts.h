#pragma once

#include "defines.h"

// Disable by commenting the below line
#define NASSERTIONS_ENABLED

#ifdef NASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

NAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define NASSERT(expr) \
    { \
        if (expr) { \
        } else { \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak(); \
        } \
    }

#define NASSERT_MSG(expr, msg) \
    { \
        if (expr) { \
        } else { \
            report_assertion_failure(#expr, msg, __FILE__, __LINE__); \
            debugBreak(); \
        } \
    }

#ifdef _DEBUG
#define NASSERT_DEBUG(expr) \
    { \
        if (expr) { \
        } else { \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak(); \
        } \
    }
#else
#define NASSERT_DEBUG(expr) // Do nothing in release builds
#endif

#else
#define NASSERT(expr) // Do nothing in release builds
#define NASSERT_MSG(expr, msg) // Do nothing in release builds
#define NASSERT_DEBUG(expr) // Do nothing in release builds
#endif