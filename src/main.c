/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Made by Tom ROUVIER and Nathan GRIMAUD
*/

#include "navy.h"

static int received = 0;

char *binaire(unsigned int nbr)
{
	int i = 0;
	char *base = "01";
	int size_base = my_strlen(base);
	int res = 0;
	int div = 0;
	char *resu = "00000000";

	resu = malloc(sizeof(char) * 9);
	if (nbr < 0) {
		resu[i] = '-';                            
		nbr = -nbr;
		i++;
	}
	div = 1;
	while ((nbr / div) >= size_base)
		div = div * size_base;
	while (div > 0) {
		res = (nbr / div) % size_base;
		resu[i] = base[res];
		div = div / size_base;
		i++;
	}
	resu[i] = '\0';
	return (resu);
}

void catch(int signal, siginfo_t *info, void *str)
{
	if (signal == SIGUSR1) {
		my_printf("%c\n", '0');
		received++;
	}
	else if (signal == SIGUSR2) {
		my_printf("%c\n", '1');
		received++;
	}
}

int main(int ac, char **av)
{
	int enemy_pid = 0;
	int i = 0;
	char *resu;
	int j = 0;

	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			help();
			return (0);
		}
		my_pid();
		my_printf("waiting for enemy connexion...\n");
		send_sig();
		while (received != 7) {
			signal(SIGUSR1, catch);
			signal(SIGUSR2, catch);
		}
		game1(read_my_pos(av[1]));
		return (0);
	} else if (ac == 3) {
		enemy_pid = my_getnbr(av[1]);
		kill(enemy_pid, SIGUSR1);
		game2(read_my_pos(av[2]));
		i = my_getnbr(get_next_line(0));
		resu = binaire(i);
		i = 0;
		while (resu[i]) {
			if (resu[i] == '0')
				kill(enemy_pid, SIGUSR1);
			if (resu[i] == '1')
				kill(enemy_pid, SIGUSR2);
			usleep(300);
			i++;
		}
		return (0);
	}
	return (84);
}
