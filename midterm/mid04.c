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
    int64_t direction;
} Enemy;

Enemy enemy1 = { 1, 1, 1, 1, 0 }, enemy2 = { 1, 1, 1, 1, 0 };

int64_t movement = 0, x = 80, y = 20, die = 0;

char map[20][80];

void build_map() {
    for (int64_t i = 0; i < 20; i++) {
        for (int64_t j = 0; j < 80; j++) {
            map[i][j] = ' ';
        }
    }

    map[enemy1.y - 1][enemy1.x - 1] = '1';
    for (int64_t i = 1; i <= enemy1.vision; i++) {
        if (enemy1.y + (enemy1.direction ? -i : i) <= 20) {
            for (int64_t j = enemy1.x - i + 1; j <= enemy1.x + i - 1; j++) {
                if (j <= 80 && j >= 1) {
                    if (map[enemy1.y + (enemy1.direction ? -i : i) - 1][j - 1] == 'P') {
                        die = 1;
                    }
                    map[enemy1.y + (enemy1.direction ? -i : i) - 1][j - 1] = '*';
                }
            }
        }
        else {
            break;
        }
    }

    map[enemy2.y - 1][enemy2.x - 1] = '2';
    for (int64_t i = 1; i <= enemy2.vision; i++) {
        if (enemy2.x + (enemy2.direction ? -i : i) <= 80) {
            for (int64_t j = enemy2.y - i + 1; j <= enemy2.y + i - 1; j++) {
                if (j <= 20 && j >= 1) {
                    if (map[j - 1][enemy2.x + (enemy2.direction ? -i : i) - 1] == 'P') {
                        die = 1;
                    }
                    map[j - 1][enemy2.x + (enemy2.direction ? -i : i) - 1] = '*';
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
}

void print_map() {
    build_map();
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

void player_control() {
    int64_t move = 0;
    printf("Move: (1) Up (2) Down? ");
    while (scanf("%" SCNd64, &move) != 1 || move < 1 || move > 2) {
        printf("Invalid input!!\n");
        printf("Move: (1) Up (2) Down? ");
    }

    int64_t range = -1;
    printf("Range (0-%" PRId64 ")? ", movement);
    while (scanf("%" SCNd64, &range) != 1 || range < 0 || range > movement || y + (move == 2 ? range : -range) > 20 || y + (move == 2 ? range : -range) < 1) {
        printf("Invalid input!!\n");
        printf("Range (0-%" PRId64 ")? ", movement);
    }

    int64_t move2 = 0;
    printf("Move: (1) Left (2) Right? ");
    while (scanf("%" SCNd64, &move2) != 1 || move2 < 1 || move2 > 2) {
        printf("Invalid input!!\n");
        printf("Move: (1) Left (2) Right? ");
    }

    int64_t range2 = -1;
    printf("Range (0-%" PRId64 ")? ", movement);
    while (scanf("%" SCNd64, &range2) != 1 || range2 < 0 || range2 > movement || x + (move2 == 2 ? range2 : -range2) > 80 || x + (move2 == 2 ? range2 : -range2) < 1) {
        printf("Invalid input!!\n");
        printf("Range (0-%" PRId64 ")? ", movement);
    }

    y = y + (move == 2 ? range : -range);
    x = x + (move2 == 2 ? range2 : -range2);
}

void enemy_controls() {
    // enemy1
    if (enemy1.direction) {
        enemy1.y -= enemy1.movement;
    }
    else {
        enemy1.y += enemy1.movement;
    }
    if (enemy1.y + (enemy1.direction ? -enemy1.vision : enemy1.vision) < 1 || enemy1.y + (enemy1.direction ? -enemy1.vision : enemy1.vision) > 20) {
        enemy1.direction = !enemy1.direction;
    }

    // enemy2
    if (enemy2.direction) {
        enemy2.x -= enemy2.movement;
    }
    else {
        enemy2.x += enemy2.movement;
    }
    if (enemy2.x + (enemy2.direction ? -enemy2.vision : enemy2.vision) < 1 || enemy2.x + (enemy2.direction ? -enemy2.vision : enemy2.vision) > 80) {
        enemy2.direction = !enemy2.direction;
    }
}

// Main Proccess
int main() {
    setup();
    print_map();

    while (1) {
        player_control();
        if (y == 1 && x == 1) {
            printf("Mission Complete!\n");
            return 0;
        }
        print_map();
        enemy_controls();
        print_map();
        if (die) {
            printf("Mission Fail!\n");
            return 0;
        }
    }


    return 0;
}
