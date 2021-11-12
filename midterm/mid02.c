// Computer Programming I - Midterm Exam #2
// Copyright © 2021 JacobLinCool. All rights reserved.
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include "midlib.h"

// Input Receiver
enum INPUT_STATE {
    ACCEPTED_INPUT, // Accpeted!
    INVALID_INPUT, // Invalid!
    GRACEFUL_EXIT // Maybe -1 or something?
};

int64_t validate_input(long double input) {
    if (input <= 0) {
        return 0;
    }
    return 1;
}

int64_t ask(char question[], long double* input) {
    printf("%s", question);
    int32_t success = scanf("%Lf", input);
    if (*input == -1) {
        return GRACEFUL_EXIT;
    }
    else if (success != 1 || validate_input(*input) == 0) {
        return INVALID_INPUT;
    }
    return ACCEPTED_INPUT;
}


// Main Proccess
int main() {

    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 1000;
    p2.y = 1000;

    Line l = newLine(p1, p2);

    printf("%Lf\n", l.slope);

    return 0;
}
