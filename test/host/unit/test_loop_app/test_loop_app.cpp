#include "unity.h"
#include "app/app.h"
#include "host/mocks/mock_log.h"


void setUp(void) {}

void tearDown(void) {}

void test_loop_app(void) {
    loop_app();
    TEST_ASSERT_EQUAL_STRING("Measure: 32 | 16", get_last_log());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_loop_app);
    return UNITY_END();
}