#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int a = 3;
    // make the "a" variable's value bigger by 10
    a += 10;
    std::cout << a << std::endl;

    int b = 100;
    // make b smaller by 7
    b -= 7;
    std::cout << b << std::endl;

    int c = 44;
    // please double c's value
    c *= 2;
    std::cout << c << std::endl;

    int d = 125;
    // please divide by 5 d's value
    d /= 5;
    std::cout << d << std::endl;

    int e = 8;
    // please cube of e's value
    int ed = e * e * e;
    std::cout << ed << std::endl;

    int f1 = 123;
    int f2 = 345;
    // tell if f1 is bigger than f2 (print as a boolean)

    bool asd = false;
    if (f1 < f2) {
        std::cout << asd << std::endl;
    }

    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)
    bool sad = true;
    if ((g2 * 2) > g1) {
        std::cout << sad << std::endl;
    }

    int h = 135798745;
    // tell if it has 11 as a divisor (print as a boolean)
    if (h / 11 > 0) {
        std::cout << asd << std::endl;
    }

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
    if (i1 > (i2 * 2)) {
        std::cout << asd << std::endl;
    }
    if ((i2 * i2 * i2) > i1) {
        std::cout << sad << std::endl;
    }

    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)
    if ((j / 3) > 0) {
        std::cout << sad << std::endl;
    }
    if ((j / 5) > 0) {
        std::cout << asd << std::endl;
    }

    std::string k = "Apple";
    //fill the k variable with its content 4 times
    std::string y = std::string("Apple") + std::string("Apple") + std::string("Apple") + std::string("Apple");

    std::cout << y << std::endl;

    return 0;
}