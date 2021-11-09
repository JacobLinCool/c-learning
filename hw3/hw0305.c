#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define MAX_SIZE 2000

const int DEBUG = 0;

int64_t data_size = 0;
long double year_sum = 0, temperature_sum = 0;
long double years[MAX_SIZE], temperatures[MAX_SIZE];

enum READ_STATE {
    ACCEPTED_INPUT,
    INVALID_INPUT,
    DUPLICATE_INPUT,
    GRACEFUL_EXIT
};

int32_t read(int64_t* Pyear, long double* Ptemp) {
    printf("Please enter the year: ");
    if (scanf("%" SCNd64, Pyear) != 1 || (*Pyear < 1900 && *Pyear != -1)) return INVALID_INPUT;
    if (*Pyear == -1) return GRACEFUL_EXIT;

    for (int64_t i = 0; i < data_size; i++) {
        if (*Pyear == years[i]) return DUPLICATE_INPUT;
    }

    printf("Temperature: ");
    if (scanf("%Lf", Ptemp) != 1 || *Ptemp + 273.15 < 0) return INVALID_INPUT;

    return ACCEPTED_INPUT;
}

int main() {
    int64_t year = 0;
    long double temperature = 0;

    int32_t state = read(&year, &temperature);
    while (state == ACCEPTED_INPUT) {
        year_sum += year;
        temperature_sum += temperature;

        years[data_size] = year;
        temperatures[data_size] = temperature;
        data_size++;

        if (DEBUG) printf("[DEBUG] data_size: %" PRId64 ", year_sum: %Lf, temperature_sum: %Lf\n", data_size, year_sum, temperature_sum);

        state = read(&year, &temperature);
    }

    if (state == INVALID_INPUT) {
        printf("Invalid Input!\n");
        return 1;
    }

    if (state == DUPLICATE_INPUT) {
        printf("Duplicate Input!\n");
        return 1;
    }

    if (data_size < 2) {
        printf("The amount of data is not enough to predict.\n");
        return 1;
    }

    if (DEBUG) printf("[DEBUG] year_avg: %Lf, year_sum: %Lf\n", year_sum / data_size, year_sum);
    if (DEBUG) printf("[DEBUG] temperature_avg: %Lf, temperature_sum: %Lf\n", temperature_sum / data_size, temperature_sum);

    // build the least square model
    long double x_sum = 0, y_sum = 0, xy_sum = 0, xx_sum = 0;
    for (int64_t i = 0; i < data_size; i++) {
        x_sum += years[i];
        y_sum += temperatures[i];
        xy_sum += years[i] * temperatures[i];
        xx_sum += years[i] * years[i];
    }
    long double x_avg = x_sum / data_size, y_avg = y_sum / data_size;
    long double xy_avg = xy_sum / data_size, xx_avg = xx_sum / data_size;
    long double a = (xy_avg - x_avg * y_avg) / (xx_avg - x_avg * x_avg);
    long double b = y_avg - a * x_avg;

    if (DEBUG) printf("[DEBUG] a: %Lf, b: %Lf\n", a, b);

    if (a != a || b != b) {
        printf("We cannot build any model base on the provided data. :(\n");
        return 1;
    }

    // predict the temperature
    long double year_predict = 0;
    printf("Please enter the prediction year: ");
    if (scanf("%Lf", &year_predict) != 1 || (year_predict < 1900)) {
        printf("Invalid Input!\n");
        return 1;
    }

    printf("Temperature: %.4Lf\n", a * year_predict + b);

    return 0;
}
