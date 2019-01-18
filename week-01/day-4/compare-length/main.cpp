#include <iostream>
#include <string>
/*  experimental
    bool isAGreaterThanB(int y[], int s[]){
    int a = sizeof(y) / sizeof(y[0]);
    int b = sizeof(s) / sizeof(s[0]);
    if (a > b) {
        return true;
    }
} */
int main(int argc, char* args[]) {

    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`
    int p1[] = {1, 0, 3};
    int p2[] = {4, 5};
    int a = 0;
    int b = 0;

    a = sizeof(p1) / sizeof(p1[0]);
    b = sizeof(p2) / sizeof(p2[0]);
    if (b > a) {
        std::cout << "p2 has more elements than p1" << std::endl;
    } else {
        std::cout << "p2 has less elements than p1" << std::endl;
    }

    /* experimental project with bool
    if (isAGreaterThanB(p1, p2)) {
        std::cout << "p2 has more elements than p1" << std::endl;
    } else {
        std::cout << "p2 has less elements than p1" << std::endl;
    return 0;
    */
    return 0;
}