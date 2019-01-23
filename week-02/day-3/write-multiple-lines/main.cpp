#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number parameter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"
void writeInFile(std::string& path, std::string& apple, int& lines) {
    std::ofstream appleFile(path);
    int i = 0;
    while (i < lines) {
        appleFile << apple << std::endl;
        i++;
    }
    appleFile.close();
}

int main() {
    std::string path = "./apple.txt";
    std::string apple = "apple";
    int lines = 5;

    writeInFile(path, apple, lines);

    return 0;
}