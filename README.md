# Conways in C++ 

> Learn some C / C++ by building conways game of life

## Learning objectives

- Pointers and pointer syntax
- Understand the difference between passing values by copy of by reference. 
- Build conways

## Pointers

[Read the pointers stuff](./pointers.md)

## Conways


## Setup

`$ mkdir build && cd build`
`$ cmake ..`

## Build

`$ make`

## Test

Run one specific test

`$ ./is_over_populated_test` (or whatever the test file is you want to run)

Run all the tests:

`$ make test` 

## Debug

`$ gdb is_over_populated_test` <function_name_>test files are the executable programs

`gdb` stands for "gnu de bugger" and is part of the compiler tools.

You'll see a whole bunch of output and a prompt that starts with `(gdb)`. Let's type in help at the prompt:

`(gdb) help`

Let's set a breakpoint at the function we're testing. If we were testing `is_over_populated` we'd say:

`(gdb) break is_over_populated`

Now let's run until we hit our breakpoint:

`(gdb) continue` or `(gdb) c` if you prefer brevity :) 

And inspect a variable:

`(gdb) print num_neighbours`

Quit when you're done:

`(gdb) quit`
