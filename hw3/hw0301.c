#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const int DEBUG = 0;

int32_t calc_padding(int64_t n) {
    int64_t padding = 1;
    while (n /= 10) padding++;
    return padding;
}

void print_tornado(int64_t height, int64_t width) {
    int64_t max = height * width;
    int32_t padding = calc_padding(max);
    int64_t tornado[height][width];

    if (DEBUG) printf("[DEBUG] size of tornado: %" PRId64 "\n", sizeof(tornado));

    // put numbers into tornado in a counter-clockwise direction
    int64_t x = 0, y = 0, direction = 0, level = 0;
    for (int64_t i = 0; i < max; i++) {
        tornado[y][x] = i + 1;

        // move to the next position
        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else if (direction == 3) x--;

        // check if we need to change the direction
        if (direction == 0 && y == height - level - 1) direction = 1;
        else if (direction == 1 && x == width - level - 1) direction = 2;
        else if (direction == 2 && y == level) direction = 3;
        else if (direction == 3 && x == level + 1) direction = 4;

        // check if we need to upgrade the level
        if (direction == 4) {
            direction = 0;
            level++;
        }
    }

    // print the tornado
    for (int64_t i = 0; i < height; i++) {
        for (int64_t j = 0; j < width; j++) {
            printf("%*" PRId64 " ", padding, tornado[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int64_t width = 0, height = 0;

    printf("Please enter the width  : ");
    if (scanf("%" SCNd64, &width) != 1 || width <= 0) {
        printf("Invalid Input. Received: %" PRId64 "\n", width);
        return 1;
    }

    printf("Please enter the height : ");
    if (scanf("%" SCNd64, &height) != 1 || height <= 0) {
        printf("Invalid Input. Received: %" PRId64 "\n", height);
        return 1;
    }

    print_tornado(height, width);

    return 0;
}