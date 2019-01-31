#include <iostream>

// Given a string, compute recursively (no loops) a new string where all the
// lowercase 'x' chars have been changed to 'y' chars.
std::string changeRecursively(std::string x, int l)
{
    if (l - 1 == -1) {
        return x;
    } else if (x[l - 1] == 'x'){
        x[l - 1] = 'y';
        return changeRecursively(x, l - 1);
    } else {
        return changeRecursively(x, l - 1);
    }

}
int main() {
    std::string xs = "xer xor or xer and xl osssx";
    int size = xs.length();
    std::cout << changeRecursively(xs, size);

    return 0;
}