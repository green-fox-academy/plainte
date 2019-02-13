#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

void parseMethod(const std::string& input, const std::string& output)
{
    std::ifstream inputFile(input);
    std::string line;
    std::string _name;
    std::string _type;
    std::string _date;
    std::vector<std::string> type;
    if (inputFile.is_open()) {
        while (inputFile >> _name >> _type >> _date) {
            type.push_back(_type);
        }
    }
    inputFile.close();

    std::vector<std::string> type2 = type;
    std::sort(type2.begin(), type2.end());
    type2.erase(unique(type2.begin(), type2.end()), type2.end());

    std::vector<std::pair<std::string, int>> usage;
    for (unsigned int i = 0; i < type2.size(); i++) {
        int count = 0;
        for (unsigned int j = 0; j < type.size(); j++) {
            if ( type2[i] == type[j]) {
                count++;
            }
        }
        usage.push_back(make_pair(type2[i], count));
    }
    std::ofstream pureUsage(output);
    pureUsage << "Building usage" << std::endl;
    for (unsigned int i = 0; i < usage.size(); i++) {
        pureUsage  << usage[i].first << ": " << usage[i].second << std::endl;
    }
    pureUsage.close();
}
int main()
{
    //Write a method which can read and parse a file containing information about
    // the frequency of Green Fox Academy students' and mentors' main entrance usage.
    std::string usageInput = "usage.txt";
    std::string usageOutput = "parsedUsage.txt";
    parseMethod(usageInput, usageOutput);

    return 0;
}