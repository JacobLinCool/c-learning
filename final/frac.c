// Copyright (c) JacobLinCool
#include "frac.h"

static int32_t gcd(int32_t a, int32_t b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

static int32_t lcm(int32_t a, int32_t b) {
    return a * b / gcd(a, b);
}

static void reduction(int32_t a, int32_t b, int32_t* c, int32_t* d) {
    int32_t g = abs(gcd(a, b));
    *c = a / g;
    *d = b / g;

    return;
}

static void nomalize_output(int32_t* x, int32_t* y) {
    if (*x == 0) {
        *y = 1;
    }
    if (*y < 0) {
        *x = -*x;
        *y = -*y;
    }

    reduction(*x, *y, x, y);

    return;
}

int32_t frac_add(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d) {
    if (b == 0 || d == 0) {
        return -1;
    }

    reduction(a, b, &a, &b);
    reduction(c, d, &c, &d);

    *y = lcm(b, d);
    *x = a * (*y / b) + c * (*y / d);

    nomalize_output(x, y);

    return 0;
}

int32_t frac_del(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d) {
    return frac_add(x, y, a, b, -c, d);
}

int32_t frac_mul(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d) {
    if (b == 0 || d == 0) {
        return -1;
    }

    reduction(a, b, &a, &b);
    reduction(c, d, &c, &d);

    *y = b * d;
    *x = (a * d) * (c * b);

    nomalize_output(x, y);

    return 0;
}

int32_t frac_div(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d) {
    if (d == 0) {
        return -1;
    }

    return frac_mul(x, y, a, b, d, c);
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
