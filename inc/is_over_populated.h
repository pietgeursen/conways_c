#ifndef IS_OVER_POPULATED_H
#define IS_OVER_POPULATED_H

#include <stdint.h> //gives uint8_t etc
#include <stdbool.h> //gives bool

#ifdef __cplusplus
extern "C" {
#endif

  bool is_over_populated(uint8_t num_neighbours);

#ifdef __cplusplus
}
#endif

#endif
