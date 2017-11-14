# Conways in C++ 

> Learn some C / C++ building conways game of life

## Learning objectives

- get comfortable with the two step process of compiling and running and the errors that can happen at each stage.
- define and call functions in c.
- intro to memory management and use the `malloc` function.
- understand the difference between passing values by copy of by reference. 

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

- The `bool * pointer_to_is_cool` bit is new. You should read the `*` as "pointer." So I read it like "Make a variable called `pointer_to_is_cool` that is a pointer to a bool."
- The `&is_cool` bit is new too. You should read is "get the address of `is_cool`"

So that translates to "Take the address of `is_cool` and store it in the variable `pointer_to_is_cool`."

Note that we can declare and initialise a pointer all in one line:

```
bool is_cool = true;
bool * pointer_to_is_cool = &is_cool;
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


## Setup

`mkdir build && cd build`
`cmake ..`

## Build

`cmake --build .`

