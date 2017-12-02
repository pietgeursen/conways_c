#include "calculate_next_board.h"
#include "is_index_out_of_bounds.h"

uint8_t count_alive_neighbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num){
  uint8_t count = 0;
  
  for (int8_t i = -1; i <= 1 ; i++) {
    for (int8_t j = -1; j <= 1 ; j++) {
      uint16_t row_index = row_num + i;
      uint16_t col_index = col_num + j;

      if(i == 0 && j == 0)
        continue;

      if(is_index_out_of_bounds(row_index, board_size) || is_index_out_of_bounds(col_index, board_size))
        continue;

      count += board[col_index + board_size * row_index] ? 1 : 0;
    }
  }

  return count;
}
