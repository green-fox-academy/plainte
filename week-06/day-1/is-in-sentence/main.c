#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_sentence(char *string1, char *string2);

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "apple";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 1
    printf("%d (1 = contains, 0 = not contains)", is_in_sentence(word, sentence));

    return 0;
}

int is_in_sentence(char *string1, char *string2)
{
    char str1[100];
    char str2[100];
    strcpy(str1, string1);
    strcpy(str2, string2);

    int i = 0;
    while (str1[i] != '\0') {
        if(str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] += 32;
        }
        i++;
    }
    while (str2[i] != '\0') {
        if(str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] += 32;
        }
        i++;
    }
    char *ptr = strstr(str2, str1);
    if (ptr != NULL) {
        return 1;
    }

    return 0;
}