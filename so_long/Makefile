# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 14:35:24 by joonhan           #+#    #+#              #
#    Updated: 2022/09/02 16:47:21 by joonhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	so_long

SRC_DIR				:=	./src/
SRC_NAME			:=	main.c \
						init.c \
						utils.c \
						save_map.c \
						is_valid_map.c \
						get_map_info.c \
						draw_map.c \
						hooks.c
SRCS				:=	$(addprefix $(SRC_DIR),$(SRC_NAME))
OBJS				:=	$(SRCS:%.c=%.o)

BONUS_DIR			:= ./src_bonus/
BONUS_SRCS			:=	main_bonus.c \
						collect_bonus.c \
						init_bonus.c \
						init_map_bonus.c \
						utils_bonus.c \
						save_map_bonus.c \
						is_valid_map_bonus.c \
						get_map_info_bonus.c \
						draw_move_count_bonus.c \
						draw_map_bonus.c \
						enemy_bonus.c \
						hooks_bonus.c
BONUSES				:=	$(addprefix $(BONUS_DIR),$(BONUS_SRCS))
BONUS_OBJS			:=	$(BONUSES:%.c=%.o)

ifdef WITH_BONUS
	OBJS			:=	$(BONUS_OBJS)
	INCLUDE			:=	$(INC_BONUS_DIR)
else
	INCLUDE			:=	$(INC_DIR)
endif

INC_DIR				:=	./include/
INC_BONUS_DIR		:=	./include_bonus/

MLX_NAME			:=	mlx
MLX_DIR				:=	./mlx/
MLX					:=	$(MLX_DIR)lib$(MLX_NAME).a
MLX_FLAGS			:=	-lmlx -framework OpenGL -framework Appkit

LIB_NAME			:=	ft
LIB_DIR				:=	./libft/
LIB					:=	$(LIB_DIR)lib$(LIB_NAME).a
LIB_FLAGS			:=	-L $(LIB_DIR) -l$(LIB_NAME)

CC					:=	gcc
CFLAGS				:=	-Wall -Wextra -Werror -g

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(NAME)

re : fclean all

bonus :
	make WITH_BONUS=1 all

norm :
	@echo $(GREEN)🔮 MANDATORY NORMINETTE $(RESET) '\n'
	norminette $(SRCS) $(INC_DIR)$(NAME).h
	@echo '\n'$(GREEN)🎁 BONUS NORMINETTE $(RESET) '\n'
	norminette $(BONUSES) $(INC_BONUS_DIR)$(NAME)_bonus.h

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(MLX_FLAGS) -L $(MLX_DIR) $(LIB_FLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# COLOR
GREEN	:=	"\033[32m"
RESET	:=	"\033[0m"
CUT		:=	"\033[K"