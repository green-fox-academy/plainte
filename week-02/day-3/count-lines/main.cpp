#include <iostream>
#include <fstream>
#include <string>

int readFile(std::string& pass) {
    std::ifstream file(pass);
    if (file.is_open()) {
        std::string data;
        int lines = 0;
        while (getline(file, data)) {
            lines++;
        }
        file.close();
        return lines;
    } else {
        return 0;
    }
}

int main() {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
    std::string pass = "my-file.txt";
    std::cout << readFile(pass);
    return 0;
}