// Computer Programming I - Midterm Exam #1
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

int64_t validate_input(int64_t input) {
    if (input < 0 || input > INT32_MAX) {
        return 0;
    }
    return 1;
}

int64_t ask(char question[], int64_t* input) {
    printf("%s", question);
    int32_t success = scanf("%" SCNd64, input);
    if (success != 1 || validate_input(*input) == 0) {
        return INVALID_INPUT;
    }
    return ACCEPTED_INPUT;
}

// Utils
int64_t calc_digit(int64_t n) {
    int64_t digit = 1;
    while (n /= 10) digit++;
    return digit;
}

// Main Proccess
int main() {
    int64_t a = 0, b = 0;

    int64_t state_a = ask("Please enter the 1st integer: ", &a);
    if (state_a == INVALID_INPUT) {
        printf("Invalid input! Recieved: %" PRId64 "\n", a);
        return 1;
    }
    int64_t state_b = ask("Please enter the 2nd integer: ", &b);
    if (state_b == INVALID_INPUT) {
        printf("Invalid input! Recieved: %" PRId64 "\n", b);
        return 1;
    }

    int64_t digit_a = calc_digit(a), digit_b = calc_digit(b);

    for (int64_t i = digit_a + digit_b; i > 0; i--) {
        if (digit_a == 0) {
            printf("%" PRId64, b % 10);
            b /= 10;
        }
        else if (digit_b == 0) {
            printf("%" PRId64, a % 10);
            a /= 10;
        }
        else {
            int64_t a_last = a % 10, b_last = b % 10;

            if (a_last > b_last) {
                printf("%" PRId64, a_last);
                a /= 10;
            }
            else {
                printf("%" PRId64, b_last);
                b /= 10;
            }
        }
    }

    printf("\n");

    return 0;
}
