##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	my_free_arr.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libfree.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../$(Name)
	cp my.h ../../solver/include/
	cp my.h ../../generator/include/

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all clean fclean $(NAME) re
