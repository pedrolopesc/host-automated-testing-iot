#include "unity.h"
#include "app/filter/filter.h"


void setUp(void) {}

void tearDown(void) {}


void test_half_vaule(void) {
    int resp = half_value(10);
    TEST_ASSERT_EQUAL_INT(5, resp);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_half_vaule);
    return UNITY_END();
}