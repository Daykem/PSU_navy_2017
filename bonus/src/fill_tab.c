/*
** EPITECH PROJECT, 2017
** fill.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

void fill_ver(char **tab, int j, int i, char nb)
{
	j++;
	while (tab[j][i] != nb) {
		tab[j][i] = nb;
		j++;
	}
}

void fill_hor(char **tab, int j, int i, char nb)
{
	i++;
	while (tab[j][i] != nb) {
		if (i % 2 == 0)
			tab[j][i] = nb;
		i++;
	}
}
