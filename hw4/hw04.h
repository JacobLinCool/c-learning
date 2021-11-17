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
int64_t print_K(int64_t);

// hw0402
int64_t hanoi_recursive(int64_t, int64_t, int64_t, int64_t, int64_t);
int64_t hanoi_iterative(int64_t);

// hw0403

// hw0404
