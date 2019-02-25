#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charOccurredAt(char *string, char ch);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //
    char c;
    char str[100];
    printf("Please enter a string and a character!\n");
    scanf("%s %c", str, &c);

    printf("The character occurred at: %d(-1 it did not occur)\n", charOccurredAt(str, c));
    return 0;
}

int charOccurredAt(char *string, char ch)
{
    char * ptr;
    int index;

    ptr = strchr(string, ch);

    if ( ptr == NULL) {
        return -1;
    } else {
        index = ptr - string;
        return index;
    }
}