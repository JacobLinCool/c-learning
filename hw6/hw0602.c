// Copyright (c) JacobLinCool
#include <stdio.h>
#include <inttypes.h>
#include "ext.h"

void test(int64_t a, int64_t b, int32_t expected_returning, uint32_t expected_c) {
    printf("a = %5" PRId64 ", b = %5" PRId64 " : ", a, b);

    uint32_t c = 0.0 / 0.0;
    int32_t returning = ext_euclidean(a, b, &c);

    if (returning == expected_returning && c == expected_c) {
        printf("\033[0;92m");
        printf("PASSED\n");
        printf("\033[0m");
    }
    else {
        printf("\033[0;91m");
        printf("FAILED\n");
        if (returning != expected_returning) {
            printf("returned %" PRId32 ", expected %" PRId32 "\n", returning, expected_returning);
        }
        if (c != expected_c) {
            printf("c = %" PRIu32 ", expected %" PRIu32 "\n", c, expected_c);
        }
        printf("\033[0m");
    }
}

int main() {

    test(0, 0, 0, 0);

    test(1, 0, 1, 0);

    test(0, 1, -1, 0);

    test(1, 1, 1, 0);

    test(6, 7, -1, 0);

    test(7, 6, 1, 6);

    test(6, 6, 0, 6);

    test(70, 60, 0, 10);

    test(12500, 1250, 0, 1250);

    test(1481, 114, 1, 13);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
