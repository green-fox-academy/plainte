#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* pointer = NULL;
    int a;
    int b;
    printf("Please enter a number.\n");
    scanf("%d", &a);
    pointer = (int*) malloc(a * sizeof(int));
    printf("Please enter another number.\n");
    scanf("%d", &b);
    int c = a + b;
    pointer = (int*) realloc(pointer, c * sizeof(int));
    for (int i = 1; i <= c; i++) {
        pointer[i] = i;
        printf("%d ", pointer[i]);
    }
    free(pointer);

    return 0;
}