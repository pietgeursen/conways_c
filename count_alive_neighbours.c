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

uint8_t asm_count_alive_nighbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num){
  uint8_t result = 0;
  asm(
      "ADD r0, %[col_num], #-1;" //calculate the x index of cell top left 
      "ADD r1, %[row_num], #-1;" //calculate the y index of cell top left 

      "MUL r1, r1, %[board_size];" //calculate the y index of cell TL
      "ADD r0, r0, r1;" //calculate 1d index of cell TL
      "LDRB r0, [%[board],r0];"

      "ADD r2, r0, #0;"

      "ADD r0, %[col_num], #0;" //calculate the x index of cell top 
      "ADD r1, %[row_num], #-1;" //calculate the y index of cell top 

      "MUL r1, r1, %[board_size];" //calculate the y index of cell TL
      "ADD r0, r0, r1;" //calculate 1d index of cell TL
      "LDRB r0, [%[board],r0];"

      "ADD r2, r2, r0;"

      "ADD r0, %[col_num], # 1;" //calculate the x index of cell top right
      "ADD r1, %[row_num], #-1;" //calculate the y index of cell top right

      "MUL r1, r1, %[board_size];" //calculate the y index of cell TL
      "ADD r0, r0, r1;" //calculate 1d index of cell TL
      "LDRB r0, [%[board],r0];"

      "ADD %[result], r2, r0;"
      : [result] "=r" (result)
      : [row_num] "r" (row_num), [col_num] "r" (col_num), [board_size] "r" (board_size), [board] "r" (board)
      : "r0", "r1", "r2"
      );
  return result;
}
