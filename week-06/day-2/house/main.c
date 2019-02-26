#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/
#define FALSE 0
#define TRUE 1
typedef struct house
{
    char address[100];
    float price;
    int rooms;
    float area;
} house_t;

int is_it_worth(house_t *h);

int how_many_worth_to_buy(house_t h[], int length);

int main()
{

    house_t houses[4];
    houses[0].price = 1000000;
    houses[0].area = 20;
    houses[1].price = 10000;
    houses[1].area = 20;
    houses[2].price = 800000;
    houses[2].area = 10;
    houses[3].price = 9000;
    houses[3].area = 100;
    int length = sizeof(houses) / sizeof(*houses);

    printf("That many houses worth to buy: %d\n", how_many_worth_to_buy(houses, length));

    return 0;
}

int is_it_worth(house_t *h)
{
    float market_price = 400;
    float house_price = h->price / h->area;
    if (market_price > house_price) {
        return TRUE;
    }
    return FALSE;
}

int how_many_worth_to_buy(house_t h[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (is_it_worth(&h[i])) {
            count++;
        }
    }
    return count;
}