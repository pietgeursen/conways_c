# Conways in C++ 

> Learn some C / C++ by building conways game of life

## Learning objectives

- understand the difference between passing values by copy of by reference. 
- intro to memory management and use the `malloc` function.
- get comfortable with the two step process of compiling and running and the errors that can happen at each stage.
- define and call functions in c.
- write code against tests written in the google-test framework.

## Pointers and pointer syntax.

Pointers tend to scare people off when they first meet them. Be brave, they're a useful tool for making fast code and solving a bunch of problems.

Pointer syntax:

If a bool stores a value that is true of false, then **a pointer to bool stores the location in memory of a bool**.

### Create a pointer variable and assign it a value

```
bool is_cool = true;
bool * pointer_to_is_cool; //declare a pointer to a bool, but don't point it to anything yet 
pointer_to_is_cool = &is_cool; //make it point to is_cool
```

There's some new syntax here. 

- The `bool * pointer_to_is_cool` bit is new. You should read the `*` as "pointer." So I read it like: "Make a variable called `pointer_to_is_cool` that is a pointer to a bool."
- The `&is_cool` bit is new too. You should read it `&` as "address". So I read it like: "get the address of `is_cool`"

So that translates to "Take the address of `is_cool` and store it in the variable `pointer_to_is_cool`."

Note that we can declare and initialise a pointer all in one line:

```
bool is_cool = true;
bool * pointer_to_is_cool = &is_cool; //this line was split in two in the previous example
```

### Get the value of what the pointer points to. Or "de-reference a pointer."

```
bool is_cool = true;
bool * pointer_to_is_cool = &is_cool;
bool might_be_cool = *pointer_to_is_cool;
```

You should read that last line as "get the value of whatever `pointer_to_is_cool` is pointing to and store a copy of it in `might_be_cool`"
Will `might_be_cool` be true of false? 

### Copies vs references

Copies:

```
bool is_cool = true;
bool is_also_cool = is_cool;
bool is_cool = false; 
```
`is_cool` is now false but `is_also_cool` is **still true**. This is because we made a copy of `is_cool` and stored it in `is_also_cool`
It might help to understand that `is_cool` is one spot in memory to store a bool, and `is_also_cool` is a totally different spot in memory.
Modifying one spot does not modify the other spot.


References:

```
bool is_cool = true;
bool *pointer_to_is_cool = &is_cool;

*pointer_to_is_cool = false; //where the magic is happening 

bool is_cool_copy = is_cool; //is_cool_copy will be **false**
```
I read `*pointer_to_is_cool = false;` as "de-reference `pointer_to_is_cool` and set it to false."

TLDR: When we take a copy, modifying the copy doesn't change the original. When we take a reference, we can modify the thing we have a reference to.


Functions pass arguments by copy

In js, when we pass an object to a function, it's passed by reference. We know this coz we often pass objects around and modify them as we go.
In contrast, **c functions always pass by copy**

Pass by copy

```
void add_one(uint8_t num){
  num += 1;
}

uint8_t my_age = 34;
add_one(my_age);

// my_age is still 34

```

Pass a reference
```
void add_one(uint8_t* pointer_to_num){
  *pointer_to_num += 1;
}

uint8_t my_age = 34;
add_one(&my_age);

// my_age is now 35
```

There are two reasons we might want to pass references to things. The first one we've seen: We want to be able to make a function that modifies the value of something.
The other reason is effiency. If we pass big complex objects around by copy, the computer has to spend a lot of time making copies of that big complicated object every time the function gets called.

To make that more concrete, we might want a function that can print out a conways board. We _could_ pass a board by copy, but that's just wasteful because a board could be massive, like 1000 * 1000 cells.

Or we might want a function that seeds a board with random alive and dead cells. We'd need to pass a reference to a board so that our function was able to modify the board's contents.

## Memory management using `malloc` and `free`

Until now, we've just been declaring and initialising variables inside functions. When we do this inside a function it uses _stack_ memory. But when that function ends, that memory is freed up for other functions. Sometimes we want to make a function that creates vars that stick around after the function ends.

To do this we use the `malloc` (short for memory allocation) function to reserve space on the _heap_. We tell `malloc` how much space we're gonna need when we call it and it gives us back a pointer to our memory.  

when we're done with the chunk of memory we need to `free` it so that we don't just use up all of the available memory as the program goes on. (If we forget to do this it's called a memory leak.)

We might want to make a function that can create a new conways board:

```
bool * create_board(uint16_t board_size){
  uint16_t bytes_needed = board_size * board_size * sizeof(bool); //calculate the number of bytes we need for a board.
  bool * board = (bool *) malloc(bytes_needed); // allocate the memory and cast the resulting address as a pointer to a bool.
  return board;
}
```

- If you haven't seen casting ( the `(bool *)` bit) before, have a google. 
- Go find the docs for malloc. What does it do if there isn't enough memory to allocate and it fails? This function could be improved to make it safer.


## Setup

`$ mkdir build && cd build`
`$ cmake ..`

## Build

`$ make`

## Run

`$ ./myTest`

