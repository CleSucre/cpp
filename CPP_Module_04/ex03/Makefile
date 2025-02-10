NAME	= interface

BUILDER	= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -Iincludes

RM		= rm -f
RMDIR	= rm -rf

SRC_DIR = src
OBJ_DIR = objs
INC_DIR = includes

SRCS	= main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp Character.cpp Cure.cpp Ice.cpp

SRCS	:= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	$(BUILDER) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
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
