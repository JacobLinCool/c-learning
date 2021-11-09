#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/**
 * Use x & y to construct a Point.
 */
struct Point {
    double x;
    double y;
};

/**
 * Use 2 Points to construct a Line.
 */
struct Line {
    struct Point p1;
    struct Point p2;
};

/**
 * @brief Get the slope of a line.
 * @param line
 * @return double - the slope of the line, nan if the line is vertical.
 */
double get_slope(struct Line l) {
    if (l.p1.x == l.p2.x) return 0.0 / 0.0;
    if (l.p1.y == l.p2.y) return 0;

    return (l.p1.y - l.p2.y) / (l.p1.x - l.p2.x);
}

/**
 * @brief Get the intersection point of two lines.
 * @param line_1
 * @param line_2
 * @return Point - the intersection point of the two lines, or a point with x and y set to nan if the lines are parallel.
 */
struct Point get_intersection(struct Line l1, struct Line l2) {
    struct Point p;

    p.x = ((l1.p1.x * l1.p2.y - l1.p1.y * l1.p2.x) * (l2.p1.x - l2.p2.x) - (l1.p1.x - l1.p2.x) * (l2.p1.x * l2.p2.y - l2.p1.y * l2.p2.x)) / ((l1.p1.x - l1.p2.x) * (l2.p1.y - l2.p2.y) - (l1.p1.y - l1.p2.y) * (l2.p1.x - l2.p2.x));
    p.y = ((l1.p1.x * l1.p2.y - l1.p1.y * l1.p2.x) * (l2.p1.y - l2.p2.y) - (l1.p1.y - l1.p2.y) * (l2.p1.x * l2.p2.y - l2.p1.y * l2.p2.x)) / ((l1.p1.x - l1.p2.x) * (l2.p1.y - l2.p2.y) - (l1.p1.y - l1.p2.y) * (l2.p1.x - l2.p2.x));

    return p;
}

int main() {
    struct Point p1 = { 1, 1 };
    struct Point p2 = { 0, 0 };
    struct Line l1 = { p1, p2 };

    struct Point p3 = { 0.2, 0 };
    struct Point p4 = { 0.2, 1 };
    struct Line l2 = { p3, p4 };

    struct Point p = get_intersection(l1, l2);

    if (get_slope(l1) != get_slope(l1)) {
        printf("Slope of l1: Inf\n");
    }
    else {
        printf("Slope of l1: %f\n", get_slope(l1));
    }
    if (get_slope(l2) != get_slope(l2)) {
        printf("Slope of l2: Inf\n");
    }
    else {
        printf("Slope of l2: %f\n", get_slope(l2));
    }

    if (p.x != p.x || p.y != p.y) {
        printf("Intersection Point: %f %f\n", p.x, p.y);
    }
    else {
        printf("No Intersection Point.\n");
    }

    return 0;
}
