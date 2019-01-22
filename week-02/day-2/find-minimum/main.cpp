#include <iostream>

int minimumValuePtr (int *array, int size) {
    int *ptr = nullptr;
    int smallest = array[0];
    for (int i = 0; i < size; i++) {
        if (smallest > array[i]) {
            smallest = array[i];
        }

    }
    ptr = &smallest;
    return *ptr;
}
int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    minimumValuePtr(numbers, size);
    std::cout << minimumValuePtr(numbers,size);

    return 0;
}