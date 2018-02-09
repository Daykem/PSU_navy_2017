/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Made by Tom ROUVIER and Nathan GRIMAUD
*/

#include "navy.h"

int main(int ac, char **av)
{
	int enemy_pid = 0;
	int pid = 0;

	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			help();
			return (0);
		}
		my_pid();
		my_printf("waiting for enemy connection...\n");
		send_sig();
		pid = global3(0, 1);
		game1(read_my_pos(av[1]), pid);
		return (0);
	} else if (ac == 3) {
		enemy_pid = my_getnbr(av[1]);
		kill(enemy_pid, SIGUSR1);
		my_pid();
		my_printf("successfully connected\n");
		game2(read_my_pos(av[2]), enemy_pid);
		return (0);
	}
	return (84);
}
