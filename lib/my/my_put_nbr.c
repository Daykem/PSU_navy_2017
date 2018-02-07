/*
** EPITECH PROJECT, 2017
** put_nbr
** File description:
** Made by Daykem
*/

void	my_putchar(char c);

int	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar(45);
		nb = nb * -1;
	}
	if (nb <= 9) {
		nb = nb + 48;
		my_putchar(nb);
	} else {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	}
}
