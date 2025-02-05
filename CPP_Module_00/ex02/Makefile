NAME = phonebook

BUILDER = g++
FLAGS = -g -Wall -Wextra -Werror -std=c++98 -pedantic

RM = rm -f

SRCS =  tests.cpp Account.cpp
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(BUILDER) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(BUILDER) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
