#include <gtest/gtest.h>

#include "googletest/samples/sample1.h"
#include "googletest/samples/sample3-inl.h"

// This sample teaches how to reuse a test fixture in multi test cases
// by deriving sub-fixtures from it.
namespace {

class QuickTest : public testing::Test {
protected:
    void SetUp() override {
        start_time_ = time(nullptr);
    }

    void TearDown() override {
        const time_t end_time = time(nullptr);
        EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
    }

    time_t start_time_;
};

class IntegerFunctionTest : public QuickTest {
};

TEST_F(IntegerFunctionTest, TestFactorial) {
    EXPECT_EQ(1, Factorial(-5));
    EXPECT_EQ(1, Factorial(-1));
    EXPECT_GT(Factorial(-10), 0);

    EXPECT_EQ(1, Factorial(1));
    EXPECT_EQ(2, Factorial(2));
    EXPECT_EQ(6, Factorial(3));
    EXPECT_EQ(40320, Factorial(8));
}

TEST_F(IntegerFunctionTest, TestIsPrime) {
    EXPECT_FALSE(IsPrime(-1));
    EXPECT_FALSE(IsPrime(-2));
    EXPECT_FALSE(IsPrime(INT_MIN));

    EXPECT_FALSE(IsPrime(0));
    EXPECT_FALSE(IsPrime(1));
    EXPECT_TRUE(IsPrime(2));
    EXPECT_TRUE(IsPrime(3));
    EXPECT_FALSE(IsPrime(4));
    EXPECT_TRUE(IsPrime(5));
    EXPECT_FALSE(IsPrime(6));
    EXPECT_TRUE(IsPrime(23));
}
}