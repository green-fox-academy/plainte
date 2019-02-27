#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.
char* repeating_input_char(char* input, int num);

int main()
{
    char* repeatition = repeating_input_char("Apple", 5);
    printf("%s", repeatition);
    free(repeatition);
    return 0;
}

char* repeating_input_char(char* input, int num)
{
    char* will_return;
    will_return = (char*) malloc(50 * sizeof(char));
    for (int i = 0; i < num; i++) {
        strcat(will_return, input);
    }
    return will_return;
}