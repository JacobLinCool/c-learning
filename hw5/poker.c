// Copyright (c) JacobLinCool
#include "poker.h"
#define FULL_SET_SIZE 52
#define CARD_SET_SIZE 13

// check if all cards are different
int validate_cards(int8_t cards[]) {
    int8_t full_set[FULL_SET_SIZE + 1] = { 0 };

    for (int8_t i = 0; i < CARD_SET_SIZE; i++) {
        if (cards[i] < 1 || cards[i] > FULL_SET_SIZE) {
            return 0;
        }
        if (full_set[cards[i]]) {
            return 0;
        }
        full_set[cards[i]] = 1;
    }

    return 1;
}

// if card_1 is bigger than card_2, return 1, else return 0
static int8_t compare(int8_t card_1, int8_t card_2) {
    int8_t num_1 = (card_1 + 10) % CARD_SET_SIZE, num_2 = (card_2 + 10) % CARD_SET_SIZE;
    int8_t suit_1 = 4 - (card_1 - 1) / CARD_SET_SIZE, suit_2 = 4 - (card_2 - 1) / CARD_SET_SIZE;

    if (num_1 > num_2) {
        return 1;
    }
    else if (num_1 < num_2) {
        return 0;
    }

    if (suit_1 > suit_2) {
        return 1;
    }
    else {
        return 0;
    }
}

// swap two cards
static void swap(int8_t* card_1, int8_t* card_2) {
    int8_t temp = *card_1;
    *card_1 = *card_2;
    *card_2 = temp;
}

int32_t big_two_sort(int8_t cards[]) {
    // validate the cards
    if (validate_cards(cards) == 0) {
        return -1;
    }

    // sort the cards by ascending order
    for (int8_t i = 0; i < CARD_SET_SIZE - 1; i++) {
        for (int8_t j = i + 1; j < CARD_SET_SIZE; j++) {
            if (compare(cards[i], cards[j]) == 1) {
                swap(&cards[i], &cards[j]);
            }
        }
    }

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
