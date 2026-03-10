#pragma once

#ifndef ARDUINO

#include "mock_arduino.h"
#include "hal/ir.h"

bool setupIR() { return true; };
uint16_t readIR() { return 0; };

#endif