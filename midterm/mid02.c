// Computer Programming I - Midterm Exam #2
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
    return 1;
}

int64_t ask(char question[], int64_t* input) {
    printf("%s", question);
    int32_t success = scanf("%" SCNd64, input);
    if (*input == 0) {
        return GRACEFUL_EXIT;
    }
    else if (success != 1 || validate_input(*input) == 0) {
        return INVALID_INPUT;
    }
    return ACCEPTED_INPUT;
}

// Checkers
int64_t checker_1(int64_t x) {
    if (x == 13 || x == 27 || x == 68) return 1;
    return 0;
}

int64_t checker_2(int64_t x) {
    if (x == -5 || x == 19 || x == 103 || x == 27) return 1;
    return 0;
}

int64_t checker_3(int64_t x) {
    if (x == -33) return 1;
    return 0;
}

// Main Proccess
int main() {
    int64_t input = 0;

    int64_t position = 0, start_integer = 0;
    int64_t check_state = 0, prev_checker = 0, checker_2_tolerence = 0, input_count = 0;
    int64_t state = ask("Please enter the integer: ", &input);
    while (state != GRACEFUL_EXIT) {
        input_count++;
        if (state == INVALID_INPUT) {
            printf("Invalid input! Recieved: %" PRId64 "\n", input);
        }

        if (check_state >= 6) {
            state = ask("Please enter the integer: ", &input);
            continue;
        }

        if (check_state == 0) {
            if (checker_1(input) == 1) {
                position = input_count;
                start_integer = input;
                check_state = 1;
                prev_checker = 1;
            }
            else if (checker_2(input) == 1) {
                position = input_count;
                start_integer = input;
                check_state = 2;
                prev_checker = 2;
            }
        }
        else {
            if (prev_checker == 1) {
                if (checker_2(input) == 1) {
                    check_state++;
                    prev_checker = 2;
                }
                else {
                    check_state = 0;
                    prev_checker = 0;
                }
            }
            else if (prev_checker == 2) {
                if (checker_3(input) == 1) {
                    check_state++;
                    prev_checker = 3;
                    checker_2_tolerence = 0;
                }
                else if (checker_2(input) == 1 && !checker_2_tolerence) {
                    checker_2_tolerence = 1;
                }
                else {
                    check_state = 0;
                    prev_checker = 0;
                    checker_2_tolerence = 0;
                }
            }
            else if (prev_checker == 3) {
                if (checker_1(input) == 1) {
                    check_state++;
                    prev_checker = 1;
                }
                else if (checker_2(input) == 1) {
                    check_state++;
                    check_state++;
                    prev_checker = 2;
                }
                else {
                    check_state = 0;
                    prev_checker = 0;
                }
            }
        }

        // printf("[DEBUG] check_state: %" PRId64 " prev_checker: %" PRId64 " checker_2_tolerence: %" PRId64 "\n", check_state, prev_checker, checker_2_tolerence);

        state = ask("Please enter the integer: ", &input);
    }

    if (check_state >= 6) printf("The first matching series is at position %" PRId64 ", integer %" PRId64 ".\n", position, start_integer);
    else printf("None\n");
    return 0;
}
