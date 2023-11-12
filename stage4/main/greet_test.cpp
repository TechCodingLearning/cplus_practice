
#include "hello-greet.h"
#include <gtest/gtest.h>

TEST(GetGreetTest, Basic) {
  EXPECT_EQ("Hello World", get_greet("World"));
  EXPECT_EQ("Hello Time!", get_greet("Time!"));
}