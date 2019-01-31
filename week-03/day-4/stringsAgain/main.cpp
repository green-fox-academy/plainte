#include <iostream>

// Given a string, compute recursively a new string where all the 'x' chars have been removed.

std::string changeRecursively(std::string x, unsigned int l)
{
    if (l - 1 == -1) {
        return x;
    } else if (x[l - 1] == 'x'){
        x.erase(l - 1, 1);
        return changeRecursively(x, l - 1);
    } else {
        return changeRecursively(x, l - 1);
    }

}
int main() {
    std::string xs = "xer xor or xer and xl osssx";
    unsigned int size = xs.length();
    std::cout << changeRecursively(xs, size);

    return 0;
}