CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_strcmp.c \
	srcs/ft_strlen.c \
	srcs/ft_swap.c

OBJECTS = $(SRCS:.c=.o)
TARGET = libft.a

all: $(TARGET)	clean

$(TARGET): $(OBJECTS)
	ar rcs $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(TARGET)

re:	fclean all 
