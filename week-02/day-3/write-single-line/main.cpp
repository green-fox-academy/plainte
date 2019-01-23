#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line
    std::ofstream file;
    file.open("my-file.txt");
    std::string my_name = "Daniel Molnar";
    file << my_name;
    file.close();

    return 0;
}