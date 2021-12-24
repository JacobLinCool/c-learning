// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
// #include <math.h>

int main() {
    int printed = -1;

    printf("%nhello, world!\n", &printed);
    printf("printed: %d\n", printed);

    printf("hello%n, world!\n", &printed);
    printf("printed: %d\n", printed);

    printf("hello, world!\n%n", &printed);
    printf("printed: %d\n", printed);

    printf("%d%n\n", 1000000, &printed);
    printf("printed: %d\n", printed);

    printf("%s%n\n", "12345678900987654321", &printed);
    printf("printed: %d\n", printed);

    printf("%c%n\n", 'a', &printed);
    printf("printed: %d\n", printed);

    printf("%p%n\n", &printed, &printed);
    printf("printed: %d\n", printed);

    printf("%f%n\n", 3.1415926, &printed);
    printf("printed: %d\n", printed);

    printf("%d%n\n", -1234567890, &printed);
    printf("printed: %d\n", printed);

    printf("%lx%n\n", 0x123456ABCDEF, &printed);
    printf("printed: %d\n", printed);

    printf("%o%n\n", 077777, &printed);
    printf("printed: %d\n", printed);

    printf("%" PRId64 "%n\n", INT64_MAX, &printed);
    printf("printed: %d\n", printed);

    printf("%" PRId64 "%n\n", INT64_MIN, &printed);
    printf("printed: %d\n", printed);

    printf("%" PRIu64 "%n\n", UINT64_MAX, &printed);
    printf("printed: %d\n", printed);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
