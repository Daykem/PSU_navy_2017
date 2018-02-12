/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

int my_strlen(char const *str);
void my_putchar(char c);
char *my_revstr(char *str);
int my_putstr(char const*);

void my_memset(char *str, int size)
{
	int i = 0;

	while (i <= size) {
		str[i] = '\0';
		i++;
	}
}

int my_putnbr_base(unsigned int nbr, char const *base)
{
	int b = my_strlen(base);
	int mod;
	char str[4096];
	int i = 0;

	my_memset(str, 4096);
	while (nbr > 0) {
		mod = nbr % b;
		str[i] = base[mod];
		nbr /= b;
		i++;
	}
	my_revstr(str);
	my_putstr(str);
	return (0);
}
