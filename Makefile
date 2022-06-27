##
## Maze_Solver
## File description:
## Makefile
##

INC_DIR = include/

CFLAGS  = -W -Wall -Wextra -g3 -I$(INC_DIR)

SRC =   $(wildcard src/*.c) \
		$(wildcard src/lib/*.c) \

OBJ = $(SRC:.c=.o)

NAME = maze_solver

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
