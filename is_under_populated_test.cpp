#include "gtest/gtest.h"

#include "is_under_populated.h"

TEST(is_under_populated, Passes) {
  EXPECT_TRUE(is_under_populated(0));
  EXPECT_TRUE(is_under_populated(1));
  EXPECT_FALSE(is_under_populated(2));
  EXPECT_FALSE(is_under_populated(3));
  EXPECT_FALSE(is_under_populated(4));
  EXPECT_FALSE(is_under_populated(5));
  EXPECT_FALSE(is_under_populated(6));
  EXPECT_FALSE(is_under_populated(7));
  EXPECT_FALSE(is_under_populated(8));
}
