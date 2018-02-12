/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
	int x = 1;

	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	while (nb / x >= 10) {
		x *= 10;
	}
	while (x > 0) {
		my_putchar(((nb / x) % 10) + 48);
		x /= 10;
	}
	return (0);
}
