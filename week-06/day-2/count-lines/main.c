#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file
int count_lines(char *file_name);

int main ()
{
    printf("%d lines found in that file!\n", count_lines("../../print-lines/my-file.txt"));
    return 0;
}

int count_lines(char *file_name)
{
    FILE *fptr = fopen(file_name, "r");
    int ch = 0;
    int lines = 0;

    if (fptr == NULL) {
        return 0;
    }
    while(!feof(fptr)) {
        ch = fgetc(fptr);
        if (ch == '\n') {
            lines++;
        }
    }
    return lines;
}