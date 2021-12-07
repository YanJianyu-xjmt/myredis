#include "gtest/gtest.h"

#include "sds.hpp"

TEST(sdsAdd, test0)
{

    myredis::sds s(10);
    EXPECT_EQ(10, s.getcapacity());
}
