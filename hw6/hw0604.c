// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

typedef enum State {
    START,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    FINAL
} State;

char names[][10] = {
    "Start",
    "S1",
    "S2",
    "S3",
    "S4",
    "S5",
    "S6",
    "Final"
};

void start(int64_t n, State* state) {
    int8_t s = (n == 10 || n == 35) | (n == 11) << 1 | (n == 20 || n == 78) << 2;
    State next_states[5] = { START, S1, S3, -1, S5 };
    *state = next_states[s];
    return;
}

void s1(int64_t n, State* state) {
    int8_t s = (n == 19) | (n == 12 || n == 36) << 1;
    State next_states[3] = { S1, S2, S6 };
    *state = next_states[s];
    return;
}

void s2(int64_t n, State* state) {
    int8_t s = (n == 43) | (n == 99) << 1;
    State next_states[3] = { START, S2, FINAL };
    *state = next_states[s];
    return;
}

void s3(int64_t n, State* state) {
    *state = S4;
    return;
}

void s4(int64_t n, State* state) {
    *state = S6;
    return;
}

void s5(int64_t n, State* state) {
    int8_t s = (n == 1) | (n == 2) << 1;
    State next_states[3] = { START, S4, S6 };
    *state = next_states[s];
    return;
}

void s6(int64_t n, State* state) {
    int8_t s = (n == 108);
    State next_states[2] = { S5, FINAL };
    *state = next_states[s];
    return;
}

void final(int64_t n, State* state) {
    *state = FINAL;
    return;
}

int main() {
    void (*transfer[8]) (int64_t, State*) = { &start, &s1, &s2, &s3, &s4, &s5, &s6, &final };

    State state = START;
    printf("%s\n", names[state]);

    while (state != FINAL) {
        int64_t input = 0;
        printf("Please enter an integer: ");
        scanf("%" SCNd64, &input);
        (*transfer[state])(input, &state);
        printf("%s\n", names[state]);
    }

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
