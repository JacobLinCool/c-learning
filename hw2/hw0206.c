#include <stdio.h>

int main() {
    // Set style to [Bold] [Red]
    printf("\033[1;31m");

    // Print "Hello World"
    printf("Hello World\n");

    // Reset
    printf("\033[0m");

    return 0;
}
