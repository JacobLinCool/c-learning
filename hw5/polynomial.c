// Copyright (c) JacobLinCool
#include "polynomial.h"

Polynomial create_polynomial(int64_t degree) {
    Polynomial p;

    p.degree = degree;
    p.coefficients = malloc(sizeof(int64_t) * (degree + 1));

    for (int64_t i = 0; i <= degree; i++) {
        p.coefficients[i] = 0;
    }

    return p;
}

// return 1 if success, 0 if fail
int8_t set_term(Polynomial* polynomial, int64_t exponent, int64_t coefficient) {
    if (polynomial == NULL) {
        return 0;
    }

    if (exponent > polynomial->degree) {
        return 0;
    }

    polynomial->coefficients[exponent] = coefficient;

    return 1;
}

Polynomial add(Polynomial* polynomial_1, Polynomial* polynomial_2) {
    int64_t degree = polynomial_1->degree > polynomial_2->degree ? polynomial_1->degree : polynomial_2->degree;

    Polynomial polynomial = create_polynomial(degree);

    for (int64_t i = 0; i <= degree; i++) {
        int64_t coefficient = 0;

        if (i <= polynomial_1->degree) {
            coefficient += polynomial_1->coefficients[i];
        }

        if (i <= polynomial_2->degree) {
            coefficient += polynomial_2->coefficients[i];
        }

        set_term(&polynomial, i, coefficient);
    }

    return polynomial;
}

Polynomial sub(Polynomial* polynomial_1, Polynomial* polynomial_2) {

    int64_t degree = polynomial_1->degree > polynomial_2->degree ? polynomial_1->degree : polynomial_2->degree;

    Polynomial polynomial = create_polynomial(degree);

    for (int64_t i = 0; i <= degree; i++) {

        int64_t coefficient = 0;

        if (i <= polynomial_1->degree) {
            coefficient += polynomial_1->coefficients[i];
        }

        if (i <= polynomial_2->degree) {
            coefficient -= polynomial_2->coefficients[i];
        }

        set_term(&polynomial, i, coefficient);
    }

    return polynomial;
}

Polynomial multiply(Polynomial* polynomial_1, Polynomial* polynomial_2) {

    int64_t degree = polynomial_1->degree + polynomial_2->degree;

    Polynomial polynomial = create_polynomial(degree);

    for (int64_t i = 0; i <= polynomial_1->degree; i++) {
        for (int64_t j = 0; j <= polynomial_2->degree; j++) {
            int64_t exponent = i + j;

            int64_t coefficient = polynomial_1->coefficients[i] * polynomial_2->coefficients[j];

            polynomial.coefficients[exponent] += coefficient;
        }
    }

    return polynomial;
}

void print_polynomial(Polynomial* polynomial) {
    int8_t printed = 0;

    for (int64_t i = polynomial->degree; i >= 0; i--) {
        if (polynomial->coefficients[i] == 0) {
            continue;
        }

        if (printed) {
            if (polynomial->coefficients[i] > 0) {
                printf(" + ");
            }
            else {
                printf(" - ");
            }
        }

        printf("%" PRId64, printed == 0 || polynomial->coefficients[i] > 0 ? polynomial->coefficients[i] : -polynomial->coefficients[i]);

        if (i > 0) {
            printf("x");
        }

        if (i > 1) {
            printf("^%" PRId64, i);
        }

        printed = 1;
    }

    if (!printed) {
        printf("0");
    }

    return;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
