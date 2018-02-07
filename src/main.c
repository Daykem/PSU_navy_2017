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
	int ret = 0;

	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			help();
			return (0);
		}
		my_pid();
		my_printf("waiting for enemy connexion...\n");
		send_sig();
		game1(read_my_pos(av[1]));
		return (0);
	} else if (ac == 3) {
		enemy_pid = my_getnbr(av[1]);
		ret = kill(enemy_pid, SIGUSR1);
		printf("%d\n", ret);
		game2(read_my_pos(av[2]));
		return (0);
	}
	return (84);
}
