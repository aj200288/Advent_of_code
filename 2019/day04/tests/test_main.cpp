#include <gtest/gtest.h>
#include "../functions.h"


TEST(AoC19, is_valid1) {
    EXPECT_FALSE(is_valid1(123456));
    EXPECT_FALSE(is_valid1(122134));
    EXPECT_TRUE(is_valid1(122345));
    EXPECT_TRUE(is_valid1(111111));
}

TEST(AoC19, is_valid2) {
    EXPECT_FALSE(is_valid2(123456));
    EXPECT_FALSE(is_valid2(123444));
    EXPECT_TRUE(is_valid2(112233));
    EXPECT_TRUE(is_valid2(111122));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


