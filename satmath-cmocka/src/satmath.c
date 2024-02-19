#include "satmath.h"

int satmath_average(int *average, int *numbers, int quantity)
{
    int sta = 0;
    int acc = 0;
    for (int i = 0; (i < quantity) && (sta == 0); ++i)
        sta = satmath_accumulation(&acc, numbers[i]);
    *average = (sta == 0) ? (acc / quantity) : 0;
    return sta;
}
