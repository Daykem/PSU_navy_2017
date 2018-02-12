/*
** EPITECH PROJECT, 2017
** find_type.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

#include <stdlib.h>

void find1(char *str, char *types, int i, int j)
{
	switch (str[i + 1]) {
		case 'd':
			types[j] = 'd';
			break;
		case 's':
			types[j] = 's';
			break;
		case 'c':
			types[j] = 'c';
			break;
		case 'b':
			types[j] = 'b';
			break;
	}
}
void find2(char *str, char *types, int i, int j)
{
	switch (str[i + 1]) {
		case 'S':
			types[j] = 'S';
			break;
		case 'x':
			types[j] = 'x';
			break;
		case 'X':
			types[j] = 'X';
			break;
		case 'o':
			types[j] = 'o';
			break;
	}
}

void find3(char *str, char *types, int i, int j)
{
	switch (str[i + 1]) {
		case 'u':
			types[j] = 'u';
			break;
		case '%':
			types[j] = '%';
			break;
		case 'i':
			types[j] = 'd';
			break;
		case 'p':
			types[j] = 'p';
			break;
	}
}

char *find_type(char *str, int nb_args)
{
	int i = 0;
	int j = 0;
	char *types = malloc(nb_args + 1);

	while (str[i] != '\0') {
		if (str[i] == '%') {
			find1(str, types, i, j);
			find2(str, types, i, j);
			find3(str, types, i, j);
			j++;
			i += 2;
		} else
			i++;
	}
	return (types);
}
