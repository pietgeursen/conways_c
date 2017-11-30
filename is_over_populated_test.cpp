#include "gtest/gtest.h"

#include "is_over_populated.h"

TEST(is_over_populated, Passes) {
  EXPECT_FALSE(is_over_populated(0));
  EXPECT_FALSE(is_over_populated(1));
  EXPECT_FALSE(is_over_populated(2));
  EXPECT_FALSE(is_over_populated(3));
  EXPECT_TRUE(is_over_populated(4));
  EXPECT_TRUE(is_over_populated(5));
  EXPECT_TRUE(is_over_populated(6));
  EXPECT_TRUE(is_over_populated(7));
  EXPECT_TRUE(is_over_populated(8));
}
