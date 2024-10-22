#include <gtest/gtest.h>

#include "Vector.h"


class VectorTest : public ::testing::Test {
protected:
    Vector<int> vec;
};

TEST_F(VectorTest, InsertElement) {
    vec.insert(10, 0);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec.size(), 1);
}

TEST_F(VectorTest, RemoveElement) {
    vec.insert(10, 0);
    vec.remove(0);
    EXPECT_THROW(vec[0], std::out_of_range);
    EXPECT_EQ(vec.size(), 0);
}

TEST_F(VectorTest, InsertMultipleElements) {
    vec.insert(10, 0);
    vec.insert(30, 1);
    vec.insert(20, 2);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[2], 20);
    EXPECT_EQ(vec[1], 30);
}

TEST_F(VectorTest, RemoveMultipleElements) {
    vec.insert(10, 0);
    vec.insert(20, 1);
    vec.insert(30, 2);
    vec.remove(1);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 30);
}

TEST_F(VectorTest, OutOfRangeAccess) {
    vec.insert(10, 0);
    EXPECT_THROW(vec[1], std::out_of_range);
    EXPECT_THROW(vec[-1], std::out_of_range);
}

TEST_F(VectorTest, InsertOutOfRange) {
    EXPECT_THROW(vec.insert(10, 1), std::out_of_range);
    EXPECT_THROW(vec.insert(10, 2), std::out_of_range);
    EXPECT_THROW(vec.insert(10, -1), std::out_of_range);
}
