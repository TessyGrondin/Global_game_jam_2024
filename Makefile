##
## EPITECH PROJECT, 2023
## loadmap
## File description:
## Makefile
##

SRC = 	main.cpp\
		src/Animation.cpp\
		src/LayerMap.cpp\
		src/Map.cpp\
		src/Quiz.cpp\
		src/Sprite.cpp\
		src/SpriteSheet.cpp\
		src/TextBox.cpp\
		src/NotHim.cpp
		src/Pingouin.cpp\
		src/PingouinGame.cpp\

NAME = les_blagues_de_tonton

OBJ = $(SRC:.cpp=.o)

FLAGS = -W -Wall -Wextra -Werror -lsfml-graphics -lsfml-window \
	 -I include/ -lsfml-system -lsfml-audio -g -ggdb -g3 -lm

all:
	g++ -o $(NAME) $(SRC) $(FLAGS)

fclean:
	rm -f $(NAME)

re: fclean all
