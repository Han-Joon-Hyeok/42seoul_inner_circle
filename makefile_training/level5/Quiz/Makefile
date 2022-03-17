NAME := libft.a
SRCS := first.c second.c third.c
OBJS := $(patsubst %.c,%.o,$(SRCS))
AR := ar
ARFLAGS := rcs

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<
