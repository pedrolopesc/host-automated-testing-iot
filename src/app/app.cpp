
#include "app.h"
#include "hal/log.h"

void setup_app() {

    log_init();

    if (!setup_ir()) {
        log_info("IR Setup failed");
        while(1);
    }

    if (!setup_imu()) {
        log_info("QMC6500 setup failed");
        while(1);
    }
}


void loop_app() {
    if (imu_has_vibration_event()) {
        log_info("Vibration event interrupt detected");
        return;
    }

    uint16_t measure = read_ir();
    int half_measure = half_value(measure);
    log_info("Measure: %d | %d", measure, half_measure);
}