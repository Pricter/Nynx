#pragma once

#include <defines.h>

// Define LOG LEVEL to control logging output
#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Define NRELEASE to 1 for release build, 0 for debug build
#if NRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
    LOG_LEVEL_TRACE = 0,
    LOG_LEVEL_DEBUG = 1,
    LOG_LEVEL_INFO = 2,
    LOG_LEVEL_WARN = 3,
    LOG_LEVEL_ERROR = 4,
    LOG_LEVEL_FATAL = 5
} log_level;

// Initialize the logger
b8 initialize_logging(void);

// Shutdown the logger
void shutdown_logging(void);

// Log the message with the specified log level
NAPI void log_output(log_level level, const char* message, ...);

// Logs fatal message
#define NFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__)

#ifndef NERROR
// Logs error message
#define NERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__)
#endif

#if LOG_WARN_ENABLED == 1
// Logs warning message
#define NWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__)
#else
// Suppresses warning message
#define NWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// Logs info message
#define NINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__)
#else
// Suppresses info message
#define NINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs debug message
#define NDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
// Suppresses debug message
#define NDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs trace message
#define NTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
// Suppresses trace message
#define NTRACE(message, ...)
#endif