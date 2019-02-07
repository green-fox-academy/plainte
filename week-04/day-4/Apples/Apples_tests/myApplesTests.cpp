#include <gtest/gtest.h>
#include "myApplesClass.h"

TEST(appleMethod, test_string) //test getApple()
{
    ASSERT_STREQ(getApple().c_str(), "apple");
}

TEST(sumMethod, test_vector) //list of integers
{
    std::vector<int> testElements = {1, 2, 3, 4, 5};
    ASSERT_EQ(sum(testElements), 15);
}

TEST(sumMethod2, test_vector2) //empty list
{
    std::vector<int> testElements;
    ASSERT_EQ(sum(testElements), 0);
}

TEST(sumMethod3, test_vector3) //list with 1 element
{
    std::vector<int> testElements = {5};
    ASSERT_EQ(sum(testElements), 5);
}

TEST(sumMethod4, test_vector4) //list with multiple elements
{
    std::vector<int> testElements = {5, 2, 10, 4};
    ASSERT_EQ(sum(testElements), 21);
}

TEST(sumMethod5, test_vector5) //negative sum
{
    std::vector<int> testElements = {-20, 4, 7, -3};
    ASSERT_EQ(sum(testElements), -12);
}
