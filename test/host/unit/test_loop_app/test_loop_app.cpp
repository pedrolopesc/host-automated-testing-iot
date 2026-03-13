#include "unity.h"
#include "app/app.h"
#include "host/mocks/mock_log.h"
#include "host/mocks/mock_ir.h"


void setUp(void) {}

void tearDown(void) {}

void test_loop_app(void) {
    uint16_t read_value = 10;
    const char* expected = "Measure: 10 | 5";
    set_mock_read_ir_output(read_value);

    loop_app();

    TEST_ASSERT_EQUAL_STRING(expected, get_last_log());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_loop_app);
    return UNITY_END();
}
