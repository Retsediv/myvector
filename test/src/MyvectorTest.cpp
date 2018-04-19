#include <climits>
#include "gtest/gtest.h"
#include "../../myvector.h"

class MyvectorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
    }
};

TEST_F(MyvectorTest, size){
    myvector<int> mv{};

    EXPECT_EQ(0, mv.getSize());
//    EXPECT_EQ(5,addition.twoValues(2,3));
}