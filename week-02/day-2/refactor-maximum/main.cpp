#include <iostream>

int biggestNumber(int const * array, int array_size) {
    int x_num = 0;
    for (int i = 0; i < array_size; i++) {
        if (array[i] > x_num) {
            x_num = array[i];
        }
    }
    return x_num;
}

void print(int x_num) {
    std::cout << x_num;
}

int readPreferences() {
    int p_num = 0;
    std::cout << "How many integers you want in your array?" << std::endl;
    std::cin >> p_num;

    return p_num;
}

void readArray(int  * array, int num) {
    for (int i = 0; i < num; i++) {
        std::cout << "Please give an integer!" << std::endl;
        std::cin >> array[i];
    }

}

int main()
{
    // Refactor time!
    // use your 'refactor_maximum.cpp', solve the same exercise by creating a separate function
    // for each functionality


    int num = readPreferences();

    int array[num];

    readArray(array, num);

    int array_size = sizeof(array) / sizeof(array[0]);
    int *arrayPtr = array;

    int x_num = biggestNumber(arrayPtr, array_size);
    print(x_num);



    return 0;
}