// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct Polynomial {
    int64_t degree;
    int64_t* coefficients;
} Polynomial;

Polynomial create_polynomial(int64_t degree);

int8_t set_term(Polynomial* polynomial, int64_t exponent, int64_t coefficient);

Polynomial add(Polynomial* polynomial_1, Polynomial* polynomial_2);

Polynomial sub(Polynomial* polynomial_1, Polynomial* polynomial_2);

Polynomial multiply(Polynomial* polynomial_1, Polynomial* polynomial_2);

void print_polynomial(Polynomial* polynomial);

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
