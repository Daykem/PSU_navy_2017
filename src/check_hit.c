/*
** EPITECH PROJECT, 2017
** check_hit.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

extern char *glob;

int gfunc5(int mode)
{
	static int save = 0;
	static int win = 0;

	if (mode == 0)
		save++;
	if (win == 1)
		my_printf("I won\n");
	if (save == 14)
		win++;
	return (save);
}

int gfunc4(int mode)
{
	static int save = 0;
	static int lose = 0;

	if (mode == 0)
		save++;
	if (lose == 1)
		my_printf("Enemy won\n");
	if (save == 14)
		lose++;
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
	gfunc2(0, 0);
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
		gfunc4(0);
		my_printf("%s: hit\n", coord);
		tab[my_getnbr(&coord[1]) - 1][pos] = 'x';
	} else {
		my_printf("%s: missed\n", coord);
		tab[my_getnbr(&coord[1]) - 1][pos] = 'o';
	}
}
