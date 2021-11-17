// Copyright (c) JacobLinCool
#include "triangle.h"

// Main Process
int main() {

    printf("Initial States: \nCheck: %d\nPerimeter: %lf\nArea: %lf\nDegree 1: %lf\nDegree 2: %lf\nDegree 3 %lf\n---\n", check(), get_perimeter(), get_area(), get_1_degree(), get_2_degree(), get_3_degree());

    set_1_point(0.0, 0.0);
    set_2_point(0.0, 3.0);
    set_3_point(4.0, 0.0);
    printf("Points Set: \nCheck: %d\nPerimeter: %lf\nArea: %lf\nDegree 1: %lf\nDegree 2: %lf\nDegree 3 %lf\n---\n", check(), get_perimeter(), get_area(), get_1_degree(), get_2_degree(), get_3_degree());

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
