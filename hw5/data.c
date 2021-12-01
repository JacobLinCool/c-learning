// Copyright (c) JacobLinCool
#include "data.h"

static void copy(const int32_t src[], int32_t dst[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        dst[i] = src[i];
    }
    return;
}

static void sort(int32_t input[], size_t size) {
    int32_t temp;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            if (input[j] > input[j + 1]) {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

double get_mean(const int32_t input[], size_t size) {
    long double sum = 0.0L;

    for (size_t i = 0; i < size; i++) {
        sum += (long double)input[i];
    }

    return (double)(sum / (long double)size);
}

double get_median(const int32_t input[], size_t size) {
    int32_t temp[size];
    copy(input, temp, size);
    sort(temp, size);

    double median = 0.0;

    if (size % 2 == 0) {
        median = (double)(temp[size / 2 - 1] + temp[size / 2]) / 2.0;
    }
    else {
        median = temp[size / 2];
    }

    return median;
}

int32_t get_mode(const int32_t input[], size_t size) {
    int32_t temp[size];
    copy(input, temp, size);
    sort(temp, size);

    int32_t mode = temp[size - 1];
    int32_t max_count = 1;
    int32_t count = 1;

    for (size_t i = size - 1; i >= 1; i--) {
        if (temp[i] == temp[i - 1]) {
            count++;
        }
        else {
            count = 1;
        }

        if (count > max_count) {
            max_count = count;
            mode = temp[i];
        }
    }

    return mode;
}

double get_stddev(const int32_t input[], size_t size) {
    double mean = get_mean(input, size);

    long double sum = 0.0L;

    for (size_t i = 0; i < size; i++) {
        sum += (long double)(input[i] - mean) * (long double)(input[i] - mean);
    }

    return (double)sqrtl(sum / (long double)size);
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
