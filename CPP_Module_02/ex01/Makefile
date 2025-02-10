NAME	= canonic

BUILDER	= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f
RMDIR	= rm -rf

OBJ_DIR	= objs

SRCS	= main.cpp Fixed.cpp

OBJ		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	$(BUILDER) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(BUILDER) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
