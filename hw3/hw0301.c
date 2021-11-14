// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Print debug messages if DEBUG = 1
const int DEBUG = 0;

// The width and height of the matrix
int64_t width = 0, height = 0;

// Ask for inputs
int ask(char[], int64_t*);

// Caclulate the digit for a given number
int32_t calc_digit(int64_t);

// Get the number at a given position
int64_t get_num(int64_t, int64_t);

// Calculate the level of a given position
int64_t calc_level(int64_t, int64_t);

int main() {
    if (!ask("Please enter the width  : ", &width)) return 1;
    if (!ask("Please enter the height : ", &height)) return 1;

    int32_t padding = calc_digit(width * height);

    for (int64_t i = 0; i < height; i++) {
        for (int64_t j = 0; j < width; j++) printf("%*" PRId64 " ", padding, get_num(i, j));
        printf("\n");
    }

    return 0;
}

int ask(char q[], int64_t* answer) {
    printf("%s", q);
    int eaten = scanf("%" SCNd64, answer);
    if (eaten == 1 && *answer > 0) return 1;
    printf("Invalid Input. Received: %" PRId64 "\n", *answer);
    return 0;

}

int32_t calc_digit(int64_t n) {
    int64_t padding = 1;
    while (n /= 10) padding++;
    return padding;
}

int64_t get_num(int64_t y, int64_t x) {
    int64_t num = 0;
    int64_t level = calc_level(y, x);
    int64_t h = height - 2 * level, w = width - 2 * level;
    int64_t last_num = height * width - h * w;

    if (h == 1 || w == 1) num = last_num + 1 + (y - level) + (x - level);
    else if ((y == level && x != level) || x == width - level - 1) num = last_num + (h + w - 2) + (height - level - y) + (width - level - x - 1);
    else num = last_num + (y - level + 1) + (x - level);

    return num;
}

int64_t calc_level(int64_t y, int64_t x) {
    int64_t level = x < y ? x : y;
    level = width - x - 1 < level ? width - x - 1 : level;
    level = height - y - 1 < level ? height - y - 1 : level;

    if (DEBUG) printf("(%" PRId64 ", %" PRId64 ") -> %" PRId64 "\n", y, x, level);

    return level;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
