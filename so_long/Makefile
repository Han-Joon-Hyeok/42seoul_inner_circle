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
MLX_FLAGS := -lmlx -framework OpenGL -framework Appkit

LIB_NAME := ft
LIB_DIR := ./libft/
LIB := $(LIB_DIR)lib$(LIB_NAME).a
LIB_FLAGS := -L $(LIB_DIR) -l$(LIB_NAME)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rcus

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(NAME)

re : fclean all

norm :
	norminette $(SRCS) $(NAME).h

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -L $(MLX_DIR) $(LIB_FLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
