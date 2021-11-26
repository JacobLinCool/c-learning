// Copyright (c) JacobLinCool
#include "triangle.h"

static Point p[3] = { { x: 0.0 / 0.0, y : 0.0 / 0.0 }, { x: 0.0 / 0.0, y : 0.0 / 0.0 }, { x: 0.0 / 0.0, y : 0.0 / 0.0 } };

static int8_t safe = 0;

static double a, b, c, area, perimeter;

static double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

static void prebuild() {
    if (!check()) return;

    a = distance(p[1], p[2]);
    b = distance(p[0], p[2]);
    c = distance(p[0], p[1]);

    perimeter = a + b + c;

    double s = perimeter / 2;

    area = sqrt(s * (s - a) * (s - b) * (s - c));

    return;
}

static int set_point(int8_t idx, double x, double y) {
    // same point detection
    for (int i = 0; i < 3; i++) {
        if (i == idx) continue;
        if (x == p[i].x && y == p[i].y) {
            return 0;
        }
    }

    // same line detection
    double m1 = (p[(idx + 1) % 3].y - y) / (p[(idx + 1) % 3].x - x);
    double m2 = (p[(idx + 2) % 3].y - y) / (p[(idx + 2) % 3].x - x);
    if (m1 == m2) {
        return 0;
    }

    p[idx].x = x;
    p[idx].y = y;

    safe |= (1 << idx);

    prebuild();

    return 1;
}

static double get_degree(int8_t idx) {
    if (!check()) return -1.0;

    double sides[3] = { a, b, c };

    double opposite = sides[idx];
    double adjacent_1 = sides[(idx + 1) % 3];
    double adjacent_2 = sides[(idx + 2) % 3];

    return acos((pow(adjacent_1, 2) + pow(adjacent_2, 2) - pow(opposite, 2)) / (2 * adjacent_1 * adjacent_2)) * 180 / M_PI;
}

int set_1_point(double x, double y) {
    return set_point(0, x, y);
}
int set_2_point(double x, double y) {
    return set_point(1, x, y);
}
int set_3_point(double x, double y) {
    return set_point(2, x, y);
}

int check(void) {
    return safe == (1 << 3) - 1;
}

double get_perimeter(void) {
    if (!check()) return -1.0;

    return perimeter;
}

double get_area(void) {
    if (!check()) return -1.0;

    return area;
}

double get_1_degree(void) {
    return get_degree(0);
}

double get_2_degree(void) {
    return get_degree(1);
}

double get_3_degree(void) {
    return get_degree(2);
}

double get_inscribed_center_x(void) {
    if (!check()) return 0.0;

    return (a * p[0].x + b * p[1].x + c * p[2].x) / perimeter;
}

double get_inscribed_center_y(void) {
    if (!check()) return 0.0;

    return (a * p[0].y + b * p[1].y + c * p[2].y) / perimeter;
}

double get_inscribed_center_area(void) {
    if (!check()) return -1.0;

    double r = (2 * area) / perimeter;
    return r * r * M_PI;
}

double get_circumscribed_center_x(void) {
    if (!check()) return 0.0;

    double D = 2 * (p[0].x * (p[1].y - p[2].y) + p[1].x * (p[2].y - p[0].y) + p[2].x * (p[0].y - p[1].y));
    double numerator = (pow(p[0].x, 2) + pow(p[0].y, 2)) * (p[1].y - p[2].y) + (pow(p[1].x, 2) + pow(p[1].y, 2)) * (p[2].y - p[0].y) + (pow(p[2].x, 2) + pow(p[2].y, 2)) * (p[0].y - p[1].y);
    return numerator / D;
}

double get_circumscribed_center_y(void) {
    if (!check()) return 0.0;

    double D = 2 * (p[0].x * (p[1].y - p[2].y) + p[1].x * (p[2].y - p[0].y) + p[2].x * (p[0].y - p[1].y));
    double numerator = (pow(p[0].x, 2) + pow(p[0].y, 2)) * (p[2].x - p[1].x) + (pow(p[1].x, 2) + pow(p[1].y, 2)) * (p[0].x - p[2].x) + (pow(p[2].x, 2) + pow(p[2].y, 2)) * (p[1].x - p[0].x);
    return numerator / D;
}

double get_circumscribed_center_area(void) {
    if (!check()) return -1.0;

    double r = (a * b * c) / (4 * area);
    return r * r * M_PI;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
