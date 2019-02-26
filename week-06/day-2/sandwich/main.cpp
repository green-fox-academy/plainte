#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/
typedef struct
{
    char name[25];
    float price;
    float weight;
} sandwich_t;

float price_of_order(sandwich_t s, int number_of_sandwiches);

int main()
{
    sandwich_t sandwich1;
    sandwich1.price = 1.5;
    printf("The total price is: %.2f\n", price_of_order(sandwich1, 5));
    return 0;
}

float price_of_order(sandwich_t s, int number_of_sandwiches)
{
    return s.price * number_of_sandwiches;
}
