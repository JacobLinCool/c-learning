// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const int DEBUG = 0;

// calculate the exponential, from bottom to top
long double calc_e(int64_t n) {
    long double e = 1 + 1 / (1 + 1 / (2 * n));
    for (int64_t i = 2 * (n - 1); i >= 2; i -= 2) e = 1 + 1 / (1 + 1 / (i + 1 / e));
    e += 1;
    return e;
}

void line() {
    printf("----------------------------------\n");
}

int main() {

    line();
    printf("|   \033[1;94mExperiment of Exponential\033[m    |\n");
    line();

    long double last = 0, nearest_dist = 100;
    int64_t nearest = 0;
    for (int64_t n = 2; n <= 1e9; n++) {
        long double e = calc_e(n);
        long double dist = e - 2.7182818284590452354L > 0 ? e - 2.7182818284590452354L : 2.7182818284590452354L - e;
        printf("| n = \033[93m%2ld\033[m | %.19Lf |\n", n, e);
        printf("|   DIFF | \033[9%dm%.19Lf\033[m |\n", 1 + (e - 2.7182818284590452354L > 0), dist);
        line();
        if (e == last) break;
        last = e;
        if (dist < nearest_dist) {
            nearest_dist = dist;
            nearest = n;
        }
    }

    printf("|       >> \033[1;94mNearest N: %ld\033[m <<       |\n", nearest);
    line();

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
