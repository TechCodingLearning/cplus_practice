#include <gtest/gtest.h>
#include "prime_tables.h"

// This sample shows how to test common properties of multiple
// implementaions of the same interface (aka interface tests).

namespace {

// factory functions
template <class T>
PrimeTable* CreatePrimeTable();

template <>
PrimeTable* CreatePrimeTable<OnTheFlyPrimeTable>() {
    return new OnTheFlyPrimeTable();
}

template <>
PrimeTable* CreatePrimeTable<PreCalculatedPrimeTable>() {
    return new PreCalculatedPrimeTable(10000);
}

// Test suit
template <class T>
class PrimeTableTest : public testing::Test {
protected:
    PrimeTableTest()
        : table_(CreatePrimeTable<T>()) { }

    ~PrimeTableTest() override { delete table_; }

    PrimeTable* const table_;
};

using testing::Types;

typedef Types<OnTheFlyPrimeTable, PreCalculatedPrimeTable> Implementations;

TYPED_TEST_SUITE(PrimeTableTest, Implementations); // Test case name, Type list

TYPED_TEST(PrimeTableTest, ReturnsFalseForNonPrimes) {
    EXPECT_FALSE(this->table_->IsPrime(-5));
    EXPECT_FALSE(this->table_->IsPrime(0));
    EXPECT_FALSE(this->table_->IsPrime(1));
    EXPECT_FALSE(this->table_->IsPrime(4));
    EXPECT_FALSE(this->table_->IsPrime(6));
    EXPECT_FALSE(this->table_->IsPrime(100));
}

TYPED_TEST(PrimeTableTest, ReturnsTrueForPrimes) {
    EXPECT_TRUE(this->table_->IsPrime(2));
    EXPECT_TRUE(this->table_->IsPrime(3));
    EXPECT_TRUE(this->table_->IsPrime(5));
    EXPECT_TRUE(this->table_->IsPrime(7));
    EXPECT_TRUE(this->table_->IsPrime(11));
    EXPECT_TRUE(this->table_->IsPrime(131));
}

TYPED_TEST(PrimeTableTest, CanGetNextPrime) {
    EXPECT_EQ(2, this->table_->GetNextPrime(0));
    EXPECT_EQ(3, this->table_->GetNextPrime(2));
    EXPECT_EQ(5, this->table_->GetNextPrime(3));
    EXPECT_EQ(7, this->table_->GetNextPrime(5));
    EXPECT_EQ(11, this->table_->GetNextPrime(7));
    EXPECT_EQ(131, this->table_->GetNextPrime(128));
}

template <class T>
class PrimeTableTest2 : public PrimeTableTest<T> { };

TYPED_TEST_SUITE_P(PrimeTableTest2);

TYPED_TEST_P(PrimeTableTest2, ReturnsFalseForNonPrimes) {
    EXPECT_FALSE(this->table_->IsPrime(-5));
    EXPECT_FALSE(this->table_->IsPrime(0));
    EXPECT_FALSE(this->table_->IsPrime(1));
    EXPECT_FALSE(this->table_->IsPrime(4));
    EXPECT_FALSE(this->table_->IsPrime(6));
    EXPECT_FALSE(this->table_->IsPrime(100));
}

TYPED_TEST_P(PrimeTableTest2, ReturnsTrueForPrimes) {
    EXPECT_TRUE(this->table_->IsPrime(2));
    EXPECT_TRUE(this->table_->IsPrime(3));
    EXPECT_TRUE(this->table_->IsPrime(5));
    EXPECT_TRUE(this->table_->IsPrime(7));
    EXPECT_TRUE(this->table_->IsPrime(11));
    EXPECT_TRUE(this->table_->IsPrime(131));
}

TYPED_TEST_P(PrimeTableTest2, CanGetNextPrime) {
    EXPECT_EQ(2, this->table_->GetNextPrime(0));
    EXPECT_EQ(3, this->table_->GetNextPrime(2));
    EXPECT_EQ(5, this->table_->GetNextPrime(3));
    EXPECT_EQ(7, this->table_->GetNextPrime(5));
    EXPECT_EQ(11, this->table_->GetNextPrime(7));
    EXPECT_EQ(131, this->table_->GetNextPrime(128));
}

// Type-parameterized tests involve one extra step: you have to
// enumerate the tests you defined:
REGISTER_TYPED_TEST_SUITE_P(
    PrimeTableTest2,
    ReturnsFalseForNonPrimes,
    ReturnsTrueForPrimes,
    CanGetNextPrime);

typedef Types<OnTheFlyPrimeTable, PreCalculatedPrimeTable> PrimeTableImplementations;
INSTANTIATE_TYPED_TEST_SUITE_P(
    OnTheFlyAndPreCalculated, // Instance name
    PrimeTableTest2, // Test case name
    PrimeTableImplementations); // Type list
}