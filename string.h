#ifndef __JSFUCK_STRING_H
#define __JSFUCK_STRING_H

#include "common.h"

jsfuck_str_t * jsfuck_str_new(const unsigned short padding);
void jsfuck_str_append(jsfuck_str_t * ptr, const char * new_str, const unsigned int length);
char * jsfuck_str_trim(jsfuck_str_t * ptr, size_t * s);

#endif
