#include <gtest/gtest.h>
#include "../../fixedvector.hpp"
#include "../../exceptions.h"

class FixedvectorTest : public ::testing::Test {
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};


TEST_F(FixedvectorTest, contruct) {
    fixedvector<int, 5> a{1};

    EXPECT_EQ(5, a.getSize());
}

TEST_F(FixedvectorTest, initialFill) {
    fixedvector<int, 5> a{};

    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(0, a.at(i));
    }
}

TEST_F(FixedvectorTest, customFill) {
    fixedvector<int, 5> a{111};

    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(111, a.at(i));
    }
}


TEST_F(FixedvectorTest, bracketsOperator) {
    fixedvector<int, 10> a{};
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(i, a.at(i));
    }
}

TEST_F(FixedvectorTest, front) {
    fixedvector<int, 10> a{};
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
    }

    EXPECT_EQ(9, a.front());
}