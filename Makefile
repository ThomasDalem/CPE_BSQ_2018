##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	main.c			\
			find_biggest_square.c	\
			is_square_of_size.c	\
			load_2d_arr_from_file.c	\
			my_put_nbr.c		\
			my_putstr.c		\
			my_getnbr.c		\
			my_putchar.c

TESTSRC	=	find_biggest_square.c		\
			is_square_of_size.c	\
			load_2d_arr_from_file.c	\
			my_put_nbr.c		\
			my_putstr.c		\
			my_getnbr.c		\
			my_putchar.c

TESTS	=	tests/tests_bsq.c

OBJ		=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC) -g
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	gcc -o unit_tests $(TESTS) $(TESTSRC) --coverage -lcriterion
	./unit_tests
