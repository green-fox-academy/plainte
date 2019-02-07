#include <gtest/gtest.h>
#include "countLetters_lib.h"
#include <map>
#include <string>

TEST(TestCountMethod, LettersOccursMatchLetters)
{
    std::map <char, int> testMap = countLetters("almafa");
    ASSERT_EQ(testMap['a'], 3);
}

TEST(TestCountMethod2, LettersOccursMatchLetters2)
{
    std::map <char, int> testMap;
    testMap.insert(std::make_pair('s', 3));
    testMap.insert(std::make_pair('y', 1));
    testMap.insert(std::make_pair('l', 2));
    testMap.insert(std::make_pair('a', 1));
    testMap.insert(std::make_pair('b', 1));
    testMap.insert(std::make_pair('u', 1));

    ASSERT_EQ(countLetters("syllabusS"), testMap);
}