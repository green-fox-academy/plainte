#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_sentence(char *string1, char *string2);

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return the index of the word in the sentence and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "doctor";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 6
    printf("%d", is_in_sentence(word, sentence));

    return 0;
}

int is_in_sentence(char *string1, char *string2)
{
    char word[100];
    char sentence[100];
    strcpy(word, string1);
    strcpy(sentence, string2);
    // converting to lowercase
    int i = 0;
    while (word[i] != '\0') {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += 32;
        }
        i++;
    }
    while (sentence[i] != '\0') {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z') {
            sentence[i] += 32;
        }
        i++;
    }

    int count = 0;

    for (int j = 0; sentence[j] != '\0'; j++) {
        if (sentence[j] == ' ') {
            count++;
        } else if (sentence[j] == word[0]) {
            int boolean = 1;
            int newJ = j;

            for (int k = 0; k < strlen(word); k++) {
                if (sentence[newJ] != word[k]) {
                    boolean = 0;
                    break;
                }
                newJ++;
            }
            if (boolean == 1) {
                return count;
            }
        }
    }
    return 0;
}