#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.
char* concatenate_strings(char* str1, char* str2);

int main()
{
    char *pointer = concatenate_strings("Az en falum", "Balatonszabadi");
    printf("%s", pointer);
    free(pointer);
    return 0;
}

char* concatenate_strings(char* str1, char* str2)
{
    char* ptr;
    int length = strlen(str1) + strlen(str2);
    ptr = (char*) malloc(length * sizeof(char));
    strcpy(ptr, str1);
    strcat(ptr, " ");
    strcat(ptr, str2);
    return ptr;
}