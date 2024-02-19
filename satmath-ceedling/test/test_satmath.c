#include "unity.h"
#include "mock_satmath_core.h"
#include "satmath.h"

#include <limits.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_satmath_average_trivial(void)
{
    int average = 0;
    int numbers[] = {1, 3};
    int quantity = 2;
    int status = 0;

    satmath_accumulation_ExpectAndReturn(&average, numbers[0], 0);
    satmath_accumulation_ExpectAndReturn(&average, numbers[1], 0);

    status = satmath_average(&average, numbers, quantity);
    TEST_ASSERT_EQUAL_INT(0, status);
}

void test_satmath_average_upper_overflow(void)
{
    int average = INT_MAX - 3;
    int numbers[] = {1, 3};
    int quantity = 2;
    int status = 0;

    satmath_accumulation_ExpectAndReturn(&average, numbers[0], 0);
    satmath_accumulation_ExpectAndReturn(&average, numbers[1], 1);

    status = satmath_average(&average, numbers, quantity);
    TEST_ASSERT_EQUAL_INT(1, status);
}

void test_satmath_average_upper_overflow_short(void)
{
    int average = INT_MAX;
    int numbers[] = {1, 3};
    int quantity = 2;
    int status = 0;

    satmath_accumulation_ExpectAndReturn(&average, numbers[0], 1);

    status = satmath_average(&average, numbers, quantity);
    TEST_ASSERT_EQUAL_INT(1, status);
}

void test_satmath_average_lower_overflow(void)
{
    int average = INT_MIN + 3;
    int numbers[] = {-1, -3};
    int quantity = 2;
    int status = 0;

    satmath_accumulation_ExpectAndReturn(&average, numbers[0], 0);
    satmath_accumulation_ExpectAndReturn(&average, numbers[1], -1);

    status = satmath_average(&average, numbers, quantity);
    TEST_ASSERT_EQUAL_INT(-1, status);
}

void test_satmath_average_lower_overflow_short(void)
{
    int average = INT_MIN;
    int numbers[] = {-1, -3};
    int quantity = 2;
    int status = 0;

    satmath_accumulation_ExpectAndReturn(&average, numbers[0], -1);

    status = satmath_average(&average, numbers, quantity);
    TEST_ASSERT_EQUAL_INT(-1, status);
}
