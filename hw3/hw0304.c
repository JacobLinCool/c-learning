// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const int DEBUG = 0;

// calculate the exponential, from bottom to top
long double calc_e(int64_t n) {
    long double e = 1 + 1 / (1 + 1 / (2 * (long double)n));
    for (int64_t i = 2 * (n - 1); i >= 2; i -= 2) e = 1 + 1 / (1 + 1 / ((long double)i + 1 / e));
    e += 1;
    return e;
}

int main() {
    int64_t n = 0;

    printf("Please enter n: ");
    if (scanf("%" SCNd64, &n) != 1 || n < 2) {
        printf("Invalid input. Recieved %" PRId64 "\n", n);
        return 1;
    }

    if (n > 100) n = 100;
    long double e = calc_e(n);
    printf("Answer: %.19Lf\n", e);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
