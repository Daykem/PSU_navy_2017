/*
** EPITECH PROJECT, 2017
** game.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

char *glob;

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
	while (42) {
		my_printf("\nattack: ");
		coord = get_next_line(0);
		if (coord[0] >= 'A' && coord[0] <= 'H' &&
		coord[1] >= '1' && coord[1] <= '8')
			break;
		my_printf("wrong position\n");
	}
	si(enemy_tab, coord, pid);
	while (42) {
		signal(SIGUSR1, tata);
		signal(SIGUSR2, tata);
		if (global2(0, 1) != 0)
			break;
	}
	if (global2(0, 1) == 1) {
		enemy_hit(enemy_tab, coord, 0);
		global5(0);
	}
	else if (global2(0, 1) == 2)
		enemy_hit(enemy_tab, coord, 1);
	global2(0, 0);
}

void enemy_turn(char **tab, int pid)
{
	my_printf("\nwaiting for enemy's attack...\n");
	while (42) {
		signal(SIGUSR1, toto);
		signal(SIGUSR2, toto);
		if (global(0, 1) == 1)
			break;
	}
	global(0, 0);
	if (check_hit(tab, glob) == 0) {
		kill(pid, SIGUSR1);
	} else
		kill(pid, SIGUSR2);
	hit(tab, glob);
}

int game1(char *map, int enemy_pid)
{
	char **enemy_tab = create_tab(map);
	char **tab = create_tab(map);
	char *coord;

	affect_map(tab, map, 0);
	fill_map(tab, '3');
	while (42) {
		my_printf("\nmy positions:\n");
		print_tab(tab);
		my_printf("\nenemy's positions:\n");
		print_tab(enemy_tab);
		my_turn(enemy_tab, coord, enemy_pid);
		enemy_turn(tab, enemy_pid);
		if (global5(1) == 14) {
			my_printf("I won\n");
			return (0);
		} else if (global4(1) == 14) {
			my_printf("Enemy won\n");
			return (1);
		}
	}
}

int game2(char *map, int enemy_pid)
{
	char **enemy_tab = create_tab(map);
	char **tab = create_tab(map);
	char *coord;

	my_pid();
	my_printf("successfully connected\n");
	affect_map(tab, map, 0);
	fill_map(tab, '3');
	while (42) {
		my_printf("\nmy positions:\n");
		print_tab(tab);
		my_printf("\nenemy's positions:\n");
		print_tab(enemy_tab);
		enemy_turn(tab, enemy_pid);
		my_turn(enemy_tab, coord, enemy_pid);
		if (global5(1) == 14) {
			my_printf("I won\n");
			return (0);
		} else if (global4(1) == 14) {
			my_printf("Enemy won\n");
			return (1);
		}
	}
}
