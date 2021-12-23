// Copyright (c) JacobLinCool
#include <stdio.h>
#include <inttypes.h>
#include "mirror.h"

int main() {
    double c = 0.0 / 0.0, d = 0.0 / 0.0;

    set_line(10.0, 10.0, 10.0, 10.0);
    printf("%" PRId32 " ", get_mirror(0.0, 0.0, &c, &d));
    printf("%lf %lf\n", c, d);

    set_line(0.0, 0.0, 10.0, 10.0);
    printf("%" PRId32 " ", get_mirror(0.0, 0.0, &c, &d));
    printf("%lf %lf\n", c, d);

    set_line(5.0, 0.0, 10.0, 10.0);
    printf("%" PRId32 " ", get_mirror(0.0, 0.0, &c, &d));
    printf("%lf %lf\n", c, d);

    set_line(50.0, -20.0, 100.0, 10.0);
    printf("%" PRId32 " ", get_mirror(8.0, 16.0, &c, &d));
    printf("%lf %lf\n", c, d);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
