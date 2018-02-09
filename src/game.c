/*
** EPITECH PROJECT, 2017
** game.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"
char *glob;

int global2(int value, int mode)
{
	static int save = 0;
	if (mode == 0)
		save = value;
	return (save);
}

int global(int value, int mode)
{
	static int save = 0;
	if (mode == 0)
		save = value;
	return (save);
}

void find_coord(int i, int j)
{
	char letter = 'A';
	int k = -1;
	glob = malloc(sizeof(char) * 3);

	while (++k < i)
		letter++;
	glob[0] = letter;
	glob[1] = j + '0';
	glob[2] = '\0';
}

void tata(int sig)
{
	if (sig == SIGUSR2)
		global2(1, 0);
	else if (sig == SIGUSR1)
		global2(2, 0);
}

void toto(int sig)
{
	static int i = 0;
	static int j = 0;
	static int k = 0;

	if (sig == SIGUSR2)
		k++;
	if (k == 0)
		i++;
	else if (k == 1)
		j++;
	else {
		find_coord(i, j - 1);
		global(1, 0);
	}
}

void si(char **tab, char *coord, int pid)
{
	int i = 'A';
	int letter = 0;
	int number = my_getnbr(&coord[1]);

	while (i < coord[0]) {
		i++;
		letter++;
	}
	i = -1;
	while (++i < letter) {
		kill(pid, SIGUSR1);
		usleep(300);
	}
	kill(pid, SIGUSR2);
	i = -1;
	while (++i < number) {
		kill(pid, SIGUSR1);
		usleep(300);
	}
	kill(pid, SIGUSR2);
}

void my_turn(char **enemy_tab, char *coord, int pid)
{
	my_printf("\nattack: ");
	coord = get_next_line(0);
	si(enemy_tab, coord, pid);
	while (1) {
		signal(SIGUSR1, tata);
		signal(SIGUSR2, tata);
		if (global2(0, 1) == 0)
			break;
	}
	if (global2(0, 1) == 1)
		enemy_hit(enemy_tab, coord, 0);
	else if (global2(0, 1) == 2)
		enemy_hit(enemy_tab, coord, 0);
}

void enemy_turn(char **tab, int pid)
{
	my_printf("\nwaiting for enemy's attack...\n");
	while (1) {
		signal(SIGUSR1, toto);
		signal(SIGUSR2, toto);
		if (global(0, 1) == 1)
			break;
	}
	if (check_hit(tab, glob) == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	hit(tab, glob);
}

void game1(char *map, int enemy_pid)
{
	char **enemy_tab = create_tab(map);
	char **tab = create_tab(map);
	char *coord;

	affect_map(tab, map, 0);
	fill_map(tab, '3');
	while (42) {
		my_printf("my positions:\n");
		print_tab(tab);
		my_printf("\nenemy's positions:\n");
		print_tab(enemy_tab);
		enemy_turn(tab, enemy_pid);
		my_turn(enemy_tab, coord, enemy_pid);
	}
}

void game2(char *map, int enemy_pid)
{
	char **enemy_tab = create_tab(map);
	char **tab = create_tab(map);
	char *coord;

	affect_map(tab, map, 0);
	fill_map(tab, '3');
	while (42) {
		my_printf("my positions:\n");
		print_tab(tab);
		my_printf("\nenemy's positions:\n");
		print_tab(enemy_tab);
		my_turn(enemy_tab, coord, enemy_pid);
		enemy_turn(tab, enemy_pid);
	}
}
