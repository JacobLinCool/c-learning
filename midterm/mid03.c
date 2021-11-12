// Computer Programming I - Midterm Exam #3
// Copyright © 2021 JacobLinCool. All rights reserved.
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

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
    long double input = 0;

    int64_t state = ask("Enter a number: ", &input);
    while (state != GRACEFUL_EXIT) {
        if (state == INVALID_INPUT) {
            printf("Invalid input! Recieved: %" PRId64 "\n", (int64_t)input);
            return 1;
        }

        printf("%" PRId64 "\n", (int64_t)(input * input));

        state = ask("Enter a number: ", &input);
    }

    printf("Goodbye!\n");

    return 0;
}
