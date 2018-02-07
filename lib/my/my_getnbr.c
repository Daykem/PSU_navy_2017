/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** Made by daykem
*/

int	my_getnbr(char *str)
{
	int	i = 0;
	int	a = 0;
	int	nb = 0;

	while ((str[i] == ' ') || (str[i] == '\n'))
		i++;
	if (str[i] == 45)
		a = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57) {
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	if (a == 1)
		return (-nb);
	else
		return (nb);
}
