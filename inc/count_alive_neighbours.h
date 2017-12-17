#ifndef COUNT_ALIVE_NEIGHTBOURS_H
#define COUNT_ALIVE_NEIGHTBOURS_H

#include <stdint.h> //gives uint8_t etc
#include <stdbool.h> //gives bool

#ifdef __cplusplus
extern "C" {
#endif

  uint8_t count_alive_neighbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num);
  uint32_t asm_count_alive_nighbours(bool* board, uint16_t board_size, uint16_t row_num, uint16_t col_num);
#ifdef __cplusplus
}
#endif

#endif
