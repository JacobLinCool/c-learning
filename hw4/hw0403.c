// Copyright (c) JacobLinCool
#include "triangle.h"

// Main Process
int main() {

    printf(
        "Initial States: \nCheck: %d\nPerimeter: %lf\nArea: %lf\nDegree 1: %lf\nDegree 2: %lf\nDegree 3: %lf\nInscribed (X, Y): (%lf, %lf)\nInscribed Area: %lf\nCircumscribed (X, Y): (%lf, %lf)\nCircumscribed Area: %lf\n---\n",
        check(),
        get_perimeter(),
        get_area(),
        get_1_degree(),
        get_2_degree(),
        get_3_degree(),
        get_inscribed_center_x(),
        get_inscribed_center_y(),
        get_inscribed_center_area(),
        get_circumscribed_center_x(),
        get_circumscribed_center_y(),
        get_circumscribed_center_area()
    );

    printf("%d %d %d\n", set_1_point(0.0, 0.0), set_2_point(0.0, 3.0), set_3_point(4.0, 0.0));
    printf(
        "Points (0, 0), (0, 3), (4, 0): \nCheck: %d\nPerimeter: %lf\nArea: %lf\nDegree 1: %lf\nDegree 2: %lf\nDegree 3: %lf\nInscribed (X, Y): (%lf, %lf)\nInscribed Area: %lf\nCircumscribed (X, Y): (%lf, %lf)\nCircumscribed Area: %lf\n---\n",
        check(),
        get_perimeter(),
        get_area(),
        get_1_degree(),
        get_2_degree(),
        get_3_degree(),
        get_inscribed_center_x(),
        get_inscribed_center_y(),
        get_inscribed_center_area(),
        get_circumscribed_center_x(),
        get_circumscribed_center_y(),
        get_circumscribed_center_area()
    );

    printf("%d %d %d\n", set_1_point(0.0, 6.0), set_2_point(-sqrt(36.0 - 9.0), -3.0), set_3_point(sqrt(36.0 - 9.0), -3.0));
    printf(
        "Points (0, 6), (-sqrt(27), -3), (sqrt(27), -3): \nCheck: %d\nPerimeter: %lf\nArea: %lf\nDegree 1: %lf\nDegree 2: %lf\nDegree 3: %lf\nInscribed (X, Y): (%lf, %lf)\nInscribed Area: %lf\nCircumscribed (X, Y): (%lf, %lf)\nCircumscribed Area: %lf\n---\n",
        check(),
        get_perimeter(),
        get_area(),
        get_1_degree(),
        get_2_degree(),
        get_3_degree(),
        get_inscribed_center_x(),
        get_inscribed_center_y(),
        get_inscribed_center_area(),
        get_circumscribed_center_x(),
        get_circumscribed_center_y(),
        get_circumscribed_center_area()
    );

    printf("%d %d %d\n", set_1_point(1.0, 6.0), set_2_point(1.0, 3.0), set_3_point(1.0, -3.0));
    printf(
        "Points (1, 6), (1, 3), (1, -3): \nCheck: %d\nPerimeter: %lf\nArea: %lf\nDegree 1: %lf\nDegree 2: %lf\nDegree 3: %lf\nInscribed (X, Y): (%lf, %lf)\nInscribed Area: %lf\nCircumscribed (X, Y): (%lf, %lf)\nCircumscribed Area: %lf\n---\n",
        check(),
        get_perimeter(),
        get_area(),
        get_1_degree(),
        get_2_degree(),
        get_3_degree(),
        get_inscribed_center_x(),
        get_inscribed_center_y(),
        get_inscribed_center_area(),
        get_circumscribed_center_x(),
        get_circumscribed_center_y(),
        get_circumscribed_center_area()
    );

    printf("%d %d %d\n", set_1_point(-1.0, 3.0), set_2_point(0.0, 3.0), set_3_point(1.0, 3.0));
    printf(
        "Points (-1, 3), (0, 3), (1, 3): \nCheck: %d\nPerimeter: %lf\nArea: %lf\nDegree 1: %lf\nDegree 2: %lf\nDegree 3: %lf\nInscribed (X, Y): (%lf, %lf)\nInscribed Area: %lf\nCircumscribed (X, Y): (%lf, %lf)\nCircumscribed Area: %lf\n---\n",
        check(),
        get_perimeter(),
        get_area(),
        get_1_degree(),
        get_2_degree(),
        get_3_degree(),
        get_inscribed_center_x(),
        get_inscribed_center_y(),
        get_inscribed_center_area(),
        get_circumscribed_center_x(),
        get_circumscribed_center_y(),
        get_circumscribed_center_area()
    );

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
