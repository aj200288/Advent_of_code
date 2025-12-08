#include <gtest/gtest.h>
#include "../functions.h"


TEST(AoC2508, distance) {
    EXPECT_EQ(distance({162, 817, 812}, {57, 618, 57}), 620651);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



// TEST(ExampleTest, BasicAssertion) {
//     EXPECT_EQ(add(1, 1), 2);
// }