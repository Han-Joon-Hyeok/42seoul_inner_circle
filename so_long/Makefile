NAME := so_long

SRC_NAME := main.c
OBJ_NAME := $(SRC_NAME:.c=.o)
OBJ := $(OBJ_NAME)

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
	rm -f $(OBJ)

$(NAME) : $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -Lmlx -lmlx -framework OpenGL -framework AppKit -L$(LIB_DIR) -l$(LIB_NAME) -o $@ $^

$(LIB) :
	make -C $(LIB_DIR) all

# %.o : %.c
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
