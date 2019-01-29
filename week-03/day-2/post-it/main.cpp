#include "PostIt.h"
#include <iostream>

int main(int argc, char * args[]) {
    PostIt PostIt1("orange", "Idea 1", "blue");
    PostIt PostIt2("pink", "Awesome", "black");
    PostIt PostIt3("yellow", "Superb!", "green");

    std::cout << PostIt1.text << std::endl;

    return 0;
}