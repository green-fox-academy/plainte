#include <stdio.h>
#include <stdlib.h>

// with calloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits
// what's the difference between this and the previous excersice?

int main()
{
    int* pointer = NULL;
    pointer = (int*) calloc(10, sizeof(int));

    if (pointer == NULL) {
        printf("Memory not allocated.\n");
    }
    printf("Memory has been successfully allocated.\n");
    for (int i = 0; i < 10; i++) {
        pointer[i] = rand() % 5;
        printf("%d ", pointer[i]);
    }

    free(pointer);

    return 0;
}