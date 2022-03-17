NAME := main

SRC := main.c
OBJ := $(SRC:.c=.o)

LIBFT := libft.a
LIB_SRCS := first.c second.c third.c
LIB_OBJS := $(LIB_SRCS:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rcs

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f *.o

fclean :
	rm -f $(LIBFT) $(NAME)

re : fclean all

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) : $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : &.c
	$(CC) $(CFLAGS) -c $<
