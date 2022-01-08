// Computer Programming I - Final Exam #1 Pentagon Area
// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct Point {
    double x;
    double y;
} Point;

Point points[5] = { {0.0 / 0.0, 0.0 / 0.0}, {0.0 / 0.0, 0.0 / 0.0}, {0.0 / 0.0, 0.0 / 0.0}, {0.0 / 0.0, 0.0 / 0.0}, {0.0 / 0.0, 0.0 / 0.0} };

int8_t check_point_duplicate() {
    for (int8_t i = 0; i < 4; i++) {
        for (int8_t j = i + 1; j < 5; j++) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                return 1;
            }
        }
    }
    return 0;
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double calculate_triangle_area(Point p1, Point p2, Point p3) {
    return 0.5L * (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y);
}

int main() {
    // #region input points
    for (int64_t i = 0; i < 5; i++) {
        printf("Please enter P%" PRId64 ": ", i + 1);
        scanf("%lf,%lf", &points[i].x, &points[i].y);
        if (check_point_duplicate()) {
            printf("This is not a pentagon\n");
            return 1;
        }
    }
    // #endregion

    // #region calculate area
    double area1 = calculate_triangle_area(points[0], points[1], points[2]);
    double area2 = calculate_triangle_area(points[0], points[2], points[3]);
    double area3 = calculate_triangle_area(points[0], points[3], points[4]);
    // #endregion

    // #region check if it is a pentagon
    int8_t convex = 0;
    for (int64_t i = 0; i < 3; i++) {
        for (int64_t j = i + 1; j < 4; j++) {
            for (int64_t k = j + 1; k < 5; k++) {
                if (calculate_triangle_area(points[i], points[j], points[k]) < 0) {
                    convex = 1;
                }
                if (calculate_triangle_area(points[i], points[j], points[k]) <= 0) {
                    printf("This is not a pentagon\n");
                    return 1;
                }
            }
        }
    }
    // for (int8_t i = 0; i < 5; i++) {
    //     for (int8_t j = 1; j <= 3; j++) {
    //         if (calculate_triangle_area(points[i], points[(i + j) % 5], points[(i + j + 1) % 5]) <= 0) {
    //             printf("This is not a pentagon\n");
    //             return 1;
    //         }
    //     }
    // }
    // #endregion

    // #region output
    printf("%g\n", area1 + area2 + area3);
    // #endregion

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
