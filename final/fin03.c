// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "frac.h"

void test(a, b, c, d) {
    int32_t x, y;
    int32_t add = frac_add(&x, &y, a, b, c, d);

    if (add == 0) {
        printf("%" PRId32 "/%" PRId32 " + %" PRId32 "/%" PRId32 " = %" PRId32 "/%" PRId32 "\n", a, b, c, d, x, y);
    }
    else {
        printf("%" PRId32 "/%" PRId32 " + %" PRId32 "/%" PRId32 " = ERROR\n", a, b, c, d);
    }

    int32_t del = frac_del(&x, &y, a, b, c, d);

    if (del == 0) {
        printf("%" PRId32 "/%" PRId32 " - %" PRId32 "/%" PRId32 " = %" PRId32 "/%" PRId32 "\n", a, b, c, d, x, y);
    }
    else {
        printf("%" PRId32 "/%" PRId32 " - %" PRId32 "/%" PRId32 " = ERROR\n", a, b, c, d);
    }

    int32_t mul = frac_mul(&x, &y, a, b, c, d);

    if (mul == 0) {
        printf("%" PRId32 "/%" PRId32 " * %" PRId32 "/%" PRId32 " = %" PRId32 "/%" PRId32 "\n", a, b, c, d, x, y);
    }
    else {
        printf("%" PRId32 "/%" PRId32 " * %" PRId32 "/%" PRId32 " = ERROR\n", a, b, c, d);
    }

    int32_t div = frac_div(&x, &y, a, b, c, d);

    if (div == 0) {
        printf("%" PRId32 "/%" PRId32 " / %" PRId32 "/%" PRId32 " = %" PRId32 "/%" PRId32 "\n", a, b, c, d, x, y);
    }
    else {
        printf("%" PRId32 "/%" PRId32 " / %" PRId32 "/%" PRId32 " = ERROR\n", a, b, c, d);
    }

    printf("\n");
}

int main() {
    test(0, 0, 0, 0);
    test(0, 2, 3, 6);
    test(3, 2, 0, 6);
    test(3, 0, 2, 6);
    test(3, 6, 2, 0);

    test(1, 1, 1, 1);
    test(1, 2, 1, 3);
    test(-1, 2, 1, 3);
    test(1, 2, -1, 3);
    test(-1, 2, -1, 3);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
