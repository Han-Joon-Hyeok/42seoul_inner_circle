NAME := libftprintf.a

SRCS := ft_printf_va_c.c \
		ft_printf_va_d.c \
		ft_printf_va_p.c \
		ft_printf_va_s.c \
		ft_printf_va_u.c \
		ft_printf_va_x.c \
		ft_printf.c

OBJS := $(SRCS:%.c=%.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror

INCLUDE := -I./libft

LIB_DIR := ./libft/
LIB_NAME := ft
LIB := $(LIB_DIR)lib$(LIB_NAME).a

all : $(NAME)

$(NAME) : $(LIB) $(OBJS)
	mv $(LIB) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIB) :
	make -C $(LIB_DIR) all

%.o : %.c
	$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re : fclean all

.PHONY : all clean fclean re

