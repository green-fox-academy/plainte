#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output
    int a, b;
    std::cout << "Enter the sizes of array!" << std::endl;
    std::cin >> a >> b;
    int i, j;
    int array[a][b];

    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            if (i == j) {
                array[i][j] = 1;
            } else{
                array[i][j] = 0;
            }
        }
    }
    std::cout << std::endl;
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
        std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}