CC = gcc
NAME = ./bin/shady
SRC = ./src/main.c ./src/network.c
FLAGS = -W -Werror -lcurl
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
