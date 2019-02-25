#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(const char *string);

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d", count_between_chars(word));

    return 0;
}

int count_between_chars(const char *string)
{
    int num = 0;
    int count = 0;
    char repeatedChar = 'g';
    for (int i = 0; string[i]; i++) {
        if (string[i] == repeatedChar) {
            num = i + 1;
            break;
        }
    }
    for (; string[num] != '\0'; num++) {
        if (string[num] == repeatedChar) {
            return count;
        }
        count = count + 1;
    }
    return -1;
}