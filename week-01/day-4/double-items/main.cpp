#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array
    int numList[] = {3, 4, 5, 6, 7};
    int a = sizeof(numList) / sizeof(numList[0]);
    for (int i = 0; i < a; i++) {
        numList[i] *= 2;
        //std::cout << numList[i] << std::endl;
    }
    return 0;
}