#include "satmath.h"
#include "satmath_core.h"

int satmath_average(int *average, int *numbers, int quantity)
{
    int sta = 0;
    *average = 0;
    for (int i = 0; (i < quantity) && (sta == 0); ++i)
        sta = satmath_accumulation(average, numbers[i]);
    *average = (sta == 0) ? (*average / quantity) : 0;
    return sta;
}
