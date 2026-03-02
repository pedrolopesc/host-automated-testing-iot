#include "unity.h"
#include "filter/filter.h"


void setUp(void) {}

void tearDown(void) {}


void test_half_vaule(void) {
    int resp = half_value(10);
    TEST_ASSERT_TRUE(resp)
}



int main(void) {
    UNITY_BEGIN();

    return UNITY_END();
}