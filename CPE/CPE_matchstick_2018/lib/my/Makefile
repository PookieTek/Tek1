##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_strcat.c			\
		my_strncmp.c			\
		my_strcmp.c			\
		my_strncpy.c			\
		my_strcpy.c			\
		my_putchar.c			\
		my_strdup.c			\
		my_put_nbr_base.c		\
		my_strupcase.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		is_alphanum.c			\
		my_getnbr.c			\
		my_alloc.c			\
		
OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

HEAD	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
