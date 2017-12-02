#include "next_cell_state.h"

#include "is_over_populated.h"
#include "is_under_populated.h"
#include "is_ressurectable.h"

bool next_cell_state(bool current_cell_state, uint8_t neighbour_count){
  if(current_cell_state){
    return !is_over_populated(neighbour_count) && !is_under_populated(neighbour_count); 
  } else {
    return is_ressurectable(neighbour_count); 
  }
}
