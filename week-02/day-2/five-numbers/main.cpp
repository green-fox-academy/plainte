#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again
    int num = 5;
    std::cout << "Give me 5 numbers" << std::endl;
    int array[num];
    for (int i = 0; i < num; i++) {
        std::cin >> array[i];
    }

    int *p_array = array;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        std::cout << *(p_array + i) << " ";
    }

    return 0;
}