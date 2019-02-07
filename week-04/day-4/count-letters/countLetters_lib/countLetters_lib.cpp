#include <algorithm>
#include "countLetters_lib.h"

std::map<char, int> countLetters(std::string text)
{
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::map<char, int> mapC;
    for (unsigned int i = 0; i < text.size(); i++){
        char c = text.at(i);
        if (mapC.find(c) != mapC.end() ){
            mapC[c] += 1;
        } else {
            mapC.insert(std::make_pair(c, 1));
        }
    }
    return mapC;
}