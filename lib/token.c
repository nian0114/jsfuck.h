#include <string.h>
#include "token.h"

jsfuck_tokenizer_t * token_init(jsfuck_str_t * output, const jsfuck_input_t * inp) {
    jsfuck_tokenizer_t * tokenizer = malloc(sizeof(jsfuck_tokenizer_t));
    tokenizer->str = output;
    tokenizer->input = inp;
    tokenizer->index = 0;
    tokenizer->truncated = NULL;

    return tokenizer;
}

static unsigned char token_parse(
    jsfuck_tokenizer_t * ptr, const char * keyword, const unsigned char keyword_len) {

    if ((ptr->input->length - ptr->index) < keyword_len)
        return 0;
    
    ptr->truncated = malloc(keyword_len);
    memcpy(ptr->truncated, ptr->input->input + ptr->index, keyword_len);
    
    size_t i = 0; /* had to do this because ANSI C */
    for (; i < keyword_len; i++) {
        if (ptr->truncated[i] != keyword[i]) {
            free(ptr->truncated);
            return 0;
        }
    }
    
    free(ptr->truncated);
    ptr->index += keyword_len;
    
    return 1;
}

/* yanderedev!!1 */
void token_start(jsfuck_tokenizer_t * tokenizer) {
    do {
        if (token_parse(tokenizer, "NaN", 3))
            jsfuck_str_append(tokenizer->str, JSFUCK_NAN, JSFUCK_NAN_LEN);
        
        else if (token_parse(tokenizer, "true", 4))
            jsfuck_str_append(tokenizer->str, JSFUCK_TRUE, JSFUCK_TRUE_LEN);
        
        else if (token_parse(tokenizer, "false", 5))
            jsfuck_str_append(tokenizer->str, JSFUCK_FALSE, JSFUCK_FALSE_LEN);
        
        else if (token_parse(tokenizer, "Infinity", 8))
            jsfuck_str_append(tokenizer->str, JSFUCK_INFINITY, JSFUCK_INFINITY_LEN);
        
        else if (token_parse(tokenizer, "undefined", 9))
            jsfuck_str_append(tokenizer->str, JSFUCK_UNDEFINED, JSFUCK_UNDEFINED_LEN);
        
        else {
            jsfuck_get(tokenizer->input->input[tokenizer->index], tokenizer->str);
            tokenizer->index++;
        }
    } while (tokenizer->index < tokenizer->input->length);
    
    free(tokenizer);
}