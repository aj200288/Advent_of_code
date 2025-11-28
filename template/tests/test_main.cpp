#include <gtest/gtest.h>
#include "../functions.h"

// Test the add function
TEST(FunctionsTest, AddTest) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-5, -3), -8);
}

// Test the multiply function
TEST(FunctionsTest, MultiplyTest) {
    EXPECT_EQ(multiply(2, 3), 6);
    EXPECT_EQ(multiply(-2, 3), -6);
    EXPECT_EQ(multiply(0, 5), 0);
    EXPECT_EQ(multiply(-4, -3), 12);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
