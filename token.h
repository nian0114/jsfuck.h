#ifndef __JSFUCK_SIMPLE_H
#define __JSFUCK_SIMPLE_H

#include "common.h"
#include <string.h>

extern void jsfuck_str_append(jsfuck_str_t * ptr, char * new_str, unsigned int length);
extern void jsfuck_get(const char c, jsfuck_str_t * s);

jsfuck_tokenizer_t * token_init(jsfuck_str_t * output, const jsfuck_input_t * inp);
void token_start(jsfuck_tokenizer_t * tokenizer);

#endif