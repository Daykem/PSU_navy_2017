##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Devlopers
##

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c *.c
	ar rc $(NAME) *.o
	make clean

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
