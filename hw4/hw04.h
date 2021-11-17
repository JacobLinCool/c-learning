// Copyright (c) JacobLinCool
#pragma once
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// General
enum INPUT_STATE {
    ACCEPTED_INPUT, // Accpeted!
    INVALID_INPUT, // Invalid!
    GRACEFUL_EXIT // Graceful Exit!
};

// hw0401
int64_t print_K(int64_t n);

// hw0402
int64_t hanoi_recursive(int64_t n, int64_t from, int64_t to, int64_t temp, int64_t now);

int64_t hanoi_iterative(int64_t n);

int64_t power(int64_t base, int64_t exp);

typedef struct Rod {
    int64_t disks[20];
    int64_t top;
} Rod;

Rod create_rod(int64_t n, int8_t fill);

int64_t move_disk(Rod* from, Rod* to);

int64_t transfer_disk(Rod* a, Rod* b, int64_t* reversed);

// hw0403

// hw0404
