/*
** EPITECH PROJECT, 2017
** my_getnbr_base.c
** File description:
** getnbr_base
*/

int my_strlen(char const *str);

int my_power(int nb, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	if (p > 0)
		return (nb * my_power(nb, p - 1));
}

int my_getnbr_base(char const *str, char const *base)
{
	int i = 0;
	int j = my_strlen(str) - 1;
	int nbr = 0;
	int m = 1;
	int len = my_strlen(base);

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			m = m * -1;
		i++;
	}
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'F')
			nbr += (str[i] - 55) * my_power(len, j);
		else
			nbr += (str[i] - 48) * my_power(len, j);
		i++;
		j--;
	}
	return (nbr * m);
}
