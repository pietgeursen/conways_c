#include "gtest/gtest.h"

#include "is_ressurectable.h"

TEST(is_ressurectable, Passes) {
  EXPECT_FALSE(is_ressurectable(0));
  EXPECT_FALSE(is_ressurectable(1));
  EXPECT_FALSE(is_ressurectable(2));
  EXPECT_TRUE(is_ressurectable(3));
  EXPECT_FALSE(is_ressurectable(4));
  EXPECT_FALSE(is_ressurectable(5));
  EXPECT_FALSE(is_ressurectable(6));
  EXPECT_FALSE(is_ressurectable(7));
  EXPECT_FALSE(is_ressurectable(8));
}
