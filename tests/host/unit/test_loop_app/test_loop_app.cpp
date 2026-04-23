#include "unity.h"
#include "app/app.h"
#include "host/mocks/mock_log.h"
#include "host/mocks/mock_ir.h"
#include "host/mocks/mock_imu.h"

void setUp(void) {}

void tearDown(void) {}

void test_loop_app_logs_measure_when_no_vibration_event(void) {
    set_mock_read_ir_output(10);
    set_mock_imu_event(false);

    loop_app();

    TEST_ASSERT_EQUAL_STRING("Measure: 10 | 5", get_last_log());
}

void test_loop_app_logs_vibration_interrupt_when_event_is_raised(void) {
    set_mock_read_ir_output(10);
    set_mock_imu_event(true);

    loop_app();

    TEST_ASSERT_EQUAL_STRING("Vibration event interrupt detected", get_last_log());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_loop_app_logs_measure_when_no_vibration_event);
    RUN_TEST(test_loop_app_logs_vibration_interrupt_when_event_is_raised);
    return UNITY_END();
}
