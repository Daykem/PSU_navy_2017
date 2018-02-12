/*
** EPITECH PROJECT, 2017
** my_showstr.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

int my_putnbr_base(int nbr, char const *base);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);

void fill_zero(char const *str, int i)
{
	if (str[i] <= 7) {
		my_putchar('0');
		my_putchar('0');
	} else if (str[i] <= 31) {
		my_putchar('0');
	}
}

int my_showstr(char const *str)
{
	int i = 0;
	char const base[] = "01234567";
	int len = my_strlen(str);

	while (i <= len) {
		if ((str[i] <= 31 || str[i] >= 127) && str[i] != 0) {
			my_putchar('\\');
			fill_zero(str, i);
			my_putnbr_base(str[i], base);
		} else
			my_putchar(str[i]);
		i++;
	}
	return (0);
}
