#include <string.h>
#include "string.h"

jsfuck_str_t * jsfuck_str_new(const unsigned short padding) {
    jsfuck_str_t * ptr = malloc(sizeof(jsfuck_str_t));
    ptr->data = malloc(padding);
    ptr->size = 0;
    ptr->limit = padding;
    ptr->padding = padding;
    return ptr;
}

void jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, const unsigned int length) {
    ptr->size += length;
    while (ptr->limit <= ptr->size) {
        ptr->limit += ptr->padding;
        ptr->data = realloc(ptr->data, ptr->limit);
    }

    memcpy(ptr->data + ptr->size - length, new_str, length);
}

char * jsfuck_str_trim(jsfuck_str_t * ptr) {
    char * output = realloc(ptr, ptr->size);
    output[ptr->size] = 0;
    
    free(ptr->data);
    free(ptr);
    
    return output;
}
