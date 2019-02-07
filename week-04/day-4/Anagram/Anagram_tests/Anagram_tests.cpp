#include <gtest/gtest.h>
#include "Anagram.h"

TEST(Anagram_method, areAnagramsOrNot)
{
    std::string testStr1 = "alma";
    std::string testStr2 = "lama";
    ASSERT_EQ(areAnagram(testStr1, testStr2), true);
}

TEST(Anagram_method_, areAnagramsOrNot_Test)
{
    std::string testStr1 = "alma";
    std::string testStr2 = "refactor";
    ASSERT_EQ(areAnagram(testStr1, testStr2), false);
}

TEST(Anagram_method2, areAnagramsOrNot_Test2)
{
    std::string testStr1 = "password";
    std::string testStr2 = "refactor";
    ASSERT_EQ(areAnagram(testStr1, testStr2), false);
}
