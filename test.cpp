#include "gtest/gtest.h"

#include <stdint.h> //gives uint8_t etc
#include <cstdlib> //gives malloc + free

#define BOARD_ROWS 4
#define BOARD_COLUMNS BOARD_ROWS 

bool * allocate_memory_for_row(uint16_t row_size){
  return (bool *) malloc(sizeof(bool) * row_size);
}

bool ** allocate_memory_for_board(uint16_t col_size){
  return (bool **) malloc(sizeof(bool *) * col_size);
}

bool ** create_new_board(uint16_t board_size){
  bool ** board = allocate_memory_for_board(board_size);

  for (uint16_t i = 0; i < board_size; i++) {
    board[i] = allocate_memory_for_row(board_size);
  }

  return board;
}

bool is_over_populated(uint8_t num_neighbours){
  return num_neighbours > 3; 
}

bool is_under_populated(uint8_t num_neighbours){
  return num_neighbours < 2; 
}

bool is_ressurectable(uint8_t num_neighbours){
  return num_neighbours == 3; 
}

bool next_cell_state(bool current_cell_state, uint8_t neighbour_count){
  if(current_cell_state){
    return !is_over_populated(neighbour_count) && !is_under_populated(neighbour_count); 
  } else {
    return is_ressurectable(neighbour_count); 
  }
}

bool is_index_out_of_bounds(uint16_t index, uint16_t array_size){
  return index < 0 || index >= array_size;
}

uint8_t count_alive_neightbours(bool ** board, uint16_t row_num, uint16_t col_num){
  uint8_t count = 0;
  
  for (int8_t i = -1; i <= 1 ; i++) {
    for (int8_t j = -1; j <= 1 ; j++) {
      uint16_t row_index = row_num + i;
      uint16_t col_index = col_num + i;

      if(i == 0 && j == 0)
        continue;

      if(is_index_out_of_bounds(row_index, BOARD_ROWS) || is_index_out_of_bounds(col_index, BOARD_COLUMNS))
        continue;

      count += board[row_index][col_index] ? 1 : 0;
    }
  }

  return count;
}


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

TEST(is_ressurectable_populated, Passes) {
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

TEST(count_alive_neightbours, Passes) {
  bool ** board = create_new_board(BOARD_ROWS);

  board[0][0] = false;
  board[0][1] = false;
  board[1][0] = false;
  board[1][1] = false;

  EXPECT_EQ(count_alive_neightbours(board, 0, 0), 0);

  board[0][1] = true;
  EXPECT_EQ(count_alive_neightbours(board, 0, 0), 1);

  board[1][1] = true;
  EXPECT_EQ(count_alive_neightbours(board, 0, 0), 2);

  board[1][0] = true;
  EXPECT_EQ(count_alive_neightbours(board, 0, 0), 3);
}
