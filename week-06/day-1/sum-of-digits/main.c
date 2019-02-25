#include <stdio.h>
#include <stdlib.h>

int ifEqual(int first, int second);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0
    int num1;
    int num2;
    printf("Please enter two integers!\n");
    scanf("%d %d", &num1, &num2);

    printf("The sum of these numbers digits are: %d (1 = equal, 0 = not equal)\n", ifEqual(num1, num2));

    printf("Please enter two integers again!\n");
    scanf("%d %d", &num1, &num2);

    printf("The sum of these numbers digits are: %d (1 = equal, 0 = not equal)\n", ifEqual(num1, num2));
    return 0;
}

int ifEqual(int first, int second)
{
    int remainder;
    int firstSum = 0;
    int secondSum = 0;
    while (first != 0) {
        remainder = first % 10;
        firstSum += remainder;
        first /= 10;
    }
    while (second != 0) {
        remainder = second % 10;
        secondSum += remainder;
        second /= 10;
    }

    if (firstSum == secondSum) {
        return 1;
    } else {
        return 0;
    }
}