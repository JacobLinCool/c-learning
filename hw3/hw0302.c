// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const int DEBUG = 0;

int64_t calc_length(int64_t n) {
    int64_t length = 1;
    while (n /= 10) length++;
    return length;
}

int main() {
    int64_t first = 0, second = 0;

    printf("Please enter the first  number: ");
    if (scanf("%" SCNd64, &first) != 1 || first < 0 || first > INT32_MAX) {
        printf("Invalid Input. Received: %" PRId64 "\n", first);
        return 1;
    }

    printf("Please enter the second number: ");
    if (scanf("%" SCNd64, &second) != 1 || second < 0 || second > INT32_MAX) {
        printf("Invalid Input. Received: %" PRId64 "\n", second);
        return 1;
    }

    if (DEBUG) printf("[DEBUG] first: %" PRId64 ", second: %" PRId64 "\n", first, second);

    int64_t result = first + second;
    if (DEBUG) printf("[DEBUG] result: %" PRId64 "\n", result);

    if (result > INT32_MAX) {
        printf("Overflow Occurred.\n");
        return 1;
    }

    int64_t length_first = calc_length(first), length_second = calc_length(second), length_result = calc_length(result);
    int64_t split_first[length_first], split_second[length_second], split_result[length_result];
    for (int64_t i = 0; i < length_first; i++) {
        split_first[i] = first % 10;
        first /= 10;
    }
    for (int64_t i = 0; i < length_second; i++) {
        split_second[i] = second % 10;
        second /= 10;
    }
    for (int64_t i = 0; i < length_result; i++) {
        split_result[i] = result % 10;
        result /= 10;
    }


    for (int64_t i = 0; i < (length_result - length_first) + 1; i++) printf("  ");
    for (int64_t i = length_first - 1; i >= 0; i--) printf("%2" PRId64, split_first[i]);
    printf("\n+)");
    for (int64_t i = 0; i < length_result - length_second; i++) printf("  ");
    for (int64_t i = length_second - 1; i >= 0; i--) printf("%2" PRId64, split_second[i]);
    printf("\n");
    for (int64_t i = 0; i < length_result + 1; i++) printf("--");
    printf("\n");
    printf("  ");
    for (int64_t i = length_result - 1; i >= 0; i--) printf("%2" PRId64, split_result[i]);
    printf("\n");

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
