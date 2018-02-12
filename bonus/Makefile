##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Devlopers
##

SRC		=	src/main.c		\

SRC_FILE	=	src/my_pid.c		\
			src/create_tab.c	\
			src/read_positions.c	\
			src/fill_tab.c		\
			src/game.c		\
			src/check_hit.c		\
			src/glob_f.c		\

SRC_HELP	=	src/help/my_help.c	\

SRC_SIG		=	src/sig/send_sig.c	\

SRC_LIB		=	lib/get_next_line.c	\
			lib/my_getnbr.c		\

SRC_UT		=	tests/tests.c 		\

CFLAGS		+=	-Iinclude

LDFLAGS		=	-lcriterion -lgcov -L lib/printf/ -lprintf --coverage

NAME_UT		=	unit-tests

OBJ		=	$(SRC:.c=.o) $(SRC_FILE:.c=.o) $(SRC_HELP:.c=.o) \
			$(SRC_SIG:.c=.o) $(SRC_LIB:.c=.o)

OBJ_UT		=	$(SRC_UT) $(SRC_FILE) $(SRC_HELP) \
			$(SRC_SIG) $(SRC_LIB)

NAME		=	navy

all:		$(NAME)

tests_run:
	make -C lib/printf/
	cc -o $(NAME_UT) $(OBJ_UT) $(LDFLAGS) $(CFLAGS)
	./unit-tests

$(NAME):	$(OBJ)
	make -C lib/printf
	gcc $(OBJ) -o $(NAME) -L lib/printf -lprintf $(CFLAGS)

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
