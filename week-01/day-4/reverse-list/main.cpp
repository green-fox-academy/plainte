#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
    int aj[] = {3, 4, 5, 6, 7};
    int k = sizeof(aj) / sizeof(aj[0]);
    int temp;
    for (int i = 0; i < k / 2; i++) { // /2 needed -> only k: i=3 its gonna re-reverse the procedure
        temp = aj[i]; // if i=0 temp will be 3      ||
        aj[i] = aj[k-i-1]; // then the first element will be equal with the value of 5-0-1 = 4th element (5th) ||
        aj[k-i-1] = temp; // then the 4th element (5th) will get the value of temp -> 3 ||
    }
    for (int i = 0; i < k; i++) {
        std::cout << aj[i] << " ";
    }

    return 0;
}