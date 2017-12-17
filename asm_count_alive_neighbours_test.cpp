#include "gtest/gtest.h"

#include "count_alive_neighbours.h"

TEST(count_alive_neighbours, Corner) {
  bool board[9] = {false};

  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x00);

  board[0] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x01);

  board[1] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x02);

  board[2] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x03);
}

