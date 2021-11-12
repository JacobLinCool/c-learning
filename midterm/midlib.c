// Copyright © 2021 JacobLinCool. All rights reserved.
#include "midlib.h"

long double ABS(long double x) {
    return x < 0 ? -x : x;
}

/**
 * Use x & y to construct a Point.
 */
 // typedef struct Point {
 //     long double x;
 //     long double y;
 // } Point;

 /**
  * @brief Get the slope of two points.
  * @param point_1
  * @param point_2
  * @return long double - the slope of the line, nan if the line is vertical.
  */
long double get_slope(Point p1, Point p2) {
    if (p1.x == p2.x) return NAN;
    return (p2.y - p1.y) / (p2.x - p1.x);
}

/**
 * Use 2 Points to construct a Line.
 */
 // typedef struct Line {
 //     struct Point p1;
 //     struct Point p2;
 //     long double slope;
 //     long double x_intercept;
 //     long double y_intercept;
 // } Line;

 /**
  * @brief Create New Line By Two Points.
  *
  * @param point_1
  * @param point_2
  * @return Line
  */
Line newLine(Point p1, Point p2) {
    Line line;
    line.p1 = p1;
    line.p2 = p2;
    line.slope = get_slope(p1, p2);
    line.x_intercept = isnan(line.slope) ? p1.x : p1.x - (1 / line.slope) * p1.y;
    line.y_intercept = isnan(line.slope) ? NAN : p1.y - line.slope * p1.x;
    return line;
}

/**
 * @brief Check if two lines are parallel.
 *
 * @param line_1
 * @param line_2
 * @return int8_t - 1 if parallel, 0 if not.
 */
int8_t is_parallel(Line l1, Line l2) {
    // vertical lines
    if (l1.slope != l1.slope && l2.slope != l2.slope) return 1;

    return l1.slope == l2.slope;
}

/**
 * @brief Check if two lines are the same.
 *
 * @param line_1
 * @param line_2
 * @return int8_t - 1 if same, 0 if not.
 */
int8_t is_same_line(Line l1, Line l2) {
    if (!is_parallel(l1, l2)) return 0;

    // if we only check the x_intercept, it will have a problem when the line is vertical.
    if (l1.x_intercept == l2.x_intercept) return 1;

    return 0;
}

/**
 * @brief Get the intersection point of two lines.
 * @param line_1
 * @param line_2
 * @return Point - the intersection point of the two lines, or a point with x and y set to nan if the lines are parallel.
 */
Point get_intersection_point(Line l1, Line l2) {
    Point p;

    if (is_parallel(l1, l2)) {
        p.x = p.y = NAN;
    }
    else {
        if (isnan(l1.slope)) {
            p.x = l1.x_intercept;
            p.y = l2.slope * p.x + l2.y_intercept;
        }
        else if (isnan(l2.slope)) {
            p.x = l2.x_intercept;
            p.y = l1.slope * p.x + l1.y_intercept;
        }
        else {
            p.x = (l2.y_intercept - l1.y_intercept) / (l1.slope - l2.slope);
            p.y = l1.slope * p.x + l1.y_intercept;
        }
    }

    return p;
}

/**
 * @brief Get the distance between two lines.
 *
 * @param line_1
 * @param line_2
 * @return long double
 */
long double get_distance_between_lines(Line l1, Line l2) {
    if (!is_parallel(l1, l2)) return 0.0L;
    if (is_same_line(l1, l2)) return 0.0L;

    if (l1.slope != l1.slope) {
        return ABS(l1.x_intercept - l2.x_intercept);
    }
    else {
        return ABS(l1.y_intercept - l2.y_intercept) / (1 + l1.slope * l1.slope);
    }
}
