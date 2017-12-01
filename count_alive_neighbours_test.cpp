#include "gtest/gtest.h"

#include "count_alive_neighbours.h"

TEST(count_alive_neighbours, Corner) {
  bool board[BOARD_SIZE * BOARD_SIZE] = {false};

  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 0, 0), 0);

  board[0 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 0, 0), 0);

  board[0 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 0, 0), 1);

  board[1 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 0, 0), 2);

  board[1 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 0, 0), 3);
}

TEST(count_alive_neighbours, Center) {
  bool board[BOARD_SIZE * BOARD_SIZE] = {false};

  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 0);

  board[1 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 0);

  board[0 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 1);

  board[0 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 2);

  board[0 * BOARD_SIZE + 2] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 3);

  board[1 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 4);

  board[1 * BOARD_SIZE + 2] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 5);

  board[2 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 6);

  board[2 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 7);

  board[2 * BOARD_SIZE + 2] = true;
  EXPECT_EQ(count_alive_neighbours(board, BOARD_SIZE, 1, 1), 8);
}
