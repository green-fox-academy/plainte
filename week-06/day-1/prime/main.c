#include <stdio.h>
#include <stdlib.h>

int ifPrime(int number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)
    int num;
    printf("Please enter an integer!\n");
    scanf("%d", &num);

    printf("The number you've given is: %d (1 = prime number, 0 = not prime number)", ifPrime(num));
    return 0;
}

int ifPrime(int number)
{
    if (number <= 1) {
        return 0;
    }
    int flag = 0;
    for (int i = 2; i < number / 2; i++) {
        if ((number % i) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        return 1;
    } else {
        return 0;
    }
}