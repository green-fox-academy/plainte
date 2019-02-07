#include <gtest/gtest.h>
#include "myApplesClass.h"

TEST(apple_check, test_apple)
{
    ASSERT_STREQ(getApple().c_str(), "apple");
}
