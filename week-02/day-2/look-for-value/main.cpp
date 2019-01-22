#include <iostream>

int findTheValue(int * array, int array_size, int value) {
    int num2 = 0;
    for (int i = 0; i < array_size; i++){
        if (array[i] == value) {
            num2 = i;
            return num2;
        } else {
            num2 = 0;
        }
    }
    return num2;
}

int main()
{
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

    int num;
    std::cout << "How many numbers you want in the array?" << std::endl;
    std::cin >> num;
    int array[num];
    std::cout << "Give me " << num << " numbers" << std::endl;

    for (int i = 0; i < num; i++) {
        std::cin >> array[i];
    }
    int size = sizeof(array) / sizeof(array[0]);
    int *arrayPtr = array;
    int check;
    std::cout << "Which number would you like to check?" << std::endl;
    std::cin >> check;

    findTheValue(arrayPtr, size, check);
    std::cout << findTheValue(arrayPtr, size, check);

    return 0;
}