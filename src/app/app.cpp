
#include "app.h"
#include "hal/log.h"

void setup_app() {

    log_init();

    if (!setup_ir()) {
        log_info("IR Setup failed");
        while(1);
    };
}


void loop_app() {
    uint16_t measure = read_ir();
    int half_measure = half_value(measure);
    log_info("Measure: %d | %d", measure, half_measure);
}