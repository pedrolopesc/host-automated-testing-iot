#include <Arduino.h>
#include "log.h"

void log_init()
{
    Serial.begin(115200);
}

void log_info(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    Serial.printf(fmt, args);
    va_end(args);
}