// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

void print(int64_t* value) {
    // printf("[DEBUG] 0x%016llX\n", *value);
    int8_t* p = (int8_t*)value;

    for (int8_t i = 0; i < 8; i++) {
        printf("(%d) 0x%02X ", i + 1, *(p + 7 - i) & 0xFF);
    }
    printf("\n");

    return;
}

int8_t set_val(int64_t* value, int64_t position, int8_t val) {
    int8_t* p = (int8_t*)value;
    *(p + 7 - position) = val;

    return 0;
}

int main() {
    int64_t* value = malloc(sizeof(int64_t));

    int64_t initial_value = 0;
    printf("Please input an integer: ");
    scanf("%" SCNd64, &initial_value);
    *value = initial_value;

    printf("The integer: %" PRId64 "\n", *value);
    print(value);

    while (1) {
        int64_t position = 0;
        printf("Please enter the position (1-8, 0: End): ");
        scanf("%" SCNd64, &position);

        if (position == 0) {
            break;
        }
        else if (position < 0 || position > 8) {
            printf("Invalid position!\n");
            continue;
        }

        int64_t val = 0;
        while (1) {
            printf("Please enter the new value (0-255): ");
            scanf("%" SCNd64, &val);

            if (val > 255 || val < 0) {
                printf("Invalid value!\n");
                continue;
            }
            else {
                break;
            }
        }

        set_val(value, position - 1, val);

        printf("---\n");
        printf("The integer: %" PRId64 "\n", *value);
        print(value);
    }

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
