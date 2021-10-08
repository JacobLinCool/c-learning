#include <stdio.h>

int main() {
    float s, v_0, a, t;

    // Inputs
    printf("v_0: ");
    scanf("%f", &v_0);
    printf("a: ");
    scanf("%f", &a);
    printf("t: ");
    scanf("%f", &t);

    // Calculation
    s = v_0 * t + 0.5 * a * t * t;

    printf("--> s = %g\n", s);

    return 0;
}