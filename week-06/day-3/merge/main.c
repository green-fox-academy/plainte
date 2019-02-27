#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them
int cmpfunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int* pointer = NULL;
    pointer = (int*) malloc(10 * sizeof(int));
    int* pointer2 = NULL;
    pointer2 = (int*) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            int num = rand() % 100;
            if (num % 2 == 0) {
                pointer[i] = num;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            int num = rand() % 100;
            if (num % 2 == 1) {
                pointer2[i] = num;
            }
        }
    }
    int* merged = NULL;
    merged = (int*) malloc(20 * sizeof(int));
    for (int i = 0; i < 20; i++) {
        if ( i < 10) {
            merged[i] = pointer[i];
        } else {
            merged[i] = pointer2[i - 10];
        }
    }
    qsort(merged, 20, sizeof(int), cmpfunc);
    int temp;
    int end = 20 - 1;
    for (int i = 0; i < 20 / 2; i++) {
        temp = merged[i];
        merged[i] = merged[end];
        merged[end] = temp;
        end--;
    }
    for (int j = 0; j < 20; j++) {
        printf("%d ", merged[j]);
    }
    free(pointer);
    free(pointer2);
    free(merged);
    return 0;
}