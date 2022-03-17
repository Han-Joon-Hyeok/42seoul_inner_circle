NAME := libft.a
SRCS := first.c second.c third.c
OBJS := $(SRCS:.c=.o)
AR := ar
ARFLAGS := rcs
FCLEAN := fclean
ALL := all

.PHONY : all clean fclean re

all : $(NAME)

clean : $(OBJS)
	rm *.o

fclean :
	rm $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $<
	
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
