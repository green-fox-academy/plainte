#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end
    std::string animals[3] = {"koal", "pand", "zebr"};
    std::string a = "a";
    int i = 0;
    while (i < 3) {
        animals[i] += a;
        //std::cout << animals[i] << std::endl;
        i++;
    }
    return 0;
}