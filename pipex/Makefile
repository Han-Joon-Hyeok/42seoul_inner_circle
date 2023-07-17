# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 09:52:36 by joonhan           #+#    #+#              #
#    Updated: 2022/10/13 10:46:18 by joonhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:=	pipex

SRCS 			:=	$(NAME).c						\
					pipex_utils.c					\
					fork.c

OBJS			:=	$(SRCS:%.c=%.o)

BONUS_DIR		:= ./bonus/
BONUS_SRCS		:=	pipex_bonus.c					\
					pipex_utils_bonus.c				\
					execute_here_doc_bonus.c		\
					execute_multiple_pipe_bonus.c	\
					child_process_bonus.c
BONUSES			:=	$(addprefix $(BONUS_DIR),$(BONUS_SRCS))
BONUS_OBJS		:=	$(BONUSES:%.c=%.o)

LIB_NAME		:=	ft
LIB_DIR			:=	./libft/
LIB				:=	$(LIB_DIR)lib$(LIB_NAME).a
LIB_FLAGS		:=	-L $(LIB_DIR) -l$(LIB_NAME)

CC 				:=	gcc
CFLAGS 			:=	-Wall -Wextra -Werror -g

ifdef WITH_BONUS
	OBJS		:=	$(BONUS_OBJS)
endif

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIB_DIR)

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re : fclean all

bonus :
	make WITH_BONUS=1 all

norm :
	@echo $(GREEN)📚 LIBFT NORMINETTE $(RESET) '\n'
	@norminette $(LIB_DIR)
	@echo '\n'$(GREEN)🔮 MANDATORY NORMINETTE $(RESET) '\n'
	@norminette $(SRCS) $(NAME).h
	@echo '\n'$(GREEN)🎁 BONUS NORMINETTE $(RESET) '\n'
	@norminette $(BONUS_DIR)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(LIB_FLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# COLOR
GREEN	:=	"\033[32m"
RESET	:=	"\033[0m"