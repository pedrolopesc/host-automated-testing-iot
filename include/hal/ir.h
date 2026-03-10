#pragma once

#ifndef ARDUINO
#include "mock_ir.h"
#else
#include "Adafruit_VL53L0X.h"

bool setupIR();
uint16_t readIR();

#endif