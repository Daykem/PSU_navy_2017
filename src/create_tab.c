/*
** EPITECH PROJECT, 2017
** create_tab.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

void print_tab(char **tab)
{
	int i = -1;

	my_printf(" |A B C D E F G H\n-+---------------\n");
	while (tab[++i])
		my_printf("%d|%s\n", i + 1, tab[i]);
}


void affect_map(char **tab, char *map, int i)
{
	int letter = 'A';
	int pos = 0;
	int j;
	char number;

	while (map[i] < 'A' || map[i] > 'H')
		i++;
	j = i;
	while (map && map[j] != '\n' && map[j] != '\0')
		j--;
	number = map[j + 1];
	while (letter != map[i]) {
		letter++;
		pos += 2;
	}
	i++;
	tab[my_getnbr(&map[i]) - 1][pos] = number;
	if (map[i + 1] == '\0' || map[i + 2] == '\0')
		return;
	affect_map(tab, map, i);
}

void check_dir(char **tab, int i, int j, char nb)
{
	int savei = i;
	int savej = j;

	i++;
	while (tab[j][i] != '\0') {
		if (tab[j][i] == nb) {
			fill_hor(tab, savej, savei, nb);
			return;
		}
		i++;
	}
	j++;
	while(tab[j] != NULL) {
		if (tab[j][savei] == nb) {
			fill_ver(tab, savej, savei, nb);
			return;
		}
		j++;
	}
}

void fill_map(char **tab, char nb)
{
	int i = -1;
	int j = -1;

	while (nb < '6') {
		j = -1;
		while (tab[++j]) {
			i = -1;
			while (tab[j][++i]) {
				if (tab[j][i] == nb) {
					check_dir(tab, i, j, nb);
				}
			}
		}
		nb++;
	}
}

char **create_tab(char *map)
{
	int i = -1;
	int j = -1;
	char **tab = malloc(sizeof(char*) * 9);

	while (++j < 8) {
		i = -1;
		tab[j] = malloc(sizeof(char) * 16);
		while (++i < 15) {
			if (i % 2 == 0)
				tab[j][i] = '.';
			else
				tab[j][i] = ' ';
		}
		tab[j][i] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}
