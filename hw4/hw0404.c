// Copyright (c) JacobLinCool
#include "hw04.h"

// Input Receiver
int64_t validate_input(int64_t input) {
    if (input >= 1 && input <= 100) {
        return 1;
    }
    return 0;
}

int64_t ask(char question[], int64_t* input) {
    printf("%s", question);
    int32_t success = scanf("%" SCNd64, input);
    if (success != 1 || validate_input(*input) == 0) {
        return INVALID_INPUT;
    }
    return ACCEPTED_INPUT;
}

// Main Process
int main() {
    int64_t R = 0, n = 0;

    if (ask("Please enter the resistance (1-100): ", &R) == INVALID_INPUT) {
        printf("Invalid Input! Received %" PRId64 "\n", R);
        return 1;
    }

    if (ask("Please enter n (1-100): ", &n) == INVALID_INPUT) {
        printf("Invalid Input! Received %" PRId64 "\n", n);
        return 1;
    }

    long double equivalent = calculate_equivalent_resistance(R, n);

    printf("Ans: %Lf\n", equivalent);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
