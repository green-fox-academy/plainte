#include <iostream>

// Given a string, compute recursively a new string where all the
// adjacent chars are now separated by a '*'.

std::string insertRecursively(std::string x, unsigned int length)
{
    if (length == 0) {
        return x;
    } else {
        x.insert(length - 1, 1, '*');
        return insertRecursively(x, length - 1);
    }

}
int main() {
    std::string stringx = "xer xor or xer and xl osssx";
    unsigned int size = stringx.length();
    std::cout << insertRecursively(stringx, size);

    return 0;
}