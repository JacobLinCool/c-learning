#include <stdio.h>
#include <stdint.h>

int main() {
    int64_t x1, y1, x2, y2;

    printf("First point (x,y): ");
    // Throw an ERROR if the input is not accepted
    if (scanf("%lli, %lli", &x1, &y1) != 2) {
        printf("Invalid Input!\n");
        return 1;
    }

    printf("Second point (x,y): ");
    // Throw an ERROR if the input is not accepted
    if (scanf("%lli, %lli", &x2, &y2) != 2) {
        printf("Invalid Input!\n");
        return 1;
    }

    int64_t perimeter = (((x1 - x2) > 0 ? (x1 - x2) : (x2 - x1)) + ((y1 - y2) > 0 ? (y1 - y2) : (y2 - y1))) * 2;
    int64_t area = (((x1 - x2) > 0 ? (x1 - x2) : (x2 - x1)) * ((y1 - y2) > 0 ? (y1 - y2) : (y2 - y1)));

    // Throw an ERROR if there is a vertical or horizontal line
    if (area <= 0 && (x1 != x2 || y1 != y2)) {
        printf("Problematic Input: Two Points Cannot Be In The Same Vertical or Horizontal Line.\n");
        return 1;
    }

    printf("Perimeter --> %lli\n", perimeter);
    printf("Area --> %lli\n", area);

    return 0;
}
