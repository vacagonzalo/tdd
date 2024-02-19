#include <limits.h>
#include "unity.h"
#include "satmath_core.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_satmath_accumulation_trivial(void)
{
    int accumulator = 0;
    int status = satmath_accumulation(&accumulator, 1);;
    TEST_ASSERT_EQUAL_INT(0, status);
    TEST_ASSERT_EQUAL_INT(1, accumulator);
}

void test_satmath_accumulation_upper_overflow(void)
{
    int accumulator = INT_MAX;
    int status = satmath_accumulation(&accumulator, 1);;
    TEST_ASSERT_EQUAL_INT(1, status);
    TEST_ASSERT_EQUAL_INT(INT_MAX, accumulator);
}

void test_satmath_accumulation_lower_overflow(void)
{
    int accumulator = INT_MIN;
    int status = satmath_accumulation(&accumulator, -1);;
    TEST_ASSERT_EQUAL_INT(-1, status);
    TEST_ASSERT_EQUAL_INT(INT_MIN, accumulator);
}
