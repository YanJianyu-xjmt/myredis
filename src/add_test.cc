#include "gtest/gtest.h"

#include "add.hpp"

TEST(testAdd, test0)
{
  EXPECT_EQ(15, add(5, 10));
}
