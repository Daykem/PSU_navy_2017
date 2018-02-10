/*
** EPITECH PROJECT, 2017
** glob_f.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

#include "navy.h"

char *glob;

int gfunc2(int value, int mode)
{
	static int save = 0;
	if (mode == 0)
		save = value;
	return (save);
}

int gfunc(int value, int mode)
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
	if (sig == SIGUSR1)
		gfunc2(1, 0);
	else if (sig == SIGUSR2)
		gfunc2(2, 0);
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
		gfunc(1, 0);
		i = 0;
		j = 0;
		k = 0;
	}
}
