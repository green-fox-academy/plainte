#include "poker.h"

char *isHigher(player_t player1, player_t player2)
{
    int player1_array[5];
    int player2_array[5];
    for (int i = 0; i < 5; i++) {
        player1_array[i] = player1.player_cards[i].value;
        player2_array[i] = player2.player_cards[i].value;
    }
    bubbleSort(player1_array, 5);
    bubbleSort(player2_array, 5);
    for (int i = 0; i < 5; i++) {
        if (player2_array[i] == player2_array[i + 1]) {
            return "White wins!";
        }
    }

    for (int j = 4; j >= 0; j--) {
        if (player1_array[j] > player2_array[j]) {
            return "Black wins!";
        } else if (player1_array[j] < player2_array[j]) {
            return "White wins!";
        }
    }
    return "Tie.";
}

int giveValueToCard(const char *card)
{
    char card_to_use[2];
    strcpy(card_to_use, card);
    int value = atoi(card_to_use);

    if (value > 0) {
        return value;
    } else if (card_to_use[0] == 'T') {
        return 10;
    } else if (card_to_use[0] == 'J') {
        return 11;
    } else if (card_to_use[0] == 'Q') {
        return 12;
    } else if (card_to_use[0] == 'K') {
        return 13;
    } else if (card_to_use[0] == 'A') {
        return 14;
    }
    return value;
}

player_t playerCreator(const char *cardsInHand)
{
    player_t result;
    char cards[20];
    strcpy(cards, cardsInHand);
    char *token;
    for (int i = 0; i < 5; i++) {
        if (i > 0) {
            token = strtok(NULL, " ");
            result.player_cards[i].value = giveValueToCard(token);
            result.player_cards[i].card_type = token[1];
        } else {
            token = strtok(cards, " ");
            result.player_cards[i].value = giveValueToCard(token);
            result.player_cards[i].card_type = token[1];
        }
    }
    return result;
}

void bubbleSort(int arr[], int num)
{
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
