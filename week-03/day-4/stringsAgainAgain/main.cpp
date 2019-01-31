#include <iostream>

// Given a string, compute recursively a new string where all the 'x' chars have been removed.

std::string changeRecursively(std::string x, unsigned int length)
{   char k = '*';
    if (length == 0) {
        return x;
    } else if (x[length - 1] == 'x'){
        x.erase(length - 1, 1);
        return changeRecursively(x, length - 1);
    } else {
        return changeRecursively(x, length - 1);
    }

}
int main() {
    std::string stringx = "xer xor or xer and xl osssx";
    unsigned int size = stringx.length();
    std::cout << changeRecursively(stringx, size);

    return 0;
}