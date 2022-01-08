// Copyright (c) JacobLinCool
#include "go.h"

static int32_t get_stone_liberty(int32_t board[][19], int32_t x, int32_t y) {
    int32_t count = 0;

    if (x > 0 && board[y][x - 1] == 0) {
        count++;
        board[y][x - 1] = 4;
    }
    if (x < 18 && board[y][x + 1] == 0) {
        count++;
        board[y][x + 1] = 4;
    }
    if (y > 0 && board[y - 1][x] == 0) {
        count++;
        board[y - 1][x] = 4;
    }
    if (y < 18 && board[y + 1][x] == 0) {
        count++;
        board[y + 1][x] = 4;
    }

    // printf("[%d, %d] %d\n", x, y, count);

    return count;
}

static int32_t find(int32_t board[][19], int32_t x, int32_t y) {
    if (board[y][x] == 0 || board[y][x] == 3 || board[y][x] == 4) return 0;

    int32_t liberty = get_stone_liberty(board, x, y);

    board[y][x] = 3;

    if (x + 1 < 19) liberty += find(board, x + 1, y);
    if (x > 0) liberty += find(board, x - 1, y);
    if (y + 1 < 19) liberty += find(board, x, y + 1);
    if (y > 0) liberty += find(board, x, y - 1);

    return liberty;
}

int32_t max_black_chain(int32_t board[][19]) {
    int32_t max_black_chain = 0;

    for (int32_t i = 0; i < 19; i++) {
        for (int32_t j = 0; j < 19; j++) {
            if (board[i][j] == 1) {
                int32_t liberty = find(board, j, i);
                max_black_chain = liberty > max_black_chain ? liberty : max_black_chain;
            }
        }
    }

    for (int32_t i = 0; i < 19; i++) {
        for (int32_t j = 0; j < 19; j++) {
            if (board[i][j] == 3) {
                board[i][j] = 1;
            }
            if (board[i][j] == 4) {
                board[i][j] = 0;
            }
        }
    }

    return max_black_chain;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
