##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Devlopers
##

SRC		=	src/main.c		\
			src/my_pid.c		\
			src/create_tab.c	\
			src/read_positions.c	\
			src/fill_tab.c		\
			src/game.c		\

SRC_HELP	=	src/help/my_help.c	\

SRC_SIG		=	src/sig/send_sig.c	\

SRC_UT		=	tests/test.c 		\

CFLAGS		+=	-Iinclude

LDFLAGS		=	-lcriterion -lgcov -L lib/my/ -lmy --coverage

NAME_UT		=	unit-tests

OBJ		=	$(SRC:.c=.o) $(SRC_HELP:.c=.o) $(SRC_SIG:.c=.o)

OBJ_UT		=	$(SRC_UT:.c=.o) $(SRC_HELP:.c=.o) $(SRC_SIG:.c=.o)

NAME		=	navy

all:		$(NAME)

tests_run:	$(OBJ_UT)
	make -C lib/my/
	cc -o $(NAME_UT) $(OBJ_UT) $(LDFLAGS)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno
	./unit-tests

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) -L lib/my -lmy $(CFLAGS)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f unit-tests
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno

re:	fclean all
