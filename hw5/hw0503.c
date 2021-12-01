// Copyright (c) JacobLinCool
#include <stdio.h>
#include <inttypes.h>
#include "polynomial.h"

int main() {
    int64_t degree_1 = -1, degree_2 = -1;

    printf("Please enter p1 degree: ");
    scanf("%" SCNd64, &degree_1);

    Polynomial p1 = create_polynomial(degree_1);

    printf("Please enter p1 coefficients: ");
    for (int64_t i = degree_1; i >= 0; i--) {
        int64_t coefficient;
        scanf("%" SCNd64, &coefficient);
        p1.coefficients[i] = coefficient;
    }

    printf("Please enter p2 degree: ");
    scanf("%" SCNd64, &degree_2);

    Polynomial p2 = create_polynomial(degree_2);

    printf("Please enter p2 coefficients: ");
    for (int64_t i = degree_2; i >= 0; i--) {
        int64_t coefficient;
        scanf("%" SCNd64, &coefficient);
        p2.coefficients[i] = coefficient;
    }

    printf("p1: ");
    print_polynomial(&p1);
    printf("\n");

    printf("p2: ");
    print_polynomial(&p2);
    printf("\n");

    printf("p1 + p2: ");
    Polynomial sum = add(&p1, &p2);
    print_polynomial(&sum);
    printf("\n");

    printf("p1 - p2: ");
    Polynomial dif = sub(&p1, &p2);
    print_polynomial(&dif);
    printf("\n");

    printf("p1 * p2: ");
    Polynomial mul = multiply(&p1, &p2);
    print_polynomial(&mul);
    printf("\n");

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
