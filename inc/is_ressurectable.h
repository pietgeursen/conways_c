#ifndef IS_RESSURECTABLE_H
#define IS_RESSURECTABLE_H

#include <stdint.h> //gives uint8_t etc
#include <stdbool.h> //gives bool

#ifdef __cplusplus
extern "C" {
#endif

  bool is_ressurectable(uint8_t num_neighbours);

#ifdef __cplusplus
}
#endif

#endif
