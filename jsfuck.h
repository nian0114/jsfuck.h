#ifndef __JSFUCK_H
#define __JSFUCK_H

#include <stdlib.h>

#ifdef __JSFUCK_C

#include <string.h>
#include "common.h"

extern jsfuck_str_t * jsfuck_str_new(const unsigned short padding);
extern void jsfuck_str_append(jsfuck_str_t * ptr, char * new_str, unsigned int length);
extern char * jsfuck_str_trim(jsfuck_str_t * ptr);

extern void token_start(jsfuck_tokenizer_t * tokenizer);
extern jsfuck_tokenizer_t * token_init(jsfuck_str_t * output, const jsfuck_input_t * inp);

#undef __JSFUCK_C

#endif

char * jsfuck(const char * code, const size_t length);

#endif