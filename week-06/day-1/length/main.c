#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthWithoutStringh(const char * name);

int lengthWithStringh(const char * name);

int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions
    char name[20];
    int count;
    printf("Hello! What is your name?\n");
    scanf("%s", name);

    for (count = 0; name[count] != '\0'; count++);
    printf("Your name is %d characters long.\n", lengthWithoutStringh(name)); //for loop
    printf("Your name is %d characters long.\n", lengthWithStringh(name)); //string.h

    return 0;
}

int lengthWithoutStringh(const char * name)
{
    int count;
    for (count = 0; name[count] != '\0'; count++);
    return count;
}

int lengthWithStringh(const char * name)
{
    return strlen(name);
}