/*
** EPITECH PROJECT, 2017
** check_hit.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

int check_hit(char **tab, char *coord)
{
	int pos = 0;
	int letter = 'A';

	while (letter != coord[0]) {
		letter++;
		pos += 2;
	}
	if (tab[pos][my_getnbr(&coord[1]) - 1] >= '2' &&
	 tab[pos][my_getnbr(&coord[1]) - 1] <= '5')
		return (0);
	else
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
		tab[pos][my_getnbr(&coord[1]) - 1] = 'x';
	} else {
		my_printf("%s: missed\n", coord);
		tab[pos][my_getnbr(&coord[1]) - 1] = 'o';
	}
}
