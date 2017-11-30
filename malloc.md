## Memory management using `malloc` and `free`

Until now, we've just been declaring and initialising variables inside functions. When we do this inside a function it uses _stack_ memory. But when that function ends, that memory is freed up for other functions. Sometimes we want to make a function that creates vars that stick around after the function ends.

To do this we use the `malloc` (short for memory allocation) function to reserve space on the _heap_. We pass `malloc` how much space we're gonna need and it gives us back a pointer to our memory.  

when we're done with the chunk of memory we need to `free` it so that we don't use up all of the available memory as the program goes on. (If we forget to do this it's called a memory leak.)

We might want to make a function that can create a new conways board:

```
bool * create_board(uint16_t board_size){
  uint16_t bytes_needed = board_size * board_size * sizeof(bool); //calculate the number of bytes we need for a board.
  bool * board = (bool *) malloc(bytes_needed); // allocate the memory and cast the resulting address as a pointer to a bool.
  return board;
}
```

- If you haven't seen casting ( the `(bool *)` bit) before, have a google. 
- Same for `sizeof`
- Go find the docs for malloc. What does it do if there isn't enough memory to allocate and it fails? How would you improve this function to make it safer.
- The return type of the function should actually be `bool **` to make things easier but we can delve into that later.
