CC = gcc
NAME = ./bin/shady
SRC = ./src/main.c ./src/network.c ./src/words.c
FLAGS = -W -Werror
OBJ = $(SRC:%.c=%.o)
RM = rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) $(FLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all
