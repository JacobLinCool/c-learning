#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const int DEBUG = 1;

// calculate the exponential
double calc_e(int64_t n) {
    double e = 1.0, factorial = 1.0;
    for (int64_t i = 1; i <= n; i++) {
        factorial *= i;
        e += 1.0 / factorial;
    }
    return e;
}

int main() {
    int64_t n = 0;

    printf("Please enter n: ");
    if (scanf("%" SCNd64, &n) != 1 || n < 2) {
        printf("Invalid input. Recieved %" PRId64 "\n", n);
        return 1;
    }

    double e = calc_e(n);
    printf("Answer: %.15g\n", e);

    return 0;
}