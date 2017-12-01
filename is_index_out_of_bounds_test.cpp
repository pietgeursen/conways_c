#include "gtest/gtest.h"

#include "is_index_out_of_bounds.h"

TEST(is_out_of_bounds, Passes) {
  EXPECT_TRUE(is_index_out_of_bounds(-1,1));
  EXPECT_FALSE(is_index_out_of_bounds(0,1));
  EXPECT_TRUE(is_index_out_of_bounds(1,1));
}
