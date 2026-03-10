#include "hal/ir.h"

#ifdef ARDUINO

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

bool setupIR() {
    static int trys = 3;
    for (int i = 0; i < trys; i++) {
        if (lox.begin()) {
            return true;
        }
        delay(20);
    }
    return false;
}

uint16_t readIR() {
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);
    if (measure.RangeStatus != 4) {
        return measure.RangeMilliMeter;
    }
    return UINT16_MAX;
}

#endif