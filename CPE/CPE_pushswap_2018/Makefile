##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		tool.c		\
		sort_function_one.c	\
		sort_function_two.c	\
		sort_function_three.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

LIB	=	lib/my/libmy.a

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
