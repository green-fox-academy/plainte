#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int main()
{
    int a, b;
    printf("Please enter the size of the matrix (two integers)!\n");
    scanf("%d %d", &a, &b);
    int **arr = (int **) malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++) {
        arr[i] = (int *) malloc(b * sizeof(int));
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}