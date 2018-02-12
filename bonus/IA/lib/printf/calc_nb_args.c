/*
** EPITECH PROJECT, 2017
** calc_nb_args
** File description:
** Made by Nathan GRIMAUD
*/

int calc_nb_args(char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] != '\0') {
		if (str[i] == '%')
			nb++;
		i++;
	}
	return (nb);
}
