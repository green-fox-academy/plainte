#include <stdio.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8
    int number;
    printf("Guess the number!\n");
    scanf("%d", &number);
    int guess_number = 1;
    while (guess_number != 0) {
        if (number < 8) {
            printf("The stored number is higher. Try again!\n");
            scanf("%d", &number);
        } else if (number > 8) {
            printf("The stored number is lower. Try again!\n");
            scanf("%d", &number);
        } else {
            printf("You found the number: %d\n", number);
            guess_number = 0;
        }
    }
    return 0;
}