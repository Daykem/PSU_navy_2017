/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Made by Tom ROUVIER and Nathan GRIMAUD
*/

#include "navy.h"

int main(int ac, char **av)
{
	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			help();
			return (0);
		}
		if (read_my_pos(av[1]) == NULL)
			return (84);
		send_sig();
		return (game1(read_my_pos(av[1]), gfunc3(0, 1)));
	} else if (ac == 3) {
		if (read_my_pos(av[2]) == NULL)
			return (84);
		kill(my_getnbr(av[1]), SIGUSR1);
		return (game2(read_my_pos(av[2]), my_getnbr(av[1])));
	}
	return (84);
}
