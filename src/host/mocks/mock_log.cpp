#include <stdio.h>
#include <stdarg.h>
#include "hal/log.h"
#include "mock_log.h"

static char last_log[128];

void log_init() {}

void log_info(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsnprintf(last_log, sizeof(last_log), fmt, args);
    va_end(args);
}

const char* get_last_log()
{
    return last_log;
}