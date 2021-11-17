// Copyright (c) JacobLinCool
#include "hw04.h"

// Input Receiver
int64_t validate_input(int64_t input) {
    if (input >= 2 && input <= 20) {
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
    int64_t disk;

    int64_t state = ask("Please enter the disk number (2-20): ", &disk);
    if (state == INVALID_INPUT) {
        printf("Invalid input! Recieved: %" PRId64 "\n", disk);
        return 1;
    }

    // n, from, to, temp, now
    hanoi_recursive(disk, 1, 3, 2, disk);

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
