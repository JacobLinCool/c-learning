// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "mem.h"

int main() {
    size_t header = 0xFF;
    void* p = my_malloc(48, 16, &header);

    printf("%p\n", p);

    my_push(&p, 0xF, &header);

    my_free(p, header);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
