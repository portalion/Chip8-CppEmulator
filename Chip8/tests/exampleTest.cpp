#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace ExampleTests
{
    TEST(MyExampleTests, AssertTrue) 
    {
        ASSERT_TRUE(true);
    }

    TEST(MyExampleTests, AssertFalse)
    {
        ASSERT_FALSE(false);
    }
}
