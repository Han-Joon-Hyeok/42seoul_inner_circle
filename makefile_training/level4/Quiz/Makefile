NAME := libft.a
OBJS := first.o second.o third.o
AR := ar
ARFLAGS := rcs

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<
