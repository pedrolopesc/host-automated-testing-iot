
#include "app/app.h"

void setup_app() {
    Serial.begin(115200);

    while (!Serial) {
        delay(1);
    }

    if (!setupIR()) {
        Serial.println("IR Setup failed");
        while(1);
    };
}


void loop_app() {

    Serial.print("Reading a measurement... ");
    uint16_t measure = readIR();
    Serial.println(measure);
    delay(100);
}