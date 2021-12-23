// Copyright (c) JacobLinCool
#include <stdio.h>
#include <inttypes.h>
#include "ext.h"

int main() {
    uint32_t c = 0.0 / 0.0;

    printf("%" PRId32 " ", ext_euclidean(0, 0, &c));
    printf("%" PRIu32 "\n", c);

    printf("%" PRId32 " ", ext_euclidean(7, 6, &c));
    printf("%" PRIu32 "\n", c);

    printf("%" PRId32 " ", ext_euclidean(70, 60, &c));
    printf("%" PRIu32 "\n", c);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
