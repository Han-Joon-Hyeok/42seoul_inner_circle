NAME 						:=	phonebook

SRC_FILES				:=	main			\
										PhoneBook

SRCS						:=	$(addsuffix .cpp, $(SRC_FILES))

OBJ_DIR					:=	obj/
OBJS						:=	$(SRCS:%.c=$(OBJ_DIR)%.o)

CXX							:=	c++
CXXFLAGS 				:=	-Wall -Wextra -Werror -std=c++98 -pedantic

ifdef DEBUG_MODE
	CXXFLAGS				:=	$(CXXFLAGS) -g
endif

ifdef D_SANI
	CXXFLAGS				:=	$(CXXFLAGS) -g -fsanitize=address
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

$(OBJS): $(OBJ_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

