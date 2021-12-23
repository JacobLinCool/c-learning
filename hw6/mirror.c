// Copyright (c) JacobLinCool
#include "mirror.h"

static Line line = { 0.0 / 0.0, 0.0 / 0.0 };

void set_line(double x1, double y1, double x2, double y2) {
    if (x1 == x2 && y1 == y2) {
        return;
    }
    else {
        line.m = (y2 - y1) / (x2 - x1);
        line.y_intercept = y1 - line.m * x1;
    }

    return;
}

int32_t get_mirror(double a, double b, double* c, double* d) {
    if (line.m != line.m || line.y_intercept != line.y_intercept) {
        return -1;
    }
    else {
        double t = (a + (b - line.y_intercept) * line.m) / (1 + line.m * line.m);
        *c = 2 * t - a;
        *d = 2 * t * line.m - b + 2 * line.y_intercept;
        return 0;
    }
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
