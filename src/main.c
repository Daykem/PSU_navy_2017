/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Made by Tom ROUVIER and Nathan GRIMAUD
*/

#include "navy.h"

int     binaire(unsigned int nbr)
{
	char *base = "01";
	int size_base = my_strlen(base);
	int res = 0;
	int div = 0;
	char *resu = malloc(sizeof(char) * 5);

	if (nbr < 0) {
		resu[nbr] = '-';                            
		nbr = -nbr;
	}
	div = 1;
	while ((nbr / div) >= size_base)
		div = div * size_base;
	while (div > 0) {
		res = (nbr / div) % size_base;
		resu[div] = base[res];
		div = div / size_base;
	}
	return (resu);
}

void catche(int signal)
{
	if (signal == SIGUSR1)
		printf("0\n");
	else if (signal == SIGUSR2)
		printf("1\n");
}

int main(int ac, char **av)
{
	int enemy_pid = 0;
	int i = 0;
	char *resu;

	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			help();
			return (0);
		}
		my_pid();
		my_printf("waiting for enemy connexion...\n");
		send_sig();
		while (1) {
			signal(SIGUSR1, catche);
			signal(SIGUSR2, catche);
		}
		game1(read_my_pos(av[1]));
		return (0);
	} else if (ac == 3) {
		enemy_pid = my_getnbr(av[1]);
		kill(enemy_pid, SIGUSR1);
		game2(read_my_pos(av[2]));
		i = atoi(get_next_line(0));
		//resu = binaire(i);
		//printf("%s\n", resu);
		//i = 0;
		//while (resu[i]) {
		if (i == 0)
			kill(enemy_pid, SIGUSR1);
		if (i == 1)
			kill(enemy_pid, SIGUSR2);
		//i++;
		//}
		return (0);
	}
	return (84);
}
