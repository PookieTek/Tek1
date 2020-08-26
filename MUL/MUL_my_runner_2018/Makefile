##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		configure.c	\
		game_display.c	\
		misc.c		\
		player.c	\
		configure_two.c	\
		destroy_game.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

LIB	=	lib/my/libmy.a

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB) -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

clean:
	make -C lib/my clean
	$(RM) $(OBJ)

fclean:	clean
	make -C lib/my fclean
	$(RM) $(NAME)

re:	fclean all
