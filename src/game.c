/*
** EPITECH PROJECT, 2017
** game.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

void hit(char **tab, char *coord)
{
	int pos = 0;
	int letter = 'A';

	while (letter != coord[0]) {
		letter++;
		pos += 2;
	}
	if (tab[pos][my_getnbr(&coord[1]) - 1] >= '2' &&
	 tab[pos][my_getnbr(&coord[1]) - 1] <= '5') {
		my_printf("%s: hit\n", coord);
		tab[pos][my_getnbr(&coord[1]) - 1] = 'x';
	} else {
		my_printf("%s: missed\n", coord);
		tab[pos][my_getnbr(&coord[1]) - 1] = 'o';
	}
}

void my_turn(char **enemy_tab, char *coord)
{
	int coord_int = 0;

	my_printf("\nattack: ");
	coord_int = my_getnbr(coord = get_next_line(0));
	if (coord_int != NULL)
		printf("%d", coord_int);
	sleep(100);
	/*envoie coord : missed or hit (+check erreur)*/
	/*hit(enemy_tab, coord);*/
}

void enemy_turn(char **tab)
{
	my_printf("\nwaiting for enemy's attack...\n");
	/*recoie coord : missed or hit*/
	/*hit(tab, enemy_coord);*/
}
void game1(char *map)
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
		my_turn(enemy_tab, coord);
		enemy_turn(tab);
		return;
	}
}

void game2(char *map)
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
		enemy_turn(tab);
		my_turn(enemy_tab, coord);
		return;
	}
}
