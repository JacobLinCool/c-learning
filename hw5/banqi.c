// Copyright (c) JacobLinCool
#include "banqi.h"
#define DEBUG 0

static void init_chess_set(Chess chess[32]) {
    for (size_t i = 0; i < 2; i++) {
        // GENERAL
        for (size_t j = 0; j < 1; j++) {
            chess[i * 16 + j].color = i;
            chess[i * 16 + j].type = (TYPE)GERERAL;
            chess[i * 16 + j].hidden = 1;
        }
        // ADVISOR
        for (size_t j = 1; j < 3; j++) {
            chess[i * 16 + j].color = i;
            chess[i * 16 + j].type = (TYPE)ADVISOR;
            chess[i * 16 + j].hidden = 1;
        }
        // ELEPHANT
        for (size_t j = 3; j < 5; j++) {
            chess[i * 16 + j].color = i;
            chess[i * 16 + j].type = (TYPE)ELEPHANT;
            chess[i * 16 + j].hidden = 1;
        }
        // CHARIOT
        for (size_t j = 5; j < 7; j++) {
            chess[i * 16 + j].color = i;
            chess[i * 16 + j].type = (TYPE)CHARIOT;
            chess[i * 16 + j].hidden = 1;
        }
        // HORSE
        for (size_t j = 7; j < 9; j++) {
            chess[i * 16 + j].color = i;
            chess[i * 16 + j].type = (TYPE)HORSE;
            chess[i * 16 + j].hidden = 1;
        }
        // CANNON
        for (size_t j = 9; j < 11; j++) {
            chess[i * 16 + j].color = i;
            chess[i * 16 + j].type = (TYPE)CANNON;
            chess[i * 16 + j].hidden = 1;
        }
        // SOLDIER
        for (size_t j = 11; j < 16; j++) {
            chess[i * 16 + j].color = i;
            chess[i * 16 + j].type = (TYPE)SOLDIER;
            chess[i * 16 + j].hidden = 1;
        }
    }

    return;
}

static void shuffle_chess_set(Chess chess[32]) {
    srand(time(NULL));

    for (size_t i = 0; i < 32; i++) {
        size_t j = rand() % 32;
        Chess tmp = chess[i];
        chess[i] = chess[j];
        chess[j] = tmp;
    }

    return;
}

static char get_chess_name(Chess chess) {
    if (chess.color == BLACK) {
        switch (chess.type) {
        case GERERAL:
            return '1';
        case ADVISOR:
            return '2';
        case ELEPHANT:
            return '3';
        case CHARIOT:
            return '4';
        case HORSE:
            return '5';
        case CANNON:
            return '6';
        case SOLDIER:
            return '7';
        default:
            return ' ';
        }
    }
    else {
        switch (chess.type) {
        case GERERAL:
            return 'A';
        case ADVISOR:
            return 'B';
        case ELEPHANT:
            return 'C';
        case CHARIOT:
            return 'D';
        case HORSE:
            return 'E';
        case CANNON:
            return 'F';
        case SOLDIER:
            return 'G';
        default:
            return ' ';
        }
    }
}

Board create_board() {
    Board board;

    Chess chess[32];
    init_chess_set(chess);
    shuffle_chess_set(chess);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            board.grid[i][j] = chess[i * 8 + j];
        }
    }

    return board;
}

void print_board(Board* board) {
    printf("  1 2 3 4 5 6 7 8  \n");
    printf(" +---------------+ \n");

    for (int8_t i = 0; i < 4; i++) {
        printf("%" PRId8 "|", i + 1);
        for (int8_t j = 0; j < 8; j++) {
            if (board->grid[i][j].hidden) {
                printf("%c|", '*');
            }
            else {
                printf("%c|", get_chess_name(board->grid[i][j]));
            }
        }
        printf("\n");
        if (i != 3) printf(" |---------------| \n");
    }

    printf(" +---------------+ \n");

    return;
}

void player_move(Board* board, int8_t player) {
    while (1) {
        printf("%s (x,y): ", board->player[player].name);
        int8_t x, y;
        scanf("%" SCNd8 ",%" SCNd8, &x, &y);

        if (y < 1 || y > 4 || x < 1 || x > 8) {
            printf("Out of area!\n");
            continue;
        }

        if (board->grid[y - 1][x - 1].hidden == 1) {
            board->grid[y - 1][x - 1].hidden = 0;

            if (board->player[player].color == NONE && board->player[!player].color == NONE) {
                board->player[player].color = board->grid[y - 1][x - 1].color;
                board->player[!player].color = !board->grid[y - 1][x - 1].color;

                if (DEBUG) {
                    printf("[DEBUG] Assigned Color %d To Player %s\n", board->player[player].color, board->player[player].name);
                    printf("[DEBUG] Assigned Color %d To Player %s\n", board->player[!player].color, board->player[!player].name);
                }
            }

            break;
        }
        else {
            if (board->player[player].color != board->grid[y - 1][x - 1].color) {
                printf("Not your chess!\n");
                continue;
            }

            int8_t direction[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
            int8_t can_move = 0;
            for (int8_t i = 0; i < 4; i++) {
                int8_t x_tmp = x + direction[i][0], y_tmp = y + direction[i][1];

                if (y_tmp < 1 || y_tmp > 4 || x_tmp < 1 || x_tmp > 8) {
                    continue;
                }

                if (board->grid[y_tmp - 1][x_tmp - 1].hidden == 1) {
                    continue;
                }

                if (board->grid[y_tmp - 1][x_tmp - 1].color == board->player[player].color) {
                    continue;
                }

                if (board->grid[y_tmp - 1][x_tmp - 1].color == board->player[!player].color && board->grid[y_tmp - 1][x_tmp - 1].type < board->grid[y - 1][x - 1].type) {
                    continue;
                }

                can_move = 1;
                break;
            }

            if (!can_move) {
                printf("No place to move!\n");
                continue;
            }

            int8_t to_x, to_y;
            while (1) {
                printf("To (x,y): ");
                scanf("%" SCNd8 ",%" SCNd8, &to_x, &to_y);

                if (to_y < 1 || to_y > 4 || to_x < 1 || to_x > 8) {
                    printf("Out of area!\n");
                    continue;
                }

                if (to_x - x > 1 || x - to_x > 1 || to_y - y > 1 || y - to_y > 1) {
                    printf("Can't move more than one step!\n");
                    continue;
                }

                if (board->grid[to_y - 1][to_x - 1].hidden == 1) {
                    printf("Can't move to this place!\n");
                    continue;
                }

                if (board->grid[to_y - 1][to_x - 1].color == board->player[player].color) {
                    printf("Can't eat your own chess!\n");
                    continue;
                }

                if (board->grid[to_y - 1][to_x - 1].color == board->player[!player].color && board->grid[to_y - 1][to_x - 1].type < board->grid[y - 1][x - 1].type) {
                    printf("Can't eat greater chess!\n");
                    continue;
                }

                board->grid[to_y - 1][to_x - 1].type = board->grid[y - 1][x - 1].type;
                board->grid[to_y - 1][to_x - 1].color = board->grid[y - 1][x - 1].color;

                break;
            }

            board->grid[y - 1][x - 1].type = EMPTY;
            board->grid[y - 1][x - 1].color = NONE;

            break;
        }
    }
}

int8_t game_over(Board* board) {
    int8_t red_alive = 0, black_alive = 0;

    for (int8_t i = 0; i < 4; i++) {
        for (int8_t j = 0; j < 8; j++) {
            if (board->grid[i][j].color == RED) {
                red_alive++;
            }
            else if (board->grid[i][j].color == BLACK) {
                black_alive++;
            }
        }
    }

    if (red_alive == 0) {
        printf("Black win!\n");
        return 1;
    }
    else if (black_alive == 0) {
        printf("Red win!\n");
        return 1;
    }
    else {
        return 0;
    }
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
