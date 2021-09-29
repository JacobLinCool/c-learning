#include <stdio.h>

int main() {
    int input, result = 1;

    printf("Please enter a 5-digits integer: ");
    scanf("%d", &input);

    // calculate the product of "input" and store it in "result"
    for (int i = 0; i < 5; i++) {
        // we calculate the product from the last digit to the first digit
        result *= input % 10;
        input /= 10;
    }

    printf("Result: %d\n", result);

    return 0;
}