# jsfuck.h
JSFuck obfuscator written in ANSI C. For more info, go to [jsfuck.com](https://jsfuck.com).

### Example
```c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "jsfuck.h"

int main() {
    char code[] = "hello";
    char * output = jsfuck(code, strlen(code));
    
    printf("%s\n", output);
    free(output);
    
    return 0;
}
```