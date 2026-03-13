#include "ir.h"
#include "Adafruit_VL53L0X.h"


Adafruit_VL53L0X lox = Adafruit_VL53L0X();

bool setup_ir() {
    static int trys = 3;
    for (int i = 0; i < trys; i++) {
        if (lox.begin()) {
            return true;
        }
        delay(20);
    }
    return false;
}

uint16_t read_ir() {
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);
    if (measure.RangeStatus != 4) {
        return measure.RangeMilliMeter;
    }
    return UINT16_MAX;
}
