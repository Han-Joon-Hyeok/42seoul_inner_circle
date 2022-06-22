NAME := libft.a

SRCS := ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strlen.c

OBJS := $(SRCS:%.c=%.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
