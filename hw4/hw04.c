#include "hw04.h"

// hw0401
int64_t print_K(int64_t n) {
    for (int64_t i = 0; i < n; i++) {
        int64_t len = (n / 2) - (i > (n - i - 1) ? (n - i - 1) : i);

        for (int64_t j = 0; j <= len; j++) {
            if (j == 0 || j == len) printf("*");
            else printf(" ");
        }

        printf("\n");
    }

    return 1;
}

// hw0402
int64_t hanoi_recursive(int64_t n, int64_t from, int64_t to, int64_t temp, int64_t now) {
    if (n == 1) {
        printf("move disk %" PRId64 " to rod %" PRId64 "\n", now, to);
        return 1;
    }

    hanoi_recursive(n - 1, from, temp, to, now - 1);
    printf("move disk %" PRId64 " to rod %" PRId64 "\n", now, to);
    hanoi_recursive(n - 1, temp, to, from, now - 1);

    return 1;
}

int64_t hanoi_iterative(int64_t n) {

}

// hw0403

// hw0404
