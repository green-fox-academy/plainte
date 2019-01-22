#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string todoText = " - Buy milk\n";
    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo

    std::string s1 = "My todo:\n";
    std::string s2 = " - Download games\n";
    std::string s3 = "\t- Diablo";

    todoText.insert(0, s1);
    todoText.append(s2);
    todoText.append(s3);

    std::cout << todoText << std::endl;

    return 0;
}