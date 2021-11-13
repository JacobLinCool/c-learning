// Computer Programming I - Midterm Exam #4
// Copyright © 2021 JacobLinCool. All rights reserved.
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

typedef struct Enemy {
    int64_t movement;
    int64_t vision;
    int64_t x;
    int64_t y;
} Enemy;

Enemy enemy1 = { 1, 1, 1, 1 }, enemy2 = { 1, 1, 1, 1 };

int64_t movement = 0, x = 80, y = 20;

char map[20][80];

void setup() {
    printf("Your movement (3-6): ");
    while (scanf("%" SCNd64, &movement) != 1 || movement < 3 || movement > 6) {
        printf("Invalid input!!\n");
        printf("Your movement (3-6): ");
    }
    printf("Enemy 1 movement (3-6): ");
    while (scanf("%" SCNd64, &enemy1.movement) != 1 || enemy1.movement < 3 || enemy1.movement > 6) {
        printf("Invalid input!!\n");
        printf("Enemy 1 movement (3-6): ");
    }
    printf("Enemy 1 vision (2-10): ");
    while (scanf("%" SCNd64, &enemy1.vision) != 1 || enemy1.vision < 2 || enemy1.vision > 10) {
        printf("Invalid input!!\n");
        printf("Enemy 1 vision (2-10): ");
    }
    printf("Enemy 1 location (2-80): ");
    while (scanf("%" SCNd64, &enemy1.x) != 1 || enemy1.x < 2 || enemy1.x > 80) {
        printf("Invalid input!!\n");
        printf("Enemy 1 location (2-80): ");
    }

    printf("Enemy 2 movement (3-6): ");
    while (scanf("%" SCNd64, &enemy2.movement) != 1 || enemy2.movement < 3 || enemy2.movement > 6) {
        printf("Invalid input!!\n");
        printf("Enemy 2 movement (3-6): ");
    }
    printf("Enemy 2 vision (2-10): ");
    while (scanf("%" SCNd64, &enemy2.vision) != 1 || enemy2.vision < 2 || enemy2.vision > 10) {
        printf("Invalid input!!\n");
        printf("Enemy 2 vision (2-10): ");
    }
    printf("Enemy 2 location (2-20): ");
    while (scanf("%" SCNd64, &enemy2.y) != 1 || enemy2.y < 2 || enemy2.y > 20) {
        printf("Invalid input!!\n");
        printf("Enemy 2 location (2-20): ");
    }



    for (int64_t i = 0; i < 20; i++) {
        for (int64_t j = 0; j < 80; j++) {
            map[i][j] = ' ';
        }
    }

    map[enemy1.y - 1][enemy1.x - 1] = '1';
    for (int64_t i = 1; i <= enemy1.vision; i++) {
        if (enemy1.y + i <= 20) {
            for (int64_t j = enemy1.x - i + 1; j <= enemy1.x + i - 1; j++) {
                if (j <= 80 && j >= 1) {
                    map[enemy1.y + i - 1][j - 1] = '*';
                }
            }
        }
        else {
            break;
        }
    }

    map[enemy2.y - 1][enemy2.x - 1] = '2';
    for (int64_t i = 1; i <= enemy2.vision; i++) {
        if (enemy2.x + i <= 80) {
            for (int64_t j = enemy2.y - i + 1; j <= enemy2.y + i - 1; j++) {
                if (j <= 20 && j >= 1) {
                    map[j - 1][enemy2.x + i - 1] = '*';
                }
            }
        }
        else {
            break;
        }
    }
    map[y - 1][x - 1] = 'P';
    map[0][0] = 'S';
}

void print_map() {
    for (int32_t i = 0; i < 82; i++) printf("-");
    printf("\n");

    for (int32_t i = 0; i < 20; i++) {
        printf("|");
        for (int32_t j = 0; j < 80; j++) {
            printf("%c", map[i][j]);
        }
        printf("|\n");
    }

    for (int32_t i = 0; i < 82; i++) printf("-");
    printf("\n");
}

// Main Proccess
int main() {
    setup();
    print_map();

    return 0;
}
