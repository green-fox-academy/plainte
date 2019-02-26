#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"
void write_multiple_lines(const char *path, const char *word, int number);

int main()
{
    write_multiple_lines("../my-file.txt", "apple", 5);
    return 0;
}

void write_multiple_lines(const char *path, const char *word, int number)
{
    char to_be_printed[50];
    strcpy(to_be_printed, word);
    char *new_line = "\n";
    strcat(to_be_printed, new_line);
    FILE *fptr = fopen(path, "w");
    for (int i = 0; i < number; i++) {
        fputs(to_be_printed, fptr);
    }
    fclose(fptr);

    fptr = fopen(path, "r");
    char line[150];
    while(fgets(line, 150, fptr) != NULL) {
        printf("%s", line);
    }
}