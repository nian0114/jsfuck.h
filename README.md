# jsfuck.h
JSFuck obfuscator written in ANSI C. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com). Tested on MinGW (Windows) and GCC (Linux, Ubuntu).

### Build
To build this library and/or the transpiler, simply run the appropiate shell files.

### Library Usage
```c
#include <stdlib.h>
#include <stdio.h>

#include "jsfuck.h"

int main() {
    size_t output_size;

    char code[] = "hello";
    char * output = jsfuck(code, 5, &output_size);
    
    printf("length of output string: %d\n", output_size);
    printf("%s\n", output);
    free(output);
    
    return 0;
}
```
Pro Tip: You can use `NULL` for the third argument if determining output size is not necessary.

### Transpiler
This library also provides a transpiler that transpiles a js file to a jsfucked js file. Simply build it and play with it!<br><br>
![transpiler demo](https://vierofernando.is-inside.me/K3pCKi2V.gif)
