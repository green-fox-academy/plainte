#include <iostream>

// Create a recursive function called `refactorio`
// that returns it's input's factorial
int refactorio(int num)
{
    if (num <= 1) {
        return 1;
    } else {
        return num * refactorio(num - 1);
    }
}

int main()
{
    try {
        int num;
        std::cout << "Give me a number!" << std::endl;
        std::cin >> num;
        if (num < 0) {
            throw -1;
        } else {
            std::cout << refactorio(num) << std::endl;
        }
    } catch (...) {
        std::cout << "Not positive integer!";
    }
    return 0;
}