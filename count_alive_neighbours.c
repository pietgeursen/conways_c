#include "calculate_next_board.h"
#include "is_index_out_of_bounds.h"

bool is_edge_cell(uint16_t board_size, uint16_t row_num, uint16_t col_num){
  return row_num == 0 || col_num == 0 || row_num == board_size - 1 || col_num == board_size - 1;
}

uint8_t asm_count_alive_nighbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num);

uint8_t count_alive_neighbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num){
  
  //if(!is_edge_cell(board_size, row_num, col_num))
    //return asm_count_alive_nighbours(board, board_size, row_num, col_num);

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

uint8_t __attribute__ ((noinline)) asm_count_alive_nighbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num){
  uint8_t result = 0;
  asm(
      ".macro GET_NEIGHBOUR_AT_X_Y, x, y\n"
      "ADD r0, %[col_num], #\\x\n" //calculate the x index of cell top left 
      "ADD r1, %[row_num], #\\y\n" //calculate the y index of cell top left 

      "MLA r0, r1, %[board_size], r0\n" //calculate the y index of cell TL
      "LDRB r0, [%[board],r0]\n"

      "ADD r2, r2, r0\n" //Accumulate the neighbour count in r2
      ".endm \n"
      "MOV r2, #0;" //zero out sum register
      "GET_NEIGHBOUR_AT_X_Y -1, -1;"
      "GET_NEIGHBOUR_AT_X_Y  0, -1;"
      "GET_NEIGHBOUR_AT_X_Y  1, -1;"

      "GET_NEIGHBOUR_AT_X_Y -1,  0;"
      "GET_NEIGHBOUR_AT_X_Y  1,  0;"

      "GET_NEIGHBOUR_AT_X_Y -1,  1;"
      "GET_NEIGHBOUR_AT_X_Y  0,  1;"
      "GET_NEIGHBOUR_AT_X_Y  1,  1;"
      "MOV %[result], r2;"
      : [result] "=r" (result)
      : [row_num] "r" (row_num), [col_num] "r" (col_num), [board_size] "r" (board_size), [board] "r" (board)
      : "r0", "r1", "r2"
      );
  return result;
}
