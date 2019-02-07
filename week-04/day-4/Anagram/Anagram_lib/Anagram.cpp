#include <algorithm>
#include "Anagram.h"

bool areAnagram(std::string strExample1, std::string strExample2)
{
    int str1 = strExample1.length();
    int str2 = strExample2.length();

    if (str1 != str2) {
        return false;
    }

    sort(strExample1.begin(), strExample1.end());
    sort(strExample2.begin(), strExample2.end());

    for (int i = 0; i < str1; i++) {
        if (strExample1[i] != strExample2[i]) {
            return false;
        }
    }
    return true;
}