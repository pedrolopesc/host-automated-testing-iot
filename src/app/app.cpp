
#include "app.h"
#include "hal/log.h"

void setup_app() {

    log_init();

    if (!setupIR()) {
        log_info("IR Setup failed");
        while(1);
    };
}


void loop_app() {
    uint16_t measure = readIR();
    log_info("Measure: %d", measure);
}