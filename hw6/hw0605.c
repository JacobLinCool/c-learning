// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include "mymem.h"

void homemade() {
    int64_t* ptr = malloc(sizeof(int64_t) * 16);
    for (int i = 0; i < 16; i++) {
        ptr[i] = i + 1;
    }

    // print memory layout around ptr
    for (int64_t i = -1; i <= 17; i++) {
        if (i == 0) {
            printf("[\033[93mptr + 0\033[0m] ");
        }
        else {
            printf("[\033[95mptr + %" PRId64 "\033[0m] ", i);
        }
        printf("%p: %" PRId64 "\n", ptr + i, *(ptr + i));
    }

    printf("\n");

    my_realloc((void**)&ptr, sizeof(int64_t) * 16, sizeof(int64_t) * 8);

    // print memory layout around ptr
    for (int64_t i = -1; i <= 17; i++) {
        if (i == 0) {
            printf("[\033[93mptr + 0\033[0m] ");
        }
        else {
            printf("[\033[95mptr + %" PRId64 "\033[0m] ", i);
        }
        printf("%p: %" PRId64 "\n", ptr + i, *(ptr + i));
    }

    printf("\n");
}

void builtin() {
    int64_t* ptr = malloc(sizeof(int64_t) * 16);
    for (int i = 0; i < 16; i++) {
        ptr[i] = i + 1;
    }

    // print memory layout around ptr
    for (int64_t i = -1; i <= 17; i++) {
        if (i == 0) {
            printf("[\033[93mptr + 0\033[0m] ");
        }
        else {
            printf("[\033[95mptr + %" PRId64 "\033[0m] ", i);
        }
        printf("%p: %" PRId64 "\n", ptr + i, *(ptr + i));
    }

    printf("\n");

    realloc((void*)ptr, sizeof(int64_t) * 8);

    // print memory layout around ptr
    for (int64_t i = -1; i <= 17; i++) {
        if (i == 0) {
            printf("[\033[93mptr + 0\033[0m] ");
        }
        else {
            printf("[\033[95mptr + %" PRId64 "\033[0m] ", i);
        }
        printf("%p: %" PRId64 "\n", ptr + i, *(ptr + i));
    }

    printf("\n");
}

int main() {
    homemade();

    builtin();

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
