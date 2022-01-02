// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

size_t* alloc_1MB() {
    size_t* ptr = malloc(1024 * 1024);

    size_t size = 1024 * 1024 / sizeof(size_t);

    for (size_t i = 0; i < size; i++) {
        ptr[i] = i + 1;
    }

    return ptr;
}

int64_t string_to_integer(char* str) {
    int64_t sign = 1;
    int64_t result = 0;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

int main(int argc, char* argv[]) {
    int64_t max = 8 * 1024;

    if (argc == 2) {
        max = string_to_integer(argv[1]);

        if (max < 0) {
            max = 8 * 1024;
        }
    }
    else if (argc > 2) {
        fprintf(stderr, "Usage: %s [max allocation size (MB)]\n", argv[0]);
        return 1;
    }

    for (int64_t i = 0; i < max; i++) {
        size_t* ptr = alloc_1MB();
    }

    printf("Allocated %" PRId64 " MB Memory.\n", max);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
