#include <stdlib.h>
#include <jsfuck.h>
#include <stdio.h>
#include "io.h"

#define JSFUCK_HEADER "[][(![]+[])[+[]]+(![]+[])[!+[]+!+[]]+(![]+[])[+!+[]]+(!![]+[])[+[]]][([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+([][[]]+[])[+!+[]]+(![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[+!+[]]+([][[]]+[])[+[]]+([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+(!![]+[])[+!+[]]]("
#define JSFUCK_FOOTER ")()"

int main(int argc, char ** argv) {
    if (argc != 2) {
        puts("error: please add a valid js file to transpile to.");
        return 1;
    }
    
    printf("reading %s...", argv[1]);
    
    file_contents_t f = read_file(argv[1]);
    if (f == NULL) {
        puts("\nerror: file does not exist.");
        return 1;
    }
    
    printf(" read %d bytes.\ntranspiling...", f->file_size);

    uint64_t transpiled_size;
    char * transpiled = jsfuck(f->contents, f->file_size, &transpiled_size);
    
    printf(" done.\n");
    
    char o_fn[255];
    strcpy(o_fn, "jsfucked-", 9);
    o_fn[strcpy(o_fn + 9, argv[1], input_fn_l)] = 0;
    
    FILE * of = fopen(o_fn, "w");
    
    fputs(JSFUCK_HEADER, of);
    fputs(transpiled, of);
    fputs(JSFUCK_FOOTER, of);
    
    printf("wrote %d bytes to %s.\n", 776 + transpiled_size, o_fn);
    
    free_file(f);
    free(transpiled);
    fclose(of);
    
    return 0;
}