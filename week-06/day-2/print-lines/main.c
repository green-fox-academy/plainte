#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE *fptr = fopen("../my-file.txt", "w");
    fprintf(fptr, "I like Green Fox!\n");
    fprintf(fptr, "I like World of Warcraft!\n");
    fprintf(fptr, "I love my girlfriend more tho!\n");

    fclose(fptr);

    FILE *filep = fopen("../my-file.txt", "r");
    char line[150];

    while(fgets(line, 150, filep) != NULL) {
        printf("%s", line);
    }
    fclose(filep);

    return 0;
}