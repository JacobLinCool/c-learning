// Copyright (c) JacobLinCool
#include "hw04.h"

// Input Receiver
int64_t validate_input(int64_t input) {
    if (input >= 1 && input <= 100 && input % 2 == 1) {
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
    int64_t n = 0;

    int64_t state = ask("Please enter n (1-100, n must be odd): ", &n);
    if (state == INVALID_INPUT) {
        printf("Invalid input! Recieved: %" PRId64 "\n", n);
        return 1;
    }

    int64_t success = print_K(n);

    if (success != 1) {
        printf("print_K Failed.\n");
        return 1;
    }

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
