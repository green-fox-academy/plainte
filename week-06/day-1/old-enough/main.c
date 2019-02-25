#include <stdio.h>
#include <stdlib.h>

int ifOldEnough(int age);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary
    int age;
    printf("Please enter your age!\n");
    scanf("%d", &age);

    printf("%d", ifOldEnough(age));
    return 0;
}

int ifOldEnough(int age)
{
    if (age > 17) {
        printf("Congrats, you can buy alcohol in Hungary!\n");
        return age;
    } else {
        printf("Sorry, you aren't old enough to buy alcohol in Hungary!\n");
        return -1;
    }
}