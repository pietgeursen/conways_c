#ifndef IS_INDEX_OUT_OF_BOUNDS_H
#define IS_INDEX_OUT_OF_BOUNDS_H

#include <stdint.h> //gives uint8_t etc
#include <stdbool.h> //gives bool

#ifdef __cplusplus
extern "C" {
#endif

  bool is_index_out_of_bounds(int16_t index, uint16_t array_size);

#ifdef __cplusplus
}
#endif

#endif
