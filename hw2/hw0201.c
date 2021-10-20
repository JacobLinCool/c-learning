#include <stdio.h>
#include <stdint.h>

int main() {
    // ax^2 + bx + c = 0
    int64_t a, b, c;
    printf("Please enter a quadratic polynomial (a,b,c): ");
    // Throw an ERROR if the input is not accepted
    if (scanf("%ld,%ld,%ld", &a, &b, &c) != 3) {
        printf("Invalid Input!\n");
        return 1;
    }

    // Calculate discriminant
    int64_t d = b * b - 4 * a * c;

    if (d < 0) printf("No real roots.\n");
    else if (d == 0) printf("One real root.\n");
    else printf("Two distinct real roots.\n");

    return 0;
}
