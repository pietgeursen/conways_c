#include "gtest/gtest.h"

#include "calculate_next_board.h"

TEST(calculate_next_board, One) {

  bool board[BOARD_SIZE * BOARD_SIZE] = {false};
  bool next_board[BOARD_SIZE * BOARD_SIZE] = {false};

  board[0 + BOARD_SIZE * 0] = true;
  board[1 + BOARD_SIZE * 1] = true;
  board[2 + BOARD_SIZE * 1] = true;
  board[3 + BOARD_SIZE * 0] = true;

  calculate_next_board(board, next_board, BOARD_SIZE);

  EXPECT_FALSE(next_board[0 + BOARD_SIZE * 0]);
  EXPECT_TRUE(next_board[1 + BOARD_SIZE * 0]);
  EXPECT_TRUE(next_board[2 + BOARD_SIZE * 0]);
  EXPECT_FALSE(next_board[3 + BOARD_SIZE * 0]);

  EXPECT_FALSE(next_board[0 + BOARD_SIZE * 1]);
  EXPECT_TRUE(next_board[1 + BOARD_SIZE * 1]);
  EXPECT_TRUE(next_board[2 + BOARD_SIZE * 1]);
  EXPECT_FALSE(next_board[3 + BOARD_SIZE * 1]);

  EXPECT_FALSE(next_board[0 + BOARD_SIZE * 2]);
  EXPECT_FALSE(next_board[1 + BOARD_SIZE * 2]);
  EXPECT_FALSE(next_board[2 + BOARD_SIZE * 2]);
  EXPECT_FALSE(next_board[3 + BOARD_SIZE * 2]);
}

TEST(calculate_next_board, Two) {

  bool board[BOARD_SIZE * BOARD_SIZE] = {false};
  bool next_board[BOARD_SIZE * BOARD_SIZE] = {false};

  board[1 + BOARD_SIZE * 0] = true;
  board[2 + BOARD_SIZE * 0] = true;

  board[1 + BOARD_SIZE * 1] = true;
  board[2 + BOARD_SIZE * 1] = true;

  board[1 + BOARD_SIZE * 2] = true;
  board[2 + BOARD_SIZE * 2] = true;

  calculate_next_board(board, next_board, BOARD_SIZE);

  EXPECT_FALSE(next_board[0 + BOARD_SIZE * 0]);
  EXPECT_TRUE(next_board[1 + BOARD_SIZE * 0]);
  EXPECT_TRUE(next_board[2 + BOARD_SIZE * 0]);
  EXPECT_FALSE(next_board[3 + BOARD_SIZE * 0]);

  EXPECT_TRUE(next_board[0 + BOARD_SIZE * 1]);
  EXPECT_FALSE(next_board[1 + BOARD_SIZE * 1]);
  EXPECT_FALSE(next_board[2 + BOARD_SIZE * 1]);
  EXPECT_TRUE(next_board[3 + BOARD_SIZE * 1]);

  EXPECT_FALSE(next_board[0 + BOARD_SIZE * 2]);
  EXPECT_TRUE(next_board[1 + BOARD_SIZE * 2]);
  EXPECT_TRUE(next_board[2 + BOARD_SIZE * 2]);
  EXPECT_FALSE(next_board[3 + BOARD_SIZE * 2]);
}

