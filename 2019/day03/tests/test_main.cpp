#include <gtest/gtest.h>
#include "../functions.h"


TEST(MakeEdgeTest, MoveRight) {
    Point start{0, 0};
    Edge edge = make_edge("R5", start);
    
    EXPECT_EQ(edge.start.x, 0);
    EXPECT_EQ(edge.start.y, 0);
    EXPECT_EQ(edge.end.x, 5);
    EXPECT_EQ(edge.end.y, 0);
}

TEST(MakeEdgeTest, MoveLeft) {
    Point start{10, 5};
    Edge edge = make_edge("L3", start);
    
    EXPECT_EQ(edge.start.x, 10);
    EXPECT_EQ(edge.start.y, 5);
    EXPECT_EQ(edge.end.x, 7);
    EXPECT_EQ(edge.end.y, 5);
}

TEST(MakeEdgeTest, MoveUp) {
    Point start{0, 0};
    Edge edge = make_edge("U8", start);
    
    EXPECT_EQ(edge.start.x, 0);
    EXPECT_EQ(edge.start.y, 0);
    EXPECT_EQ(edge.end.x, 0);
    EXPECT_EQ(edge.end.y, 8);
}

TEST(MakeEdgeTest, MoveDown) {
    Point start{5, 10};
    Edge edge = make_edge("D6", start);
    
    EXPECT_EQ(edge.start.x, 5);
    EXPECT_EQ(edge.start.y, 10);
    EXPECT_EQ(edge.end.x, 5);
    EXPECT_EQ(edge.end.y, 4);
}

TEST(MakeEdgeTest, LargeDistance) {
    Point start{100, 200};
    Edge edge = make_edge("R999", start);
    
    EXPECT_EQ(edge.end.x, 1099);
    EXPECT_EQ(edge.end.y, 200);
}

TEST(MakeEdgeTest, InvalidDirection) {
    Point start{0, 0};
    EXPECT_THROW(make_edge("X5", start), std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}