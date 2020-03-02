##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./../lib -lfree

NAME	=	solver

NAME_TESTS	=	unit_tests

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	CFLAGS += -g3
debug:	re

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_TESTS)

re: fclean all

.PHONY: all fclean re clean $(NAME) debug
