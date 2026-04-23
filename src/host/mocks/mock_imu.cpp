#include "driver/imu.h"

static bool mock_setup_imu_output = true;
static bool mock_imu_event = false;

void set_mock_setup_imu_output(bool output) {
    mock_setup_imu_output = output;
}

void set_mock_imu_event(bool event_raised) {
    mock_imu_event = event_raised;
}

bool setup_imu() {
    return mock_setup_imu_output;
}

bool imu_has_vibration_event() {
    bool has_event = mock_imu_event;
    mock_imu_event = false;
    return has_event;
}
