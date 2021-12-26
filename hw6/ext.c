// Copyright (c) JacobLinCool
#include "ext.h"

static void swap(int64_t* a, int64_t* b) {
    int64_t tmp = *a;
    *a = *b;
    *b = tmp;
}

static EXT_GCD extended_euclidean(int64_t a, int64_t b) {
    if (a < b) {
        swap(&a, &b);
    }

    EXT_GCD ext_gcd;

    if (b == 0) {
        ext_gcd.s = 1;
        ext_gcd.t = 0;
        ext_gcd.gcd = a;
    }
    else {
        EXT_GCD ext_gcd_b = extended_euclidean(b, a % b);
        ext_gcd.s = ext_gcd_b.t;
        ext_gcd.t = ext_gcd_b.s - (a / b) * ext_gcd_b.t;
        ext_gcd.gcd = ext_gcd_b.gcd;
    }

    return ext_gcd;
}

int32_t ext_euclidean(uint32_t a, uint32_t b, uint32_t* c) {
    if (a < b || b == 0) {
        *c = 0;
        return -1;
    }

    EXT_GCD ext_gcd = extended_euclidean(a, b);

    if (ext_gcd.gcd == 1LL) {
        *c = (ext_gcd.t + a) % a;
        return 1;
    }
    else {
        *c = ext_gcd.gcd;
        return 0;
    }
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
