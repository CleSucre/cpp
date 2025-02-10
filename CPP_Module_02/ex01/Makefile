NAME	= canonic
BUILDER	= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

SRCS	= main.cpp Fixed.cpp
OBJ		= $(SRC:.cpp=.o)

all:
	${BUILDER} ${SRCS} ${FLAGS} -o ${NAME}

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re