#include <iostream>
#include <fstream>
#include <string>


int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
    try {
        std::ifstream file;
        file.open("my-file.txt");
        if(file.is_open()) {
            std::string data;
            int lines = 0;
            while (getline(file, data)) {
                lines++;
            }
            std::cout << lines;
            file.close();
        } else {
            throw 0;
        }
    } catch (...) {
        std::cout << "zero";
    }

    return 0;
}