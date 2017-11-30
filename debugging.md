# Intro to debugging

Let's modify hello world and have a go at debugging it. Update hello_world.cpp to look like:

```c
#include <stdio.h>
#include <stdint.h>

int32_t main(){
  for (uint8_t i = 0; i < 5; i++) {
    printf("i is: %u\n", i); 
  }
  printf("Hello werld!\n");
}
```

Rebuild:

`$ make`

Start debugging:

`$ gdb hello_world` 

`gdb` stands for "**g**nu **d**e**b**ugger" and is part of the c compiler tools.

You'll see a whole bunch of output and a prompt that starts with `(gdb)`. Let's type in help at the prompt:

`(gdb) help` FYI you don't type the `(gdb)` bit, it's just the prompt. You'd only type `help`

Let's set a breakpoint at a specific line of a file: 

`(gdb) break hello_world.cpp:6`

Start the program:

`(gdb) start`

Your program should start and then break in the for loop.

Inspect a variable:

`(gdb) print i`

Now let's run until we hit our next breakpoint:

`(gdb) continue` or `(gdb) c` if you prefer brevity :) 

`(gdb) print i`

Quit when you're done:

`(gdb) quit`
