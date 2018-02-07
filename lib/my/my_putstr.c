/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** Made by Daykem
*/

void	my_putchar(char);

int	my_putstr(char const *str)
{
	while (*str != '\0') {
		my_putchar(*str);
		str++;
	}
}
