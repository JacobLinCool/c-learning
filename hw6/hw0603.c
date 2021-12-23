// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

void print(uint64_t* value) {
    u_int8_t* p = (u_int8_t*)value;

    for (int i = 0; i < 8; i++) {
        printf("(%d) 0x%02X ", i + 1, *(p + 7 - i));
    }
    printf("\n");

    return;
}

int8_t set_val(uint64_t* value, int64_t position, uint8_t val) {
    u_int8_t* p = (u_int8_t*)value;
    *(p + 7 - position) = val;

    return 0;
}

int main() {
    u_int64_t* value = malloc(sizeof(u_int64_t));

    uint64_t initial_value = 0;
    printf("Please input an integer: ");
    scanf("%" SCNu64, &initial_value);
    *value = initial_value;

    printf("The integer: %" PRIu64 "\n", *value);
    print(value);

    while (1) {
        uint64_t position = 0;
        printf("Please enter the position (1-8, 0: End): ");
        scanf("%" SCNu64, &position);

        if (position == 0) {
            break;
        }
        else if (position < 0 || position > 8) {
            printf("Invalid position!\n");
            continue;
        }

        uint64_t val = 0;
        while (1) {
            printf("Please enter the new value (0-255): ");
            scanf("%" SCNu64, &val);

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
        printf("The integer: %" PRIu64 "\n", *value);
        print(value);
    }

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
