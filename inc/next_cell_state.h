#ifndef NEXT_CELL_STATE_H 
#define NEXT_CELL_STATE_H 

#include <stdint.h> //gives uint8_t etc
#include <stdbool.h> //gives bool

#ifdef __cplusplus
extern "C" {
#endif

  bool next_cell_state(bool current_cell_state, uint8_t neighbour_count);

#ifdef __cplusplus
}
#endif

#endif
