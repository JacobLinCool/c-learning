#ifndef MIDLIB_HEADER_INCLUDED
#define MIDLIB_HEADER_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

long double ABS(long double);

typedef struct Point {
    long double x;
    long double y;
} Point;

typedef struct Line {
    struct Point p1;
    struct Point p2;
    long double slope;
    long double x_intercept;
    long double y_intercept;
} Line;

long double get_slope(Point, Point);

Line newLine(Point, Point);

int8_t is_parallel(Line, Line);

int8_t is_same_line(Line, Line);

Point get_intersection_point(Line, Line);

long double get_distance_between_lines(Line, Line);

#endif