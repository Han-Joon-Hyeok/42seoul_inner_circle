NAME := main

SRC_NAME := main.c fourth.c
SRC_DIR := ./src/
SRC := $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_NAME := $(SRC_NAME:.c=.o)
OBJ_DIR := ./obj/
OBJ := $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIB_NAME := ft
LIB_DIR := ./lib/
LIB := $(LIB_DIR)lib$(LIB_NAME).a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCLUDE := -I ./include -I ./lib/

.PHONY : all clean fclean re run

all : $(NAME)

clean :
	rm -f $(OBJ)
	make -C $(LIB_DIR) $@

fclean :
	rm -f $(NAME)

re : fclean all

run : all
	./$(NAME)

$(NAME) : $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIB_DIR) -l $(LIB_NAME) -o $@ $^

$(LIB) :
	make -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
