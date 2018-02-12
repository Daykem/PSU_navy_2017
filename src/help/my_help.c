/*
** EPITECH PROJECT, 2018
** -h
** File description:
** Made by Nathan GRIMAUD & Tom ROUVIER
*/

#include "navy.h"

void help(void)
{
	my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n\n");
	my_printf("DESCRIPTION\n\tfirst_player_pid   only for the 2nd player.");
	my_printf("  pid of the first player.\n\t");
	my_printf("navy_positions     file representing the positions of");
	my_printf("the ships.\n");
}
