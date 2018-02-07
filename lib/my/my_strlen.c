/*
** EPITECH PROJECT, 2017
** strlen
** File description:
** Made by Daykem
*/

int	my_strlen(char const *str)
{
	int i = 0;
	int nb = 0;

	while (str != 0 && str[i] != '\0') {
		i++;
		nb++;
	}
	return (nb);
}
