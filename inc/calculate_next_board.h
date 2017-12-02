#ifndef CALCULATE_NEXT_BOARD_H 
#define CALCULATE_NEXT_BOARD_H 

#include <stdint.h> //gives uint8_t etc

#ifdef __cplusplus
extern "C" {
#endif

  void calculate_next_board(bool* current_board, bool* next_board, uint16_t board_size);

#ifdef __cplusplus
}
#endif

#endif
