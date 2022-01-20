LIB_SRC_FILES := $(wildcard src/*.c)
LIB_OBJ_FILES := $(patsubst src/%.c,src/%.o,$(LIB_SRC_FILES))

JSFUCK_PADDING := 0xfff

libjsfuck.a: $(LIB_OBJ_FILES)
	ar rcs -o libjsfuck.a $^

src/%.o: src/%.c
	gcc -O3 -Wall -ansi -I include -D JSFUCK_PADDING=$(JSFUCK_PADDING) -c $< -o $@