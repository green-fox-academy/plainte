#ifndef POKER_GAME_POKER_H
#define POKER_GAME_POKER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char card_type;
    int value;
} card_t;

typedef struct
{
    card_t player_cards[5];
} player_t;

player_t playerCreator(const char *cardsInHand);

char *isHigher(player_t player1, player_t player2);

int giveValueToCard(const char *card);

void bubbleSort(int arr[], int num);

void swap(int *xp, int *yp);

#endif //POKER_GAME_POKER_H
