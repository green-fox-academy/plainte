#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful
bool copy(const std::string& original,const std::string& copied) {
    bool status = true;

    std::ifstream copyThis(original);
    std::ofstream copyIntoThis(copied);
    std::string temp;

    while (getline(copyThis, temp)) {
        copyIntoThis << temp << std::endl;
    }
    copyThis.close();
    copyIntoThis.close();

    std::string temp2;
    std::ifstream test(copied);
    while (getline(test, temp2)) {
    }

    for (unsigned int j = 0; j < temp.size(); j++) {
        if (temp2[j] == temp[j]) {
            if (j == temp.size()) {
                status = false;
            }
        }
    }
    return status;
}
int main() {
    std::string original = "from.txt";
    std::string copied = "to.txt";
    if (copy(original, copied)) {
        std::cout << "Copy was successful";
    } else {
        std::cout << "Copy wasn't successful";
    }

    return 0;
}