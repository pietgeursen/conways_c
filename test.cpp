#include "gtest/gtest.h"

#include <stdint.h> //gives uint8_t etc
#include <cstdlib> //gives malloc + free


bool next_cell_state(bool current_cell_state, uint8_t neighbour_count){
  if(current_cell_state){
    return !is_over_populated(neighbour_count) && !is_under_populated(neighbour_count); 
  } else {
    return is_ressurectable(neighbour_count); 
  }
}

bool is_index_out_of_bounds(int16_t index, uint16_t array_size){
  return index < 0 || index >= array_size;
}

uint8_t count_alive_neightbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num){
  uint8_t count = 0;
  
  for (int8_t i = -1; i <= 1 ; i++) {
    for (int8_t j = -1; j <= 1 ; j++) {
      uint16_t row_index = row_num + i;
      uint16_t col_index = col_num + j;

      if(i == 0 && j == 0)
        continue;

      if(is_index_out_of_bounds(row_index, board_size) || is_index_out_of_bounds(col_index, board_size))
        continue;

      count += board[row_index * board_size + col_index] ? 1 : 0;
    }
  }

  return count;
}

void calculate_next_board(bool* current_board, bool* next_board, uint16_t board_size){

}

void randomly_seed_board(bool * board, uint16_t board_size){

}

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

TEST(is_out_of_bounds, Passes) {
  EXPECT_TRUE(is_index_out_of_bounds(-1,1));
  EXPECT_FALSE(is_index_out_of_bounds(0,1));
  EXPECT_TRUE(is_index_out_of_bounds(1,1));
}

TEST(count_alive_neightbours, Corner) {
  bool board[BOARD_SIZE * BOARD_SIZE] = {false};

  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 0, 0), 0);

  board[0 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 0, 0), 0);

  board[0 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 0, 0), 1);

  board[1 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 0, 0), 2);

  board[1 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 0, 0), 3);
}

TEST(count_alive_neightbours, Center) {
  bool board[BOARD_SIZE * BOARD_SIZE] = {false};

  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 0);

  board[1 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 0);

  board[0 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 1);

  board[0 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 2);

  board[0 * BOARD_SIZE + 2] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 3);

  board[1 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 4);

  board[1 * BOARD_SIZE + 2] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 5);

  board[2 * BOARD_SIZE + 0] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 6);

  board[2 * BOARD_SIZE + 1] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 7);

  board[2 * BOARD_SIZE + 2] = true;
  EXPECT_EQ(count_alive_neightbours(board, BOARD_SIZE, 1, 1), 8);
}
