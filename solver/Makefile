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

LDFLAGS	=	-L./lib -lmy

NAME	=	solver

NAME_TESTS	=	unit_tests

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	CFLAGS += -g3
debug:	re

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_TESTS)
	make fclean -C lib/my/

tests_run:
	make -C lib/my/
	$(CC) -o $(NAME_TESTS) $(CPPFLAGS) $(SRC_TESTS) $(LDFLAGS)
	./$(NAME_TESTS)

re: fclean all

.PHONY: all fclean re clean $(NAME) tests_run debug
