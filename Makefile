CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude

TEST_DIR  = tests
INDIVIDUAL_DIR = individuals

LIB_SRCS = \
	src/str_utils.c \
	src/math_utils.c \
	src/array_utils.c \
	src/memory_utils.c \
	src/io_utils.c

#LESSONS = lesson00 lesson01 lesson02 lesson03 lesson04 lesson05 lesson06 lesson07 lesson08

######################################

# Individual standalone functions
######################################

%: $(INDIVIDUAL_DIR)/%.c $(LIB_SRCS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@
######################################

# Tests
######################################
test_%: $(TEST_DIR)/test_%.c $(LIB_SRCS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

# Build all tests (but do not run them)
TESTS := $(patsubst $(TEST_DIR)/%.c,%,$(wildcard $(TEST_DIR)/test_*.c))
tests: $(TESTS)
######################################

# Cleanup
######################################
clean:
	rm -f test_[0-9][0-9]
	rm -f $(notdir $(basename $(wildcard $(INDIVIDUAL_DIR)/*.c)))