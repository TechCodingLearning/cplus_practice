#include <gtest/gtest.h>
// #include <gtest/gtest_prod.h>
// #include <gtest/gtest-assertion-result.h>
#include "googletest/samples/sample3-inl.h"

class QueueTest : public testing::Test {
 protected:
  void SetUp() override {
    // q0_ remains empty
    q1_.Enqueue(1);
    q2_.Enqueue(2);
    q2_.Enqueue(3);
  }

  // void TearDown() override {}

  static int Double(int n) { return 2 * n; }
  void MapTester(const Queue<int>* q) {
    const Queue<int>* const new_q = q->Map(Double);

    ASSERT_EQ(q->Size(), new_q->Size());

    for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head();
         n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
      EXPECT_EQ(2 * n1->element(), n2->element());
    }
  }

  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

TEST_F(QueueTest, QueueWork) {
  EXPECT_EQ(q0_.Size(), 0);

  int* element = q0_.Dequeue();
  EXPECT_EQ(element, nullptr);

  element = q1_.Dequeue();
  ASSERT_NE(element, nullptr);
  EXPECT_EQ(*element, 1);
  EXPECT_EQ(q1_.Size(), 0);
  delete element;
  element = nullptr;

  element = q2_.Dequeue();
  ASSERT_NE(element, nullptr);
  EXPECT_EQ(*element, 2);
  EXPECT_EQ(q2_.Size(), 1);
  delete element;
  element = nullptr;
}

TEST_F(QueueTest, Map) {
  MapTester(&q0_);
  MapTester(&q1_);
  MapTester(&q2_);
}