// Copyright (c) JacobLinCool
#include <stdio.h>
#include <inttypes.h>
#include "poker.h"

int main() {
    int8_t cards[13] = { 45,2,34,27,22,15,10,4,28,40,35,41,23 };

    printf("Cards: ");
    for (int i = 0; i < 13; i++) {
        printf("%" PRId8 " ", cards[i]);
    }
    printf("\n");

    printf("Success: %" PRId32 "\n", big_two_sort(cards));

    printf("Sorted: ");
    for (int i = 0; i < 13; i++) {
        printf("%" PRId8 " ", cards[i]);
    }
    printf("\n");

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
