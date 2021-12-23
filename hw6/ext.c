// Copyright (c) JacobLinCool
#include "ext.h"

static uint32_t gcd(uint32_t a, uint32_t b) {
    if (a == 0 || b == 0) {
        return 0;
    }

    if (a == b) {
        return a;
    }
    else if (a > b) {
        return gcd(a - b, b);
    }
    else {
        return gcd(a, b - a);
    }
}

// If a < b, return -1 and c is meaningless.
// If a and b are co-prime , return 1 and c is the multiplicative inverse of b mod a.
// If a and b are not co-prime , return 0 and c is the gcd.
int32_t ext_euclidean(uint32_t a, uint32_t b, uint32_t* c) {
    if (a < b) {
        return -1;
    }

    uint32_t _gcd = gcd(a, b);

    // [invalid]
    // if(_gcd == 0) {
    //     return -1;
    // }

    if (_gcd == 1) {
        *c = 1;
        return 1;
    }
    else {
        *c = _gcd;
        return 0;
    }
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
