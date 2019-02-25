#include <stdio.h>
#include <stdlib.h>

int oddOrEven(int number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)
    int num;
    printf("Please enter an integer!\n");
    scanf("%d", &num);

    printf("The number is: %d (1 = even, 0 = odd)\n", oddOrEven(num));
    return 0;
}

int oddOrEven(int number)
{
    if (number % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

