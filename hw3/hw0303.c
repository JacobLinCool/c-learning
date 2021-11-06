#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const int DEBUG = 0;

enum states {
    S_START,
    S_S1,
    S_S2,
    S_S3,
    S_S4,
    S_S5,
    S_S6,
    S_FINAL
};

int main() {
    int8_t state = S_START;
    int64_t n = 0;

    printf("Start\n");

    while (state != S_FINAL) {
        printf("Please enter an integer: ");
        if (scanf("%" SCNd64, &n) != 1) {
            printf("Invalid Input. Received: %" PRId64 "\n", n);
            return 1;
        }
        if (DEBUG) printf("[DEBUG] Received: %" PRId64 "\n", n);

        switch (state) {
        case S_START:
            if (n == 10 || n == 35) state = S_S1;
            else if (n == 11) state = S_S3;
            else if (n == 20 || n == 78) state = S_S5;
            else state = S_START;
            break;

        case S_S1:
            if (n == 19) state = S_S2;
            else if (n == 12 || n == 36) state = S_S6;
            else state = S_S1;
            break;

        case S_S2:
            if (n == 43) state = S_S2;
            else if (n == 99) state = S_FINAL;
            else state = S_START;
            break;

        case S_S3:
            state = S_S4;
            break;

        case S_S4:
            state = S_S6;
            break;

        case S_S5:
            if (n == 1) state = S_S4;
            else if (n == 2) state = S_S6;
            else state = S_START;
            break;

        case S_S6:
            if (n == 108) state = S_FINAL;
            else state = S_S5;
            break;

        default:
            printf("How Did You Get There?? (%" PRId8 ")\n", state);
            return 1;
        }

        if (state == S_START) printf("Start\n");
        else if (state != S_FINAL) printf("S%" PRId8 "\n", state);
    }

    printf("Final\n");

    return 0;
}