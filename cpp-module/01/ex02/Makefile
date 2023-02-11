# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 09:19:10 by joonhan           #+#    #+#              #
#    Updated: 2023/02/10 16:04:37 by joonhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 						:=	zombie

SRC_FILES				:=	main				

SRCS						:=	$(addsuffix .cpp, $(SRC_FILES))

OBJ_DIR					:=	obj/
OBJS						:=	$(SRCS:%.cpp=$(OBJ_DIR)%.o)

CXX							:=	c++
CXXFLAGS 				:=	-Wall -Wextra -Werror -std=c++98

ifdef DEBUG_MODE
	CXXFLAGS			:=	$(CXXFLAGS) -g
endif

ifdef D_SANI
	CXXFLAGS			:=	$(CXXFLAGS) -g -fsanitize=address
endif

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	rm -rf $(OBJ_DIR)

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : re
re : fclean all

.PHONY : debug
debug : fclean
	make -j4 DEBUG_MODE=1 all

.PHONY : dsani
dsani : fclean
	make -j4 D_SANI=1 all

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): $(OBJ_DIR)%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

