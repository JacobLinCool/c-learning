// Copyright (c) JacobLinCool
#include <stdio.h>
#include <inttypes.h>
#include "data.h"

int main() {
    int32_t numbers[4] = { 5,6,12,9 };

    printf("Mean: %f\n", get_mean(numbers, 4));
    printf("Median: %f\n", get_median(numbers, 4));
    printf("Mode: %" PRId32 "\n", get_mode(numbers, 4));
    printf("Standard Deviation: %f\n", get_stddev(numbers, 4));

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
