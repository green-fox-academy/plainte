#include <stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

    int firstNum = 22;
    int secondNum = 13;

    int sum = firstNum + secondNum;
    int sub = firstNum - secondNum;
    int multiplied = firstNum * secondNum;
    float divided = (float)firstNum / (float)secondNum;
    int remainder = firstNum % secondNum;

    printf("The sum of firstNum and secondNum is: %d\n", sum);
    printf("The subtraction of firstNum and secondNum is: %d\n", sub);
    printf("The multiplication of firstNum and secondNum is: %d\n", multiplied);
    printf("The divided decimal fraction of firstNum and secondNum is: %.2f\n", divided);
    printf("The remainder of firstNum and secondNum is: %d\n", remainder);

    return 0;
}