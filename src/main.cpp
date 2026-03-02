#ifdef ARDUINO

#ifndef PIO_UNIT_TESTING

#include "filter/filter.h"
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    Serial.print("Exponetial filter (mm)"); Serial.println(exponential_filter(measure.RangeMilliMeter));
  } else {
    Serial.println(" out of range ");
  }

  delay(100);
}

#endif // PIO_UNIT_TESTING

#else // ARDUINO

#ifndef PIO_UNIT_TESTING
extern "C" int main() {
    // Função dummy para compilar HOST
    return 0;
}
#endif // PIO_UNIT_TESTING

#endif // ARDUINO