#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits


int main()
{
    int* pointer = NULL;
    int n = 10;
    pointer = (int*) malloc(n * sizeof(int));

    if (pointer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("Memory has been successfully allocated using malloc.\n");

    for (int i = 0; i < n; i++) {
        pointer[i] = rand() % 5;
        printf("%d ", pointer[i]);
    }

    free(pointer);


    return 0;
}