/*
** EPITECH PROJECT, 2017
** check_hit.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

extern char *glob;

int global5(int mode)
{
	static int save = 0;

	if (mode == 0)
		save++;
	if (save == 14)
		my_printf("I won\n");
	return (save);
}

int global4(int mode)
{
	static int save = 0;

	if (mode == 0)
		save++;
	if (save == 14)
		my_printf("Enemy won\n");
	return (save);
}

int check_hit(char **tab, char *coord)
{
	int pos = 0;
	int letter = 'A';

	while (letter != coord[0]) {
		letter++;
		pos += 2;
	}
	if (tab[my_getnbr(&coord[1]) - 1][pos] >= '2' &&
	 tab[my_getnbr(&coord[1]) - 1][pos] <= '5')
		return (0);
	return (1);
}

void enemy_hit(char **tab, char*coord, int hit)
{
	int pos = 0;
	int letter = 'A';

	while (letter != coord[0]) {
		letter++;
		pos += 2;
	}
	if (hit == 0) {
		my_printf("%s: hit\n", coord);
		tab[my_getnbr(&coord[1]) - 1][pos] = 'x';
	} else {
		my_printf("%s: missed\n", coord);
		tab[my_getnbr(&coord[1]) - 1][pos] = 'o';
	}
	global2(0, 0);
}

void hit(char **tab, char *coord)
{
	int pos = 0;
	int letter = 'A';

	while (letter != coord[0]) {
		letter++;
		pos += 2;
	}
	if (tab[my_getnbr(&coord[1]) - 1][pos] >= '2' &&
	tab[my_getnbr(&coord[1]) - 1][pos] <= '5') {
		global4(0);
		my_printf("%s: hit\n", coord);
		tab[my_getnbr(&coord[1]) - 1][pos] = 'x';
	} else {
		my_printf("%s: missed\n", coord);
		tab[my_getnbr(&coord[1]) - 1][pos] = 'o';
	}
}
