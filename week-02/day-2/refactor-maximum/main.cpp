#include <iostream>

void printBiggestNumber(int * array, int array_size) {
    int num = 0;
    for (int i = 0; i < array_size; i++) {
        if (array[i] > num) {
            num = array[i];
        }
    }
    std::cout << num;
}

int readPreferences(int *p_num) {
    std::cout << "How many integers you want in your array?" << std::endl;
    std::cin >> *p_num;

    return *p_num;
}

void readArray(int* array, int num) {
    for (int i = 0; i < num; i++) {
        std::cout << "Please give an integer!" << std::endl;
        std::cin >> array[i];
    }

}

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it
    int num = 0;
    int *p_num = &num;

    readPreferences(p_num);

    int array[num];

    readArray(array, num);

    int array_size = sizeof(array) / sizeof(array[0]);
    int *arrayPtr = array;

    printBiggestNumber(arrayPtr, array_size);

    return 0;
}