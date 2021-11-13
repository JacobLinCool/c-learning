// Computer Programming I - Midterm Exam #3
// Copyright © 2021 JacobLinCool. All rights reserved.
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>

typedef struct Layer {
    double refractive_index;
    double height;
} Layer;

// Main Proccess
int main() {
    double incidence_angle = -1.0;
    printf("Incidence angle: ");
    if (scanf("%lf", &incidence_angle) != 1 || incidence_angle < 0 || incidence_angle > 90) {
        printf("Error: Invalid Incidence Angle! Recieved: %lf\n", incidence_angle);
        return 1;
    }
    incidence_angle = incidence_angle * M_PI / 180;

    int64_t layer_count = 0;
    printf("How many layers: ");
    if (scanf("%" SCNd64, &layer_count) != 1 || layer_count < 1) {
        printf("Error: Invalid Number of Layers! Recieved: %" PRId64 "\n", layer_count);
        return 1;
    }

    Layer* layers = malloc(sizeof(Layer) * layer_count);

    for (int64_t i = 0; i < layer_count; i++) {
        printf("Layer %" PRId64 "'s refractive index: ", i + 1);
        if (scanf("%lf", &layers[i].refractive_index) != 1 || layers[i].refractive_index < 1) {
            printf("Error: Invalid Refractive Index! Recieved: %lf\n", layers[i].refractive_index);
            return 1;
        }
        printf("Layer %" PRId64 "'s height: ", i + 1);
        if (scanf("%lf", &layers[i].height) != 1 || layers[i].height <= 0) {
            printf("Error: Invalid Layer Height! Recieved: %lf\n", layers[i].height);
            return 1;
        }
    }

    double shift = 0.0;

    for (int64_t i = 0; i < layer_count; i++) {
        shift += layers[i].height * tan(incidence_angle);
        if (i != layer_count - 1) {
            incidence_angle = asin((layers[i].refractive_index / layers[i + 1].refractive_index) * sin(incidence_angle));
        }
        // printf("[DEBUG] Layer %" PRId64 ": Refractive Index: %lf, Height: %lf, Shift: %lf, Out-Angle: %lf\n", i, layers[i].refractive_index, layers[i].height, shift, incidence_angle);
    }

    printf("The shift: %lg\n", shift);

    return 0;
}
