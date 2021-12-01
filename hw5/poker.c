// Copyright (c) JacobLinCool
#include "poker.h"
#define CARD_SET_SIZE 13

// if the card is valid, return 1, else return 0
static int8_t validate_card(int8_t card) {
    if (card < 1 || card > 52) {
        return 0;
    }
    return 1;
}

// if card_1 is bigger than card_2, return 1, else return 0
static int8_t compare(int8_t card_1, int8_t card_2) {
    int8_t num_1 = (card_1 + 10) % 13, num_2 = (card_2 + 10) % 13;
    int8_t suit_1 = 4 - (card_1 - 1) / 13, suit_2 = 4 - (card_2 - 1) / 13;
    if (num_1 > num_2) {
        return 1;
    }
    else if (num_1 < num_2) {
        return 0;
    }
    else {
        if (suit_1 > suit_2) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int32_t big_two_sort(int8_t cards[]) {
    // validate the cards
    for (int8_t i = 0; i < CARD_SET_SIZE; i++) {
        if (validate_card(cards[i]) == 0) {
            return -1;
        }
    }

    // sort the cards by ascending order
    for (int8_t i = 0; i < CARD_SET_SIZE - 1; i++) {
        for (int8_t j = i + 1; j < CARD_SET_SIZE; j++) {
            if (compare(cards[i], cards[j]) == 1) {
                int8_t temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }

    return 0;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
