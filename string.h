#ifndef __JSFUCK_STRING_H
#define __JSFUCK_STRING_H

#define JSFUCK_STR_SIZE 0xFFF

#include <stdlib.h>
#include <string.h>
#include "common.h"

jsfuck_str_t * jsfuck_str_new(void);
void jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, unsigned int length);
char * jsfuck_str_trim(jsfuck_str_t * ptr);

#endif