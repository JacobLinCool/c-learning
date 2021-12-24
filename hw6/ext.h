// Copyright (c) JacobLinCool
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

/**
 * @brief Extended Euclidean GCD [sa + tb = gcd(a, b)]
 *
 * @param s
 * @param t
 * @param gcd
 */
typedef struct EXT_GCD {
    int64_t s;
    int64_t t;
    int64_t gcd;
} EXT_GCD;

/**
 * @brief Extended Euclidean Algorithm
 *
 * @param a first number
 * @param b second number
 * @param c gcd(a, b) == 1 ? multiplicative inverse of b mod a : gcd(a, b)
 * @return int32_t state -  -1: a < b, 0: a and b are co-prime, 1: a and b are not co-prime
 */
int32_t ext_euclidean(uint32_t a, uint32_t b, uint32_t* c);

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
