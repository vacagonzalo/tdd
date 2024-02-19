#include "satmath_core.h"

int satmath_accumulation(int *accumulator, int number)
{
  int addition = *accumulator + number;
  if ((*accumulator > 0) && (number > 0) && (addition < 0))
  {
    *accumulator = 0x7fffffff;
    return 1;
  }
  else if ((*accumulator < 0) && (number < 0) && (addition > 0))
  {
    *accumulator = 0x80000000;
    return -1;
  }
  else
  {
    *accumulator = addition;
    return 0;
  }
}
