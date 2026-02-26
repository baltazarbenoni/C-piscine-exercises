CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I../../../include

LIB =	../../../src/str_utils.c \
		../../../src/io_utils.c	\
		../../../src/math_utils.c

SRCS = ft_cat.c ft_cat_display_file.c $(LIB)

OBJ = $(SRCS:.c=.o)

TARGET = ft_cat

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

all: $(TARGET)	clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(TARGET)

.PHONY: all clean fclean re