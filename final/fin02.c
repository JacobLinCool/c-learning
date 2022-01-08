// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "go.h"

int32_t board[19][19] = { {0} };

void clear_board() {
    for (int32_t i = 0; i < 19; i++) {
        for (int32_t j = 0; j < 19; j++) {
            board[i][j] = 0;
        }
    }
}

int main() {
    clear_board();
    for (int32_t i = 7; i < 10; i++) {
        for (int32_t j = 7; j < 10; j++) {
            board[i][j] = 1;
        }
    }

    printf("%" PRId32 "\n", max_black_chain(board));

    clear_board();
    for (int32_t i = 7; i < 10; i++) {
        for (int32_t j = 7; j < 10; j++) {
            board[i][j] = 2;
        }
    }

    printf("%" PRId32 "\n", max_black_chain(board));

    clear_board();
    board[0][0] = 1;
    board[1][0] = 1;

    board[18][18] = 1;
    board[17][18] = 1;
    board[18][17] = 1;

    printf("%" PRId32 "\n", max_black_chain(board));

    clear_board();
    board[0][0] = 1;
    board[1][0] = 1;
    board[2][0] = 1;
    board[3][0] = 1;

    board[18][18] = 2;
    board[17][18] = 2;
    board[18][17] = 1;

    printf("%" PRId32 "\n", max_black_chain(board));

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
