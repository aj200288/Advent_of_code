#include <gtest/gtest.h>
#include "../functions.h"

TEST(AoC19, find_fuel_part1) {
    EXPECT_EQ(find_fuel_part1(12), 2);
    EXPECT_EQ(find_fuel_part1(14), 2);
    EXPECT_EQ(find_fuel_part1(1969), 654);
    EXPECT_EQ(find_fuel_part1(100756), 33583);
}

TEST(AoC19, find_fuel_part2) {
    EXPECT_EQ(find_fuel_part2(12), 2);
    EXPECT_EQ(find_fuel_part2(14), 2);
    EXPECT_EQ(find_fuel_part2(1969), 966);
    EXPECT_EQ(find_fuel_part2(100756), 50346);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



// TEST(ExampleTest, BasicAssertion) {
//     EXPECT_EQ(add(1, 1), 2);
// }