// Copyright (c) JacobLinCool
#include "triangle.h"

static Point p1 = { x: 0.0 / 0.0, y : 0.0 / 0.0 };
static Point p2 = { x: 0.0 / 0.0, y : 0.0 / 0.0 };
static Point p3 = { x: 0.0 / 0.0, y : 0.0 / 0.0 };

// static Triangle triangle = { p1: &p1, p2 : &p2, p3 : &p3 };

int set_1_point(double x, double y) {
    p1.x = x;
    p1.y = y;
    return 1;
}
int set_2_point(double x, double y) {
    p2.x = x;
    p2.y = y;
    return 1;
}
int set_3_point(double x, double y) {
    p3.x = x;
    p3.y = y;
    return 1;
}

int check(void) {
    // Check if all points are set
    if (p1.x != p1.x || p1.y != p1.y) {
        return 0;
    }
    if (p2.x != p2.x || p2.y != p2.y) {
        return 0;
    }
    if (p3.x != p3.x || p3.y != p3.y) {
        return 0;
    }

    // Check if all points are not the same
    if (p1.x == p2.x && p1.y == p2.y) {
        return 0;
    }
    if (p1.x == p3.x && p1.y == p3.y) {
        return 0;
    }
    if (p2.x == p3.x && p2.y == p3.y) {
        return 0;
    }

    // Check if all points are not on the same line
    if ((p1.x - p2.x) / (p1.y - p2.y) == (p1.x - p3.x) / (p1.y - p3.y)) {
        return 0;
    }

    return 1;
}

double get_perimeter(void) {
    if (!check()) return -1.0;

    double a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double b = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    double c = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));

    return a + b + c;
}

double get_area(void) {
    if (!check()) return -1.0;

    double a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double b = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    double c = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));

    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double get_1_degree(void) {
    if (!check()) return -1.0;

    double opposite = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    double adjacent_1 = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    double adjacent_2 = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));

    return acos((pow(adjacent_1, 2) + pow(adjacent_2, 2) - pow(opposite, 2)) / (2 * adjacent_1 * adjacent_2)) * 180 / M_PI;
}

double get_2_degree(void) {
    if (!check()) return -1.0;

    double opposite = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
    double adjacent_1 = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double adjacent_2 = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));

    return acos((pow(adjacent_1, 2) + pow(adjacent_2, 2) - pow(opposite, 2)) / (2 * adjacent_1 * adjacent_2)) * 180 / M_PI;
}

double get_3_degree(void) {
    if (!check()) return -1.0;

    double opposite = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    double adjacent_1 = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    double adjacent_2 = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));

    return acos((pow(adjacent_1, 2) + pow(adjacent_2, 2) - pow(opposite, 2)) / (2 * adjacent_1 * adjacent_2)) * 180 / M_PI;
}

double get_inscribed_center_x(void) {
    if (!check()) return 0.0;

    double a = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    double b = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
    double c = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    return (a * p1.x + b * p2.x + c * p3.x) / (a + b + c);
}

double get_inscribed_center_y(void) {
    if (!check()) return 0.0;

    double a = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    double b = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
    double c = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    return (a * p1.y + b * p2.y + c * p3.y) / (a + b + c);
}

double get_inscribed_center_area(void) {
    if (!check()) return -1.0;

    int64_t triangle_area = get_area();

    double a = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    double b = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
    double c = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    double r = (2 * triangle_area) / (a + b + c);

    return r * r * M_PI;
}

double get_circumscribed_center_x(void) {
    if (!check()) return 0.0;

    double a = p2.x - p1.x;
    double b = p2.y - p1.y;
    double c = p3.x - p1.x;
    double d = p3.y - p1.y;

    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));

    if (g == 0) return NAN;

    double center_x = (d * e - b * f) / g;

    return center_x;
}

double get_circumscribed_center_y(void) {
    if (!check()) return 0.0;

    double a = p2.x - p1.x;
    double b = p2.y - p1.y;
    double c = p3.x - p1.x;
    double d = p3.y - p1.y;

    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));

    if (g == 0) return NAN;

    double center_y = (a * f - c * e) / g;

    return center_y;
}

double get_circumscribed_center_area(void) {
    if (!check()) return -1.0;

    int64_t triangle_area = get_area();

    double a = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    double b = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
    double c = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    double r = (a * b * c) / (4 * triangle_area);

    return r * r * M_PI;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
