#include "calculate_next_board.h"

#include "count_alive_neighbours.h"
#include "next_cell_state.h"

void calculate_next_board(bool* current_board, bool* next_board, uint16_t board_size){

  for (uint16_t i = 0; i < board_size; i++) {
    for (uint16_t j = 0; j < board_size; j++) {
      uint8_t num_neighbours = count_alive_neighbours(current_board, board_size, i, j);
      bool current_cell_state = current_board[j + board_size * i];
      next_board[j + board_size * i] = next_cell_state(current_cell_state, num_neighbours);
    }
  }
}
