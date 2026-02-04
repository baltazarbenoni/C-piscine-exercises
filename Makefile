CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude

LIB_SRCS = \
	src/str_utils.c \
	src/math_utils.c \
	src/array_utils.c \
	src/memory_utils.c \
	src/io_utils.c

LESSONS = lesson00 lesson01 lesson02 lesson03 lesson04 lesson05 lesson06 lesson07 lesson08

#all: $(LESSONS)


#$(LESSONS):
#$(CC) $(CFLAGS) lessons/$@/$@.c $(LIB_SRCS) -o $@

test:
	$(CC) $(CFLAGS) tests/test_string_utils.c $(LIB_SRCS) -o test_string
	./test_string

clean:
	rm -f $(LESSONS) test_string

