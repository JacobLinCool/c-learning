// Copyright (c) JacobLinCool (MIT Licensed)
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#define RANGE_MAX 100000000

void help();
void test(int32_t size);

int main(int argc, char* argv[]) {
    if (argc == 1) {
        help();
        return 0;
    }

    if (argc == 4 && (strcmp(argv[1], "range") & strcmp(argv[1], "r")) == 0) {
        int32_t start = atoi(argv[2]), end = atoi(argv[3]);
        size_t count = 0;
        for (int32_t i = start; i <= end; i++) {
            test(i);
            count++;
            if (count > RANGE_MAX) {
                printf("\033[91mRange Is Too Wide!\033[0m\n");
                break;
            }
        }
    }
    else {
        for (size_t i = 1; i < argc; i++) {
            test(atoi(argv[i]));
        }
    }

    return 0;
}

void help() {
    printf("Allocation Size Checker by \033[96mJacobLinCool\033[0m.\n");
    printf("Only Tested on \033[93mLinux (Ubuntu 20.04.3)\033[0m.\n\n");
    printf("Usage 1: \033[93m./check \033[95m[size1] [size2] ...\033[0m\n");
    printf("    Example: \033[93m./check \033[95m24 25 40 41 56 57 72 73 88 89\033[0m\n");
    printf("Usage 2: \033[93m./check range \033[95m[start] [end]\033[0m\n");
    printf("    Example: \033[93m./check range \033[95m0 100\033[0m\n");
}

void test(int32_t size) {
    if (size < 0) {
        printf("\033[91mNegative Size Detected! Skipped. (%4" PRId32 ")\033[0m\n", size);
        return;
    }
    printf("malloc( \033[93m%4" PRId32 "\033[0m ) : ", size);

    size_t* pointer = malloc(size);
    printf("\033[92m%4lu\033[0m ( \033[95m0x%lX\033[0m )\n", *(pointer - 1), *(pointer - 1));
    free(pointer);
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
