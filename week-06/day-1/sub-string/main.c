#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substring(char *string1, char *string2);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same length than the function should return -1
    char str1[100];
    char str2[100];
    printf("Please enter two strings!\n");
    scanf("%s %s", str1, str2);

    printf("%d ( -1 = same length, 1 = substring, 0 = isn't a substring)", substring(str1, str2));

    return 0;
}

int substring(char *string1, char *string2)
{
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    if (length1 == length2) {
        return -1;
    }
    if (length1 < length2) {
        if (strstr(string2,string1) != NULL) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (strstr(string1, string2) != NULL) {
            return 1;
        } else {
            return 0;
        }
    }
}