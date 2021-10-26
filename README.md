# jsfuck.h
JSFuck obfuscator written in ANSI C. For more info/context, visit [www.jsfuck.com](http://www.jsfuck.com). Tested on MinGW (Windows) and GCC (Linux, Ubuntu).

### Build
To build this library, you can clone the repo, compile every C source to an object file, and turn the object files to a static library file or a dynamic library file.
> Windows users can simply just use the `build.bat` file to build the library.

### Example
```c
#include <stdlib.h>
#include <stdio.h>

#include "jsfuck.h"

int main() {
    char code[] = "hello";
    char * output = jsfuck(code, 5);
    
    printf("%s\n", output);
    free(output);
    
    return 0;
}
```
