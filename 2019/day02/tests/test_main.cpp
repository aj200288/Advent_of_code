#include <gtest/gtest.h>
#include "../functions.h"

TEST(AoC19, intcode) {
    std::vector<long long> input = {1,9,10,3,2,3,11,0,99,30,40,50};
    EXPECT_EQ(intcode(input), 3500);
    std::vector<long long> input1 = {1,1,1,4,99,5,6,0,99};
    EXPECT_EQ(intcode(input1), 30);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



// TEST(ExampleTest, BasicAssertion) {
//     EXPECT_EQ(add(1, 1), 2);
// }