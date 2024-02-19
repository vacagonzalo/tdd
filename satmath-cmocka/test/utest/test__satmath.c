#include "../utils.h"
#include "../../src/satmath.c"

static void test__satmath_average__trivial(void **state)
{
  int acc = 0;
  int num[] = {0, 0, 0};
  will_return(__wrap_satmath_accumulation, 0);
  will_return(__wrap_satmath_accumulation, 0);
  will_return(__wrap_satmath_accumulation, 0);
  assert_int_equal(0, satmath_average(&acc, num, 3));
}

static void test__satmath_average__upper_overflow(void **state)
{
  int acc = INT_MAX - 3;
  int num[] = {1, 1, 2};
  will_return(__wrap_satmath_accumulation, 0);
  will_return(__wrap_satmath_accumulation, 0);
  will_return(__wrap_satmath_accumulation, 1);
  assert_int_equal(1, satmath_average(&acc, num, 3));
  assert_int_equal(0, acc);
}

static void test__satmath_average__lower_overflow(void **state)
{
  int acc = INT_MIN + 3;
  int num[] = {-1, -1, -2};
  will_return(__wrap_satmath_accumulation, 0);
  will_return(__wrap_satmath_accumulation, 0);
  will_return(__wrap_satmath_accumulation, -1);
  assert_int_equal(-1, satmath_average(&acc, num, 3));
  assert_int_equal(0, acc);
}

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test__satmath_average__trivial),
      cmocka_unit_test(test__satmath_average__upper_overflow),
      cmocka_unit_test(test__satmath_average__lower_overflow),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
