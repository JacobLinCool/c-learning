// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    printf("===\n[Printf Test]\n");
    printf(
        "printf(\"Hello, World!\\n\"): %d\n",
        printf("Hello, World!\n")
    );

    printf("===\n[Scanf Test]\n");
    int32_t a = 0;
    int32_t b = 0;
    printf("scanf(\"%%d %%d\")\nPlease input two items:\n");
    printf("scanf(\"%%d %%d\"): %d\n", scanf("%d %d", &a, &b));

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
