NAME := so_long

SRCS := main.c \
		init.c \
		utils.c \
		maps.c \
		hooks.c

OBJS := $(SRCS:.c=.o)

MLX_NAME := mlx
MLX_DIR := ./mlx/
MLX := $(MLX_DIR)lib$(MLX_NAME).a

LIB_NAME := ft
LIB_DIR := ./libft/
LIB := $(LIB_DIR)lib$(LIB_NAME).a

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDE := -I ./mlx -I $(LIB_DIR)

.PHONY : all clean fclean re run bonus

all : $(NAME)

clean :
	rm -f $(OBJS)

$(NAME) : $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -Lmlx -lmlx -framework OpenGL -framework AppKit -L$(LIB_DIR) -l$(LIB_NAME) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all

