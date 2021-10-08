#include <stdio.h>
#include <stdint.h>

int main() {
    int16_t inputs[2] = { 0 };

    // Input
    printf("Please enter the first  number: ");
    scanf("%d", &inputs[0]);
    printf("Please enter the second number: ");
    scanf("%d", &inputs[1]);

    // Input Validation
    if (inputs[0] < 100 || inputs[0] > 999 || inputs[1] < 100 || inputs[1] > 999) {
        printf("Invalid input.\n");
        return 1;
    }

    // Calculation
    int16_t sum = inputs[0] + inputs[1];

    // Outputs
    printf("   %d %d %d\n", inputs[0] / 100, inputs[0] % 100 / 10, inputs[0] % 10);
    printf("+) %d %d %d\n", inputs[1] / 100, inputs[1] % 100 / 10, inputs[1] % 10);
    printf("--------\n");
    if (sum > 999) printf(" %d %d %d %d\n", sum / 1000, sum % 1000 / 100, sum % 100 / 10, sum % 10);
    else printf("   %d %d %d\n", sum / 100, sum % 100 / 10, sum % 10);

    return 0;
}
