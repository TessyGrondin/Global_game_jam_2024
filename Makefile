##
## EPITECH PROJECT, 2023
## loadmap
## File description:
## Makefile
##

SRC = 	main.cpp\

NAME = make_me_laugh

OBJ = $(SRC:.c=.o)

FLAGS = -W -Wall -Wextra -Werror -lsfml-graphics -lsfml-window \
	 -I include/ -lsfml-system -lsfml-audio -g -ggdb -g3 -lm

all: $(OBJ)
	g++ -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
