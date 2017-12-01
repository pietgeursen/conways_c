#include "gtest/gtest.h"

#include "next_cell_state.h"

TEST(next_cell_state, Passes) {
  EXPECT_FALSE(next_cell_state(false, 0));
  EXPECT_FALSE(next_cell_state(false, 1));
  EXPECT_FALSE(next_cell_state(false, 2));
  EXPECT_TRUE(next_cell_state(false, 3));
  EXPECT_FALSE(next_cell_state(false, 4));
  EXPECT_FALSE(next_cell_state(false, 5));
  EXPECT_FALSE(next_cell_state(false, 6));
  EXPECT_FALSE(next_cell_state(false, 7));
  EXPECT_FALSE(next_cell_state(false, 8));

  EXPECT_FALSE(next_cell_state(true, 0));
  EXPECT_FALSE(next_cell_state(true, 1));
  EXPECT_TRUE(next_cell_state(true, 2));
  EXPECT_TRUE(next_cell_state(true, 3));
  EXPECT_FALSE(next_cell_state(true, 4));
  EXPECT_FALSE(next_cell_state(true, 5));
  EXPECT_FALSE(next_cell_state(true, 6));
  EXPECT_FALSE(next_cell_state(true, 7));
  EXPECT_FALSE(next_cell_state(true, 8));
}
