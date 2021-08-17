#include "string.h"

jsfuck_str_t * jsfuck_str_new(void) {
    jsfuck_str_t * ptr = malloc(sizeof(jsfuck_str_t));
    ptr->data = malloc(JSFUCK_STR_SIZE);

    if (ptr->data == NULL)
        return NULL;

    ptr->size = 0;
    ptr->limit = JSFUCK_STR_SIZE;
    return ptr;
}

void jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, unsigned int length) {
    if (!length)
        length = strlen(new_str);
    
    ptr->size += length;
    while (ptr->limit <= ptr->size) {
        ptr->limit += JSFUCK_STR_SIZE;
        ptr->data = realloc(ptr->data, ptr->limit);
    }

    memcpy(ptr->data + ptr->size - length, new_str, length);
}

char * jsfuck_str_trim(jsfuck_str_t * ptr) {
    const size_t size = ptr->size;
    char * output = malloc(size);
    output[size] = 0;
    memcpy(output, ptr->data, size - 1); /* ignore last + */
    
    free(ptr->data);
    ptr->size = 0;
    ptr->limit = 0;

    free(ptr);
    
    return output;
}