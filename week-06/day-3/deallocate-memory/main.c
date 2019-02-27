#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    srand(time(NULL));
    int* pointer = NULL;

    pointer = (int*) malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            pointer[i] = i;
            printf("%d ", pointer[i]);
        } else {
            pointer[i] = i + 1;
            printf("%d ", pointer[i]);
        }
    }
    realloc(pointer, 20 * sizeof(int));
    return 0;
}