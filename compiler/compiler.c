#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jsfuck.h>
#include "io.h"

#define JSFUCK_HEADER "[][(![]+[])[+[]]+(![]+[])[!+[]+!+[]]+(![]+[])[+!+[]]+(!![]+[])[+[]]][([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+([][[]]+[])[+!+[]]+(![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[+!+[]]+([][[]]+[])[+[]]+([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+(!![]+[])[+!+[]]]("
#define JSFUCK_FOOTER ")()"

int main(int argc, char ** argv) {
    if (argc != 2) {
        puts("error: please add a valid js file to compile.");
        return 1;
    }
    
    printf("reading %s...", argv[1]);
    
    file_contents_t f = read_file(argv[1]);
    if (f == NULL) {
        puts("\nerror: file does not exist.");
        return 1;
    }
    
    printf(" read %d bytes.\ncompiling...", f->file_size);

    size_t compiled_size;
    char * compiled = jsfuck(f->contents, f->file_size, &compiled_size);
    
    printf(" done.\n");
    
    const size_t input_fn_l = strlen(argv[1]);
    char * o_fn = malloc(input_fn_l + 10);
    o_fn[input_fn_l + 9] = 0;
    memcpy(o_fn, "jsfucked-", 9);
    memcpy(o_fn + 9, argv[1], input_fn_l);
    
    FILE * of = fopen(o_fn, "w");
    
    fputs(JSFUCK_HEADER, of);
    fputs(compiled, of);
    fputs(JSFUCK_FOOTER, of);
    
    printf("wrote %d bytes to %s.\n", 776 + compiled_size, o_fn);
    
    free_file(f);
    free(compiled);
    free(o_fn);
    fclose(of);
    
    return 0;
}