NAME 						:=	cub3D

INCLUDE						:=	-I./include/

SRC_DIR						:=	src/
SRC_MAIN					:=	main.c

SRC_INIT_DIR				:=	init/
SRC_INIT_FILES				:=	init.c

SRC_EXECUTE_DIR				:=	execute/
SRC_EXECUTE_FILES			:=	calc.c					\
								set_wall_dist.c			\
								draw.c

SRC_HOOKS_DIR				:=	hooks/
SRC_HOOKS_FILES				:=	hooks.c								\
								handle_player_move.c				\
								handle_camera_rotation.c

SRC_UTILS_DIR				:=	utils/
SRC_UTILS_FILES				:=	error.c								\
								free.c								\
								vector.c

SRC_PARSING_MAP_DIR			:=	parse_map/
SRC_PARSING_MAP_FILES		:=	check_map_validation.c						\
								is_valid_line.c						\
								is_one_player.c						\
								save_map.c							\
								check_wall.c						\
								parse_map_utils.c

SRC_PARSING_MAP_INFO_DIR	:=	parse_map_info/
SRC_PARSING_MAP_INFO_FILES	:=	check_map_info_validation.c				\
								map_info_utils.c					\
								process_line.c						\
								save_floor_ceiling_info.c

SRC_FILES					:=	$(SRC_MAIN)	\
								$(addprefix $(SRC_INIT_DIR), $(SRC_INIT_FILES))	\
								$(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS_FILES))	\
								$(addprefix $(SRC_PARSING_MAP_DIR), $(SRC_PARSING_MAP_FILES))	\
								$(addprefix $(SRC_PARSING_MAP_INFO_DIR), $(SRC_PARSING_MAP_INFO_FILES))	\
								$(addprefix $(SRC_HOOKS_DIR), $(SRC_HOOKS_FILES))	\
								$(addprefix $(SRC_EXECUTE_DIR), $(SRC_EXECUTE_FILES))

SRCS						:=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR						:=	obj/
OBJS						:=	$(SRCS:%.c=$(OBJ_DIR)%.o)

CFLAGS 						:=	-Wall -Wextra -Werror

LIB_NAME					:=	ft
LIB_DIR						:=	./libft/
LIB							:=	$(LIB_DIR)lib$(LIB_NAME).a
LIB_FLAGS					:=	-L $(LIB_DIR) -l$(LIB_NAME) -I$(LIB_DIR)

MLX_NAME			:=	mlx
MLX_DIR				:=	./mlx/
MLX					:=	$(MLX_DIR)lib$(MLX_NAME).a
MLX_FLAGS			:=	-lmlx -framework OpenGL -framework Appkit

ifdef DEBUG_MODE
	CFLAGS					:=	$(CFLAGS) -g
endif

ifdef D_SANI
	CFLAGS					:=	$(CFLAGS) -g -fsanitize=address
endif

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)

.PHONY : fclean
fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

.PHONY : re
re : fclean all

.PHONY : debug
debug : fclean
	make -j4 DEBUG_MODE=1 all

.PHONY : dsani
dsani : fclean
	make -j4 D_SANI=1 all

$(NAME) : $(OBJS)
	$(MAKE) -j4 -C $(LIB_DIR)
	$(MAKE) -j4 -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_FLAGS) $(MLX_FLAGS) -L $(MLX_DIR)

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)
# 	mkdir -p $(OBJ_DIR)$(SRC_UTILS_DIR)
# 	mkdir -p $(OBJ_DIR)$(SRC_PARSING_MAP_DIR)
# 	mkdir -p $(OBJ_DIR)$(SRC_PARSING_MAP_INFO_DIR)

# $(OBJ_DIR)%.o : $(SRCS) | $(OBJ_DIR)
$(OBJS): $(OBJ_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) -I$(LIB_DIR)

