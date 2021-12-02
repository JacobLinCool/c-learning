#include <stdint.h>
#include <stdio.h>

unsigned int ui = 0;
unsigned short us = 0;
signed int si = -1;

int64_t get_r1() {
    return (int64_t)((unsigned int)ui + (unsigned int)si);
}

int64_t get_r2() {
    return (int64_t)((signed int)us + (signed int)si);
}

int main() {
    int64_t r1 = ui + si;
    int64_t r2 = us + si;
    printf("%ld %ld\n", r1, r2);

    // r1 = 4294967295 (INT32_MAX * 2 + 1)
    // r2 = -1

    printf("%ld %ld\n", get_r1(), get_r2());
}
