##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

all:
	make -C lib/my/
	make -C generator/
	make -C solver/

clean:
	make clean -C lib/my/
	make clean -C generator/
	make clean -C solver/


fclean:	clean
	make fclean -C lib/my/
	make fclean -C generator/
	make fclean -C solver/

debug:
	make debug -C generator/
	make debug -C solver/

tests_run:
	make -C lib/my/
	make tests_run -C generator/

re: fclean all

.PHONY: all fclean re clean debug tests_run
