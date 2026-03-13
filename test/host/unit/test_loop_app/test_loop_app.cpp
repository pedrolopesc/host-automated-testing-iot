#include "unity.h"
#include "app/app.h"
#include "host/mocks/mock_log.h"
#include "host/mocks/mock_ir.h"


void setUp(void) {
    set_mock_read_ir_output(10);
}

void tearDown(void) {}

void test_loop_app(void) {
    loop_app();
    TEST_ASSERT_EQUAL_STRING("Measure: 10 | 5", get_last_log());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_loop_app);
    return UNITY_END();
}