##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/main.c 				\
		src/error_handling.c 	\
		src/create_maze.c 		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./../lib -lfree

NAME	=	generator

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	CFLAGS += -g3
debug:	re

tests_run: SRC += tests/tests_generator.c
tests_run: SRC := $(filter-out src/main.c, $(SRC))
tests_run: NAME := unit_tests
tests_run:
	make -C ../lib/my/
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) -lcriterion --coverage -I./include
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re clean $(NAME) debug
