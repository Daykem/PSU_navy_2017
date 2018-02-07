/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** Made by Daykem
*/

int	my_strlen(char const *str);
void	my_putchar(char c);

int	my_putnbr_base(unsigned int nbr, char const *base)
{
	int size_base = my_strlen(base);
	int res = 0;
	int div = 0;

	if (nbr < 0) {
		my_putchar('-');
		nbr = -nbr;
	}
	div = 1;
	while ((nbr / div) >= size_base)
		div = div * size_base;
	while (div > 0) {
		res = (nbr / div) % size_base;
		my_putchar(base[res]);
		div = div / size_base;
	}
	return (0);
}
