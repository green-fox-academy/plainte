#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found
void listing(char *array);
void listing2(char *array);

int main ()
{
	char string[55] = "This is a string for testing";
    listing(string);
    listing2(string);
	return 0;
}

void listing(char *array)
{
    //easier version
    int index = 0;
    for (char *p = array; *p != '\0'; p++) {
        index++;
        if (*p == 'i') {
            printf("%d\n", index);
        }
    }
}

void listing2(char *array)
{
    // harder version
    // get last occurrence
    int index = -1;
    for (int i = 0; i < strlen(array); i++) {
        if (array[i] == 'i') {
            index = i;
        }
    }
    //tokenizing
    char *word = strtok(array,"i");
    int count = 0;
    while ( word != NULL) {
        if (count > index) {
            break;
        } else {
        count += strlen(word) + 1 ;
        printf("%d\n", count);
        word = strtok(NULL, "i");
        }
    }
}