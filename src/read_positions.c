/*
** EPITECH PROJECT, 2018
** read
** File description:
** made by dev
*/

#include "navy.h"

int check_getline(char *coord)
{
	if (coord == NULL) {
		my_printf("\nwrong position");
		return (1);
	} else if (coord[0] < 'A' || coord[0] > 'H' ||
	coord[1] < '1' || coord[1] > '8' || coord[2] != '\0') {
		my_printf("wrong position");
		return (1);
	}
	return (0);
}

int alpha(char c)
{
	if (c >= 'A' && c <= 'H')
		return (0);
	return (1);
}

int num(char c)
{
	if (c >= '1' && c <= '8')
		return (0);
	return (1);
}

int check_error(char *str)
{
	int fd = open(str, O_RDONLY);
	char* buffer;
	char c = '2';

	while ((buffer = get_next_line(fd)) != NULL) {
		if (buffer[0] != c || buffer[1] != ':' || alpha(buffer[2])
		== 1 || num(buffer[3]) == 1 || buffer[4] != ':'
		|| alpha(buffer[5]) == 1 || num(buffer[6]) == 1 ||
		(buffer[7] != '\n' && buffer[7] != '\0') || c > '5')
			return (1);
		else if (buffer[2] != buffer[5] && buffer[3] != buffer[6])
			return (1);
		c++;
	}
	return (0);
}

char *read_my_pos(char *str)
{
	int fd = open(str, O_RDONLY);
	char *map = malloc(sizeof(char) * 33);

	if (read(fd, map, 32) == -1)
		return (NULL);
	if (check_error(str) == 1)
		return (NULL);
	return (map);
}
