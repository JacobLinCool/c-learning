// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include "mymem.h"

int main() {
    int64_t* ptr = malloc((sizeof(int64_t) * 1 << 20) * 100);
    memset(ptr, 1, (sizeof(int64_t) * 1 << 20) * 100);
    sleep(10);
    printf("ptr = %p\n", ptr);
    printf("size = %ld\n", (sizeof(int64_t) * 1 << 20) * 100);
    my_realloc((void**)&ptr, (sizeof(int64_t) * 1 << 20) * 100, (sizeof(int64_t) * 1 << 20) * 50);
    sleep(10);
    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
