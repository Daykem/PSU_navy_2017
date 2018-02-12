/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
	int i = 0;
	int j = (my_strlen(str) - 1);
	char c;

	while (i != my_strlen(str) / 2) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}
