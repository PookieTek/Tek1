##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		game.c		\
		status.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

LIB	=	lib/my/libmy.a

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB) -lncurses

clean:
	make -C lib/my clean
	$(RM) $(OBJ)

fclean:	clean
	make -C lib/my fclean
	$(RM) $(NAME)

re:	fclean all
