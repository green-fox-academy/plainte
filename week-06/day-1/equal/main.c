#include <stdio.h>
#include <stdlib.h>

int ifEqual(int a, int b);

int main()
{
    // Create a program which asks for two integers and stores them separately
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise
    int a, b;
    printf("Please enter two integers!\n");
    scanf("%d %d", &a, &b);

    printf("The numbers are: %d (1 = equal, 0 = not equal)\n", ifEqual(a, b));

    return 0;
}

int ifEqual(int a, int b)
{
    if (a == b) {
        return 1; //true
    } else {
        return 0; //false
    }
}