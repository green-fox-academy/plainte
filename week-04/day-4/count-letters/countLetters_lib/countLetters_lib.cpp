#include "countLetters_lib.h"

std::map<char, int> countLetters(std::string text)
{
    std::map<char, int> charactersOccur;
    for (unsigned int i = 0; i < text.size(); i++){
        if (charactersOccur.find(text.at(i)) != charactersOccur.end() ){
            charactersOccur[text.at(i)] += 1;
        } else charactersOccur.insert(std::make_pair(text.at(i), 1));
    }
    return charactersOccur;
}