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
	int letter;
	int number;

	my_printf("\nattack: ");
	//coord = get_next_line(0);
	//letter = coord[0];
	//number = coord[1];
	/*envoie coord (int, int)*/
	/*if (return == 0)
		hit(enemy_tab);
	else
		missed(enemy_tab);*/
}

void enemy_turn(char **tab)
{
	char *enemy_coord[3];

	my_printf("\nwaiting for enemy's attack...\n");
	/*recu coord (int, int)*/
	/*enemy_coord[0] = letter;
	enemy_coord[1] = number;*
	enemy_coord[2] = '\0';
	if (check_hit(enemy_coord) == 0)*/
		/*return 0(hit)
	else
		return 1(missed)
	hit(tab, enemy_coord);*/
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
