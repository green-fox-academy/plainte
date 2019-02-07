#include <gtest/gtest.h>
#include "countLetters_lib.h"
#include <map>
#include <string>

TEST(TestCountMethod, LettersOccursMatchLetters)
{
    std::map <char, int> testMapOfLetters = countLetters("almafa");
    ASSERT_EQ(testMapOfLetters['a'], 3);
}

TEST(TestCountMethod2, LettersOccursMatchLetters2)
{
    std::map <char, int> testMapOfLetters;
    testMapOfLetters.insert(std::make_pair('s', 2));
    testMapOfLetters.insert(std::make_pair('y', 1));
    testMapOfLetters.insert(std::make_pair('l', 2));
    testMapOfLetters.insert(std::make_pair('a', 1));
    testMapOfLetters.insert(std::make_pair('b', 1));
    testMapOfLetters.insert(std::make_pair('u', 1));

    ASSERT_EQ(countLetters("syllabus"), testMapOfLetters);
}