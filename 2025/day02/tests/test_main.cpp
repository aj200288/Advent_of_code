#include <gtest/gtest.h>
#include "../functions.h"

TEST(AoC2502, p1) {
    EXPECT_EQ(invalid_ids_part1(11, 22), 33);
    EXPECT_EQ(invalid_ids_part1(95, 115), 99);
    EXPECT_EQ(invalid_ids_part1(1188511880, 1188511890), 1188511885);
    EXPECT_EQ(invalid_ids_part1(1698522, 1698528), 0);
}

TEST(AoC2502, p2) {
    EXPECT_EQ(invalid_ids_part2(11, 22), 33);
    EXPECT_EQ(invalid_ids_part2(95, 115), 210);
    EXPECT_EQ(invalid_ids_part2(998,1012), 2009);
    EXPECT_EQ(invalid_ids_part2(1188511880, 1188511890), 1188511885);
    EXPECT_EQ(invalid_ids_part2(222220, 222224), 222222);
    EXPECT_EQ(invalid_ids_part2(1698522, 1698528), 0);
    EXPECT_EQ(invalid_ids_part2(446443, 446449), 446446);

    EXPECT_EQ(invalid_ids_part2(2121212118, 2121212124), 2121212121);

   
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



// TEST(ExampleTest, BasicAssertion) {
//     EXPECT_EQ(add(1, 1), 2);
// }