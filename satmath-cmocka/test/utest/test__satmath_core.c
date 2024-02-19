#include "../utils.h"
#include "../../src/satmath_core.c"

static void test__satmath_accumulation__trivial(void **state)
{
  int acc = 0;
  assert_int_equal(0, satmath_accumulation(&acc, 1));
  assert_int_equal(1, acc);
}

static void test__satmath_accumulation__upper_saturation(void **state)
{
  int acc = INT_MAX;
  assert_int_equal(1, satmath_accumulation(&acc, 1));
  assert_int_equal(INT_MAX, acc);
}

static void test__satmath_accumulation__lower_saturation(void **state)
{
  int acc = INT_MIN;
  assert_int_equal(-1, satmath_accumulation(&acc, -1));
  assert_int_equal(INT_MIN, acc);
}

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test__satmath_accumulation__trivial),
      cmocka_unit_test(test__satmath_accumulation__upper_saturation),
      cmocka_unit_test(test__satmath_accumulation__lower_saturation),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
