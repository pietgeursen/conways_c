# Conways in C 

> Learn some C by building conways game of life

## Learning objectives

- Pointers and pointer syntax
- Understand the difference between passing values by copy of by reference. 
- Build conways

## Target audience

- You already know how to program in another language.
- You've never written any c before
- Bonus if:
  - You've written conways game of life in your language of choice.
  - You're familiar with a test driven development. This exercise has tests that you will make pass. Being able to read the tests will help guide you.

## [Test your dev setup](setup.md)

## [Debug a program](debugging.md)

## [Intro to pointers](pointers.md)

## Conways

### Board data structure

The tests expect a conways board to be a single dimension array of bools like:

`bool board [BOARD_SIZE * BOARD_SIZE] = {false};`

You're going to have to work out the maths and syntax for treating this like a 2d array:
```c
  int8_t row = 1;
  int8_t col = 2;

  // one option if you want to use index syntax
  bool cell_at_location = board[???something with row, col and BOARD_SIZE??];

  // the option if you want to use pointer syntax
  bool cell_at_location = *(board + ???);
```

### Build files

Build set ups are painful and you don't need to delve into it now. But you will need to uncomment some lines of the main build file as you progress through the challenge.
This is so that you can be sure that any errors you see are actually coming from the code you're working on.

So, go open up the file `CMakeLists.txt` and go down until you find the lines that look something like this:

```cmake
# Uncomment each group below as you progress through the challenge

#add_library(is_over_populated is_over_populated.cpp)
#add_executable(is_over_populated_test is_over_populated_test.cpp)
#target_link_libraries(is_over_populated_test is_over_populated gtest_main)
```

and uncomment the first of the three lines like so:

```cmake
# Uncomment each group below as you progress through the challenge

add_library(is_over_populated is_over_populated.cpp)
add_executable(is_over_populated_test is_over_populated_test.cpp)
target_link_libraries(is_over_populated_test is_over_populated gtest_main)
```

### Dev cycle
  - Edit the build settings to build the next part of the challenge. 
  - Write code.
  - Try and build it with `$ make`
  - Run the test for the part you're working on, eg `$ ./is_over_populated_test`
  - Repeat!

### Testing

Run all the tests:

`$ make test` 

### Revel in the glory that is _The Game of Life_

`./conways`
