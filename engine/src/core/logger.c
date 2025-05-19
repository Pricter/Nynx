#include "logger.h"

// TODO: Temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <core/asserts.h>
#include <platform/platform.h>

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line) {
    log_output(LOG_LEVEL_FATAL, "Assertion failed: %s, message: '%s', in file: %s, line: %d", expression, message, file, line);
}

b8 initialize_logging(void) {
    // TODO: create a log file and set up logging
    return true;
}

void shutdown_logging(void) {
    // TODO: close the log file and clean up logging resources and queued entries
}

void log_output(log_level level, const char* message, ...) {
    const char* level_strings[6] = {"[TRACE]: ", "[DEBUG]: ", "[INFO]:  ", "[WARN]:  ", "[ERROR]: ", "[FATAL]: "};
    // b8 is_error = level == LOG_LEVEL_ERROR || level == LOG_LEVEL_FATAL;

    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, sizeof(out_message), message, arg_ptr);
    va_end(arg_ptr);

    char out_message2[32000];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    platform_console_write(out_message2, level);
}