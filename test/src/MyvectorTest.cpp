
#include "gtest/gtest.h"
#include "../../myvector.h"

using std::vector;

class MyvectorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
//        std::cout << "End of test" << std::endl;
        // Code here will be called immediately after each test
        // (right before the destructor).
    }
};

TEST_F(MyvectorTest, initialSizeEqualToZero) {
    myvector<int> mv{};

    EXPECT_EQ(0, mv.getSize());
}

TEST_F(MyvectorTest, sizeAfterInitialSet) {
    // it does't effect to size of array
    myvector<int> mv{50};

    // it affect
    myvector<int> mv1{50, 100};

    EXPECT_EQ(0, mv.getSize());
    EXPECT_EQ(50, mv1.getSize());
}

TEST_F(MyvectorTest, reservedSizeAfterCreate) {
    myvector<int> mv{};
    myvector<int> mv1{100};
    myvector<int> mv2{50, 0};

    EXPECT_EQ(default_vector_size, mv.getReserved_size());
    EXPECT_EQ(100, mv1.getReserved_size());
    EXPECT_EQ(50 + default_vector_size, mv2.getReserved_size());
}

TEST_F(MyvectorTest, fillWithInitialValueAfterCreate) {
    int size = 10;
    myvector<int> mv{size, 0};
    myvector<int> mv1{size, -1};
    myvector<int> mv2{size, 99};

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(0, mv[i]);
        EXPECT_EQ(-1, mv1[i]);
        EXPECT_EQ(99, mv2[i]);
    }
}

TEST_F(MyvectorTest, simplePushBack) {
    myvector<int> mv{};

    mv.push_back(1);
    EXPECT_EQ(1, mv.getSize());

    mv.push_back(9999);
    EXPECT_EQ(2, mv.getSize());

    mv.push_back(-123);
    EXPECT_EQ(3, mv.getSize());
}

TEST_F(MyvectorTest, pushBackWithSTLContainer) {
    myvector<vector<int>> mv{};

    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(100, -1);

    mv.push_back(v1);
    EXPECT_EQ(1, mv.getSize());

    mv.push_back(v2);
    EXPECT_EQ(2, mv.getSize());

    mv.push_back(v3);
    EXPECT_EQ(3, mv.getSize());
}

TEST_F(MyvectorTest, popAndFront) {
    // simple case
    myvector<int> mv{};
    int i1 = 1;
    int i2 = 999;

    mv.push_back(i1);
    mv.push_back(i2);

    EXPECT_EQ(i2, mv.front());
    mv.pop();
    EXPECT_EQ(1, mv.getSize());
    EXPECT_EQ(i1, mv.front());
    mv.pop();
    EXPECT_EQ(0, mv.getSize());

    // with STL container
    myvector<vector<int>> mv1{};

    vector<int> v1{};
    vector<int> v2{10};
    vector<int> v3{100, -1};

    mv1.push_back(v1);
    mv1.push_back(v2);
    mv1.push_back(v3);

//    EXPECT_EQ(v3, mv1.front());
//    mv1.pop();
//    EXPECT_EQ(2, mv1.getSize());
//    EXPECT_EQ(v2, mv1.front());
//    mv1.pop();
//    EXPECT_EQ(v1, mv1.front());
//    EXPECT_EQ(1, mv1.getSize());
//    mv1.pop();
//    EXPECT_EQ(0, mv1.getSize());


}


