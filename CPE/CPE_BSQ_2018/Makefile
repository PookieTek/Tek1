##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		bsq.c		\
		misc.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

LIB	=	lib/my/libmy.a

CFLAGS	=	-Wall -Wextra -O2

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C lib/my clean
	$(RM) $(OBJ)

fclean:	clean
	make -C lib/my fclean
	$(RM) $(NAME)

re:	fclean all
