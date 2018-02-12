/*
** EPITECH PROJECT, 2018
** read
** File description:
** made by dev
*/

#include "navy.h"

char *read_my_pos(char *str)
{
	int fd = open(str, O_RDONLY);
	char *map = malloc(sizeof(char) * 33);

	read(fd, map, 32);
	return map;
}
