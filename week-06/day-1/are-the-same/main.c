#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(char * str1, char * str2);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.
    char str1[100];
    char str2[100];
    printf("Please enter two strings!\n");
    scanf("%s %s", str1, str2);

    if (compareStrings(str1, str2) == 1) {
        printf("The two strings you've entered are equal!\n");
    } else {
        printf("The two strings you've entered are not equal!\n");
    }
    return 0;
}

int compareStrings(char *str1, char *str2)
{
    if (stricmp(str1, str2) == 0) {
        return 1;
    }
    return 0;
}
