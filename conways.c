#include <stdint.h>
#include <stdio.h>
#include <stdlib.h> //has rand funtion for random numbers
#include <time.h>

#include "calculate_next_board.h"


void randomly_seed_board(bool * board, uint16_t board_size){
  for (int16_t i = 0; i < board_size ; i++) {
    for (int16_t j = 0; j < board_size ; j++) {
      board[i + board_size * j] = rand() % 10  > 6;
    }
  }
}

void print_board(bool * board, uint16_t board_size){
  system("clear");
  for (int16_t i = 0; i < board_size ; i++) {
    for (int16_t j = 0; j < board_size ; j++) {
      bool cell = board[i + board_size * j];
      const char * character = cell ? "x" : "_";
      printf("%s", character);
    }
    printf("\n");
  }
}

int32_t main(){

  bool board_one[BOARD_SIZE * BOARD_SIZE] = {false};
  bool board_two[BOARD_SIZE * BOARD_SIZE] = {false};

  bool * current_board = board_one;
  bool * next_board = board_two;
  bool * old_current_board;

  randomly_seed_board(current_board, BOARD_SIZE);

  print_board(current_board, BOARD_SIZE);

	uint32_t start = clock(), diff;

  for (uint32_t i = 0; i < 1; i++) {
    calculate_next_board(current_board, next_board, BOARD_SIZE); 
    print_board(current_board, BOARD_SIZE);

    old_current_board = current_board;
    current_board = next_board;
    next_board = old_current_board;
  }
	diff = clock() - start;

	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken %d seconds %d milliseconds\n", msec/1000, msec%1000);
  return 0;
}
