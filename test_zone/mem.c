// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#define range 5

void test(size_t size) {
    printf("==== malloc( sizeof(size_t) * \033[93m%zu\033[0m ) ====\n", size);

    void* ptr = malloc(sizeof(size_t) * size);
    printf("Assigned Blocks: \033[92m%lu\033[0m\n", (*((size_t*)ptr - 1) - 9UL) / 16UL);

    // printf("length = %zu\n", *((size_t*)ptr - 1));

    // print memory layout around ptr
    for (int64_t i = -range; i <= range; i++) {
        if (i == 0) {
            printf("[\033[93mptr + 0\033[0m] ");
        }
        else if (i < 0) {
            printf("[\033[94mptr - %" PRId64 "\033[0m] ", -i);
        }
        else {
            printf("[\033[95mptr + %" PRId64 "\033[0m] ", i);
        }
        printf("%p: %lu\n", ptr + i * sizeof(size_t), *((size_t*)ptr + i));
    }

    printf("\n");
}

int main() {

    for (unsigned int i = 0; i < 20; i++) {
        test(i);
    }

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
