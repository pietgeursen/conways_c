#include "gtest/gtest.h"

#include "count_alive_neighbours.h"

TEST(count_alive_neighbours, Asm) {
  bool board[9] = {false};

  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x00);

  board[0] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x01);

  board[1] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x02);

  board[2] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x03);

  board[3] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x04);

  board[4] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x04);

  board[5] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x05);

  board[6] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x06);

  board[7] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x07);

  board[8] = true;
  EXPECT_EQ(asm_count_alive_nighbours(board, 3, 1, 1), 0x08);
}

